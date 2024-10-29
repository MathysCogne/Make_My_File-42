/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#include "make_my_file.h"

short init_config(t_make_config *config)
{
	bool	fast_mode = false;
	char *fast_mode_input = get_default_input(BOLD GREEN"Welcome to the Make My File ! \n\n" C_RESET
										"This application will help you create a Makefile.\n\n\n"
										BOLD"🚀 "C_RESET"Enable "BOLD CYAN"fast mode "C_RESET""YorN" ?\n\n"C_RESET 
										"> If you want to use Libft or MiniLibX (minilibx-linux), please choose No. \n"
										"> 💡 Tips: Leaving the options blank will always set a default value \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "src");
	fast_mode = (fast_mode_input[0] == 'y' || fast_mode_input[0] == 'Y');
	free(fast_mode_input);

	/* FAST MODE */
	if (fast_mode)
	{
		char *create_lib_or_exec = get_input(BOLD"[1/4] "C_RESET"Create "CYAN"library "BOLD"'1'"C_RESET" or "C_RESET CYAN"executable "BOLD"'0'"C_RESET ITALIC" (Default is executable)"C_RESET" ?\n\n"C_RESET BOLD CYAN"➜"C_RESET" ");
		config->create_lib_or_exec = (create_lib_or_exec[0] == '1') ? 1 : 0;
		free(create_lib_or_exec);

		config->name = get_default_input(BOLD"[2/4] "C_RESET BOLD CYAN"Enter the name"C_RESET" of the executable or library: \n\n > "ITALIC"No space in name please\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "ProjectName");
		config->src_dir = get_default_input(BOLD"[3/4] "C_RESET"Enter the "BOLD CYAN"source directory"C_RESET" or leave blank for "BOLD CYAN"default"C_RESET" "ITALIC"(Default is 'src'): \n\n"
										"> If using the current directory, please type '.'\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "src");
		config->header_dir = get_default_input(BOLD"[4/4] "C_RESET"Enter the "BOLD CYAN"includes directory"C_RESET" or leave blank for "BOLD CYAN"default"C_RESET" "ITALIC"(Default is 'include'): \n\n"
										"> If using the current directory, please type '.'\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "include");
		default_config(config); // Set other params
		return (0);
	}

	/* NORMAL MODE */
	char *create_lib_or_exec = get_default_input(BOLD"[1/13] "C_RESET"Create "CYAN"library "BOLD"'1'"C_RESET" or "C_RESET CYAN"executable "BOLD"'0'"C_RESET ITALIC" (Default is executable)"C_RESET" ?\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "0");
	config->create_lib_or_exec = (create_lib_or_exec[0] == '1') ? 1 : 0;
	free(create_lib_or_exec);

	config->name = get_default_input(BOLD"[2/13] "C_RESET BOLD CYAN"Enter the name"C_RESET" of the executable or library: \n\n > "ITALIC"No space in name please\n\n" BOLD CYAN"➜"C_RESET" ", "ProjectName");
	config->src_dir = get_default_input(BOLD"[3/13] "C_RESET"Enter the "BOLD CYAN"source directory"C_RESET" or leave blank for "BOLD CYAN"default"C_RESET" "ITALIC"(Default is 'src'): \n\n"
										"> If using the current directory, please type '.'\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "src");
	config->header_dir = get_default_input(BOLD"[4/13] "C_RESET"Enter the "BOLD CYAN"includes directory"C_RESET" or leave blank for "BOLD CYAN"default"C_RESET" "ITALIC"(Default is 'include'): \n\n"
										"> If using the current directory, please type '.'\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "include");
	config->src_files = get_default_input(BOLD"[5/13] "C_RESET"Enter the "BOLD CYAN"source files"C_RESET" or leave blank for "BOLD CYAN"auto-detection"C_RESET" "ITALIC"(Ex: main.c utils.c ft_putchar.c): \n\n"
										C_RESET"🤖"ITALIC" If left blank, source files will be automatically detected in the selected directory\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");

	config->src_file_bonus = get_default_input(BOLD"[6/13] "C_RESET"Enter the "BOLD CYAN"bonus source files"C_RESET" or leave blank for "BOLD CYAN"auto-detection"C_RESET" "ITALIC"(Ex: *_bonus.c): \n\n"
										C_RESET"🤖"ITALIC" If left blank, bonus source files will be automatically detected in the selected directory\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");
	config->header_files = get_default_input(BOLD"[7/13] "C_RESET"Enter the "BOLD CYAN"header files"C_RESET" or leave blank for "BOLD CYAN"auto-detection"C_RESET" "ITALIC"(Ex: ft.h): \n\n"
										C_RESET"🤖"ITALIC" If left blank, header files will be automatically detected in the selected directory\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");
	config->obj_dir = strdup("obj");

	config->compiler = get_default_input(BOLD"[8/13] "C_RESET BOLD CYAN"Enter the compiler"C_RESET" "ITALIC"(Default is 'cc' leave blank): \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "cc");
	config->cflags = get_default_input(BOLD"[9/13] "C_RESET BOLD CYAN"Enter the compilation flags"C_RESET" "ITALIC"(Default '-Wall -Wextra -Werror' leave blank): \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "-Wall -Wextra -Werror");
	char *include_libft = get_default_input(BOLD"[10/13] "C_RESET"Include "BOLD CYAN"ft_libft "YorN" "C_RESET"?  "C_RESET ITALIC"(Default 'No')\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "n");
	config->include_libft = (include_libft[0] == 'y' || include_libft[0] == 'Y');
	free(include_libft);

	char *include_mlx = get_default_input(BOLD"[11/13] "C_RESET"Include "BOLD CYAN"MLX (minilibx-linux) with auto download script. "YorN" "C_RESET"?  "C_RESET ITALIC"(Default 'No')\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "n");
	config->include_mlx = (include_mlx[0] == 'y' || include_mlx[0] == 'Y');
	free(include_mlx);

	config->ldflags = get_default_input(BOLD"[12/13] "C_RESET BOLD CYAN"Enter the linker flags"C_RESET" (LDFLAGS) or leave blank for none: \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");
	config->libs = get_default_input(BOLD"[13/13] "C_RESET"Enter "BOLD CYAN"the libraries to link"C_RESET" or leave blank if none: \n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "");

	// char *create_obj_dir = get_default_input(BOLD"14. "C_RESET"Create and using "BOLD CYAN"object directory with dependency files" "YorN" C_RESET" ? "C_RESET ITALIC "(Default 'Yes')\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "y");
	// config->create_obj_dir = (create_obj_dir[0] == 'y' || create_obj_dir[0] == 'Y');
	// config->create_dependencies = config->create_obj_dir;
	// free(create_obj_dir);
	config->create_dependencies = true;

	return (0);
}
