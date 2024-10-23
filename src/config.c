/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#include "make_my_file.h"

char *get_input(const char *prompt)
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

static char *get_default_input(const char *prompt, const char *default_value)
{
	char *input = get_input(prompt);
	if (strlen(input) == 0) {
		free(input);
		input = strdup(default_value);
	}
	return (input);
}

short init_config(t_make_config *config)
{
	bool	fast_mode = false;
	char *fast_mode_input = get_default_input(BOLD GREEN"Welcome to the Make My File!\n\n" C_RESET
										"This application will help you create a Makefile.\n\n\n"
										BOLD"🚀 "C_RESET"Enable "BOLD CYAN"fast mode "C_RESET""YorN" ?\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "n");
	fast_mode = (fast_mode_input[0] == 'y' || fast_mode_input[0] == 'Y');
	free(fast_mode_input);

	/* FAST MODE */
	if (fast_mode)
	{
		char *create_lib_or_exec = get_input(BOLD"1. "C_RESET"Create "CYAN"library "BOLD"'1'"C_RESET" or "C_RESET CYAN"executable "BOLD"'0'"C_RESET ITALIC" (Default is executable)"C_RESET" ?\n\n"C_RESET BOLD CYAN"➜"C_RESET" ");
		config->create_lib_or_exec = (create_lib_or_exec[0] == '1') ? 1 : 0;
		free(create_lib_or_exec);

		config->name = get_default_input(BOLD"1. "C_RESET BOLD CYAN"Enter the name"C_RESET" of the executable or library: \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "ProjectName");
		config->src_dir = get_default_input(BOLD"2. "C_RESET"Enter the "BOLD CYAN"source directory"C_RESET" or leave blank for "BOLD CYAN"default"C_RESET" "ITALIC"(Default is 'src'): \n\n"
										"> If using the current directory, please type '.'\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "src");
		config->header_dir = get_default_input(BOLD"3. "C_RESET"Enter the "BOLD CYAN"includes directory"C_RESET" or leave blank for "BOLD CYAN"default"C_RESET" "ITALIC"(Default is 'include'): \n\n"
										"> If using the current directory, please type '.'\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "include");

		config->src_files = strdup("");
		config->src_file_bonus = strdup("");
		config->header_files = strdup("");
		config->obj_dir = strdup("obj");
		config->obj_files = NULL;
		config->compiler = strdup("cc");
		config->cflags = strdup("-Wall -Wextra -Werror");
		config->include_libft = false;
		config->ldflags = strdup("");
		config->libs = strdup("");
		config->create_obj_dir = true;
		config->create_dependencies = true;
		
		return (0);
	}

	/* NORMAL MODE */
	char *create_lib_or_exec = get_default_input(BOLD"1. "C_RESET"Create "CYAN"library "BOLD"'1'"C_RESET" or "C_RESET CYAN"executable "BOLD"'0'"C_RESET ITALIC" (Default is executable)"C_RESET" ?\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "0");
	config->create_lib_or_exec = (create_lib_or_exec[0] == '1') ? 1 : 0;
	free(create_lib_or_exec);

	config->name = get_default_input(BOLD"2. "C_RESET BOLD CYAN"Enter the name"C_RESET" of the executable or library: \n\n" BOLD CYAN"➜"C_RESET" ", "ProjectName");
	config->src_dir = get_default_input(BOLD"2. "C_RESET"Enter the "BOLD CYAN"source directory"C_RESET" or leave blank for "BOLD CYAN"default"C_RESET" "ITALIC"(Default is 'src'): \n\n"
										"> If using the current directory, please type '.'\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "src");
	config->header_dir = get_default_input(BOLD"3. "C_RESET"Enter the "BOLD CYAN"includes directory"C_RESET" or leave blank for "BOLD CYAN"default"C_RESET" "ITALIC"(Default is 'include'): \n\n"
										"> If using the current directory, please type '.'\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "include");
	config->src_files = get_default_input(BOLD"5. "C_RESET"Enter the "BOLD CYAN"source files"C_RESET" or leave blank for "BOLD CYAN"auto-detection"C_RESET" "ITALIC"(Ex: main.c utils.c ft_putchar.c): \n\n"
										C_RESET"🤖"ITALIC" If left blank, source files will be automatically detected in the selected directory\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");

	config->src_file_bonus = get_default_input(BOLD"6. "C_RESET"Enter the "BOLD CYAN"bonus source files"C_RESET" or leave blank for "BOLD CYAN"auto-detection"C_RESET" "ITALIC"(Ex: *_bonus.c): \n\n"
										C_RESET"🤖"ITALIC" If left blank, bonus source files will be automatically detected in the selected directory\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");
	config->header_files = get_default_input(BOLD"7. "C_RESET"Enter the "BOLD CYAN"header files"C_RESET" or leave blank for "BOLD CYAN"auto-detection"C_RESET" "ITALIC"(Ex: ft.h): \n\n"
										C_RESET"🤖"ITALIC" If left blank, header files will be automatically detected in the selected directory\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");
	config->obj_dir = strdup("obj");
	config->obj_files = NULL;

	config->compiler = get_default_input(BOLD"8. "C_RESET BOLD CYAN"Enter the compiler"C_RESET" "ITALIC"(Default is 'cc' leave blank): \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "cc");
	config->cflags = get_default_input(BOLD"9. "C_RESET BOLD CYAN"Enter the compilation flags"C_RESET" "ITALIC"(Default '-Wall -Wextra -Werror' leave blank): \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "-Wall -Wextra -Werror");
	char *include_libft = get_default_input(BOLD"10. "C_RESET"Include "BOLD CYAN"ft_libft "YorN" "C_RESET"?  "C_RESET ITALIC"(Default 'No')\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "n");
	config->include_libft = (include_libft[0] == 'y' || include_libft[0] == 'Y');
	free(include_libft);

	config->ldflags = get_default_input(BOLD"11. "C_RESET BOLD CYAN"Enter the linker flags"C_RESET" (LDFLAGS) or leave blank for none: \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");
	config->libs = get_default_input(BOLD"12. "C_RESET"Enter "BOLD CYAN"the libraries to link"C_RESET" or leave blank if none: \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");

	char *create_obj_dir = get_default_input(BOLD"13. "C_RESET"Create and using "BOLD CYAN"object directory with dependency files" "YorN" C_RESET" ? "C_RESET ITALIC "(Default 'Yes')\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "y");
	config->create_obj_dir = (create_obj_dir[0] == 'y' || create_obj_dir[0] == 'Y');
	config->create_dependencies = config->create_obj_dir;
	free(create_obj_dir);

	return (0);
}
