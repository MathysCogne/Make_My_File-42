/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#include "make_my_file.h"

/* Detect files with a specific extension in the given directory */
static void	detect_files(const char *base_dir, const char *current_dir, const char *ext, char **result)
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir(current_dir);
	if (!dir)
	{
		printf("Error auto-detecting.\nCould not open directory: %s\n", current_dir);
		return;
	}


	while ((entry = readdir(dir)) != NULL)
	{
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
		{
			char path[MAX_FILES];
			snprintf(path, sizeof(path), "%s/%s", current_dir, entry->d_name);
			// Check if a directory
			struct stat statbuf;
			if (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode))
				detect_files(base_dir, path, ext, result);
			else if (strstr(entry->d_name, ext)) // Check the extension
			{
				// Add the file to the list
				char *relative_path = path + strlen(base_dir) + 1;
				if (strlen(*result) + strlen(relative_path) + 2 > MAX_FILES)
				{
					// Realloc if exceeding max files
					char *tmp = realloc(*result, strlen(*result) + strlen(relative_path) + 2);
					if (!tmp)
					{
						free(*result);
						*result = NULL;
						closedir(dir);
						return;
					}
					*result = tmp;
				}
				strcat(*result, relative_path);
				strcat(*result, " ");
				printf(C_RESET ITALIC "Detected file: %s" C_RESET "\n", relative_path);
			}
		}
	}
	closedir(dir);
}

char	*auto_detect_files(const char *dir_path, const char *ext)
{
	char *result = malloc(sizeof(char) * MAX_FILES);
	if (!result)
		return (NULL);
	result[0] = '\0';

	printf(GREEN BOLD"\n🤖 Auto-detecting files is enabled with extension '%s' in directory: %s\n\n" C_RESET, ext, dir_path);

	detect_files(dir_path, dir_path, ext, &result);

	if (strlen(result) == 0)
		printf(RED"\nNo files detected with extension '%s' in directory: %s\n\n" C_RESET, ext, dir_path);

	return (result);
}

void	auto_detec_sources(t_make_config *config)
{
	print_clear();
	print_banner();

	if (!config->src_files || strlen(config->src_files) == 0)
		config->src_files = auto_detect_files(config->src_dir, ".c");
	else
		printf(RED BOLD"🤖 Auto-detecting for src_files DISABLE\n");

	if (!config->src_file_bonus || strlen(config->src_file_bonus) == 0)
		config->src_file_bonus = auto_detect_files(config->src_dir, "_bonus.c");
	else
		printf(RED BOLD"🤖 Auto-detecting for src_files_bonus DISABLE\n");

	if (!config->header_files || strlen(config->header_files) == 0)
		config->header_files = auto_detect_files(config->header_dir, ".h");
	else
		printf(RED BOLD"🤖 Auto-detecting for include_files DISABLE\n");

	print_point_loading();
}

