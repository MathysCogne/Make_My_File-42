/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#include "make_my_file.h"

char	*auto_detect_files(const char *dir_path, const char *ext)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*result;
	char 			*tmp;

	result = malloc(sizeof(char) * MAX_FILES);
	if (!result)
		return (NULL);
	result[0] = '\0';
	dir = opendir(dir_path);
	if (!dir)
	{
		printf("Error auto-detecting.\nCould not open directory: %s\n", dir_path);
		free(result);
		exit(EXIT_FAILURE);
	}
	
	printf(GREEN BOLD"\n🤖 Auto-detecting files is enable with extension '%s' in directory: %s\n" C_RESET, ext, dir_path);

	while ((entry = readdir(dir)) != NULL)
	{
		/* Check ext name */
		if (strstr(entry->d_name, ext))
		{
			/* Add files to list */
			if (strlen(result) + strlen(entry->d_name) + 2 > MAX_FILES)
			{
				// Realloc if > max files
				tmp = realloc(result, strlen(result) + strlen(entry->d_name) + 2);
				if (!tmp)
				{
					free(result);
					return (NULL);
				}
				result = tmp;
			}
			strcat(result, entry->d_name);
			strcat(result, " ");

			printf(C_RESET ITALIC "Detected file: %s" C_RESET "\n", entry->d_name);
		}
	}
	closedir(dir);
	return result;
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
	
	if (!config->src_files || strlen(config->src_files) == 0)
		printf(RED"\nError.\nSource files could not be detected. "C_RESET"Please check the source files directory: %s\n\n", config->src_dir);
	if (!config->header_files || strlen(config->header_files) == 0)
		printf(RED"\nError.\nHeader files not be detected. "C_RESET"Please check the header files directory: %s\n\n", config->header_dir);
}
