/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/
#include "make_my_file.h"

char	*get_input(const char *prompt)
{
	char *input = malloc(256);
	if (!input)
		return NULL;

	print_clear();
	print_banner();
	printf("%s", prompt);

	if (fgets(input, 256, stdin) != NULL) {
		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
			input[len - 1] = '\0';
	}
	return (input);
}

char	*get_default_input(const char *prompt, const char *default_value)
{
	char *input = get_input(prompt);
	if (strlen(input) == 0) {
		free(input);
		input = strdup(default_value);
	}
	return (input);
}

void	free_malloc(t_make_config *config)
{
	free(config->name);
	free(config->src_dir);
	free(config->src_files);
	free(config->src_file_bonus);
	free(config->header_dir);
	free(config->header_files);
	free(config->obj_dir);
	free(config->compiler);
	free(config->cflags);
	free(config->ldflags);
	free(config->libs);
	free(config);
}

void	default_config(t_make_config *config)
{
	config->src_files = strdup("");
	config->src_file_bonus = strdup("");
	config->header_files = strdup("");
	config->obj_dir = strdup("obj");
	config->compiler = strdup("cc");
	config->cflags = strdup("-Wall -Wextra -Werror");
	config->include_libft = false;
	config->include_mlx = false;
	config->ldflags = strdup("");
	config->libs = strdup("");
	config->create_obj_dir = true;
	config->create_dependencies = true;
}

