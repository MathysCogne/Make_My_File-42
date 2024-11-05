#include "make_my_file.h"

#define INSTALL_SCRIPT_PATH "$HOME/.local/bin/install.sh"

typedef struct
{
	char	*memory;
	size_t	size;
} MemoryStruct;

// Callback function to store the response in a string
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t total_size = size * nmemb;
	MemoryStruct *mem = (MemoryStruct *)userp;

	char *ptr = realloc(mem->memory, mem->size + total_size + 1);
	if (ptr == NULL)
		return 0;

	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, total_size);
	mem->size += total_size;
	mem->memory[mem->size] = 0;

	return total_size;
}

// Pull the latest version from the GitHub API
char *get_latest_release()
{
	CURL *curl;
	CURLcode res;
	MemoryStruct chunk = { .memory = malloc(1), .size = 0 };
	char *latest_version = malloc(10);

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com/repos/" REPO_OWNER "/" REPO_NAME "/releases/latest");
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

		res = curl_easy_perform(curl);
		if (res == CURLE_OK)
		{
			char *tag_start = strstr(chunk.memory, "\"tag_name\":\"");
			if (tag_start)
			{
				tag_start += strlen("\"tag_name\":\"");
				char *tag_end = strchr(tag_start, '\"');
				if (tag_end)
				{
					size_t tag_length = tag_end - tag_start;
					strncpy(latest_version, tag_start, tag_length);
					latest_version[tag_length] = '\0';
				}
			}
			else
				strcpy(latest_version, CURRENT_VERSION);
		}
		else
		{
			fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
			strcpy(latest_version, CURRENT_VERSION);
		}
		curl_easy_cleanup(curl);
		free(chunk.memory);
	}
	return latest_version;
}

void check_for_updates()
{
	char *latest_version = get_latest_release();

	if (strcmp(CURRENT_VERSION, latest_version) != 0)
	{
		printf("🚀 New version [%s] available! You are currently using version [%s]\n", latest_version, CURRENT_VERSION);
		printf("Do you want to update now? (Y/N): ");

		char response;
		scanf(" %c", &response);
		if (response == 'y' || response == 'Y')
		{
			// No need for sudo since it's installed in a user directory
			system(INSTALL_SCRIPT_PATH);
		}
	}
	free(latest_version);
}