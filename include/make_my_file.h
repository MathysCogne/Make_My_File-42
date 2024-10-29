/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#ifndef MAKE_MY_FILE_H
# define MAKE_MY_FILE_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <fcntl.h>
# include <ctype.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <curl/curl.h>

/***************** UPDATE *******************/
#define CURRENT_VERSION "1.2.1"
#define REPO_OWNER "MathysCogne"
#define REPO_NAME "Make_My_File-42"

/***************** MACROS *******************/
# define MAX_FILES	1024

# define SOURCE_EXTENSION ".c"
# define HEADER_EXTENSION ".h"

/***************** COLORS ******************/
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UDERLINE	"\033[4m"
# define C_RESET	"\033[0m"

# define YorN		""C_RESET"["BOLD GREEN"y"C_RESET BOLD"/"BOLD RED"n"C_RESET"]"

/***************** STRUCT ******************/
typedef struct s_make_config
{
	char	*name;					/* Executable name 			*/
	char	*src_dir;				/* Src dir					*/
	char	*src_files;				/* Src files				*/
	char	*src_file_bonus;		/* Src files bonus			*/
	char	*header_dir;			/* Header dir				*/
	char	*header_files;			/* Header files				*/
	char	*obj_dir;				/* Object dir				*/
	char	*compiler;				/* Compiler					*/
	char	*cflags;				/* Compilation flags		*/
	char	*ldflags;				/* Linker flags				*/
	char	*libs;					/* Libraries to link		*/
	bool	create_obj_dir;			/* Create object directory	*/
	bool	create_dependencies;	/* Generate dependency files*/
	bool	include_libft;			/* Include libft library	*/
	bool	include_mlx;			/* Include MLX library		*/
	short	create_lib_or_exec;		/* 0 executable, 1 library	*/
	/* char	*output_dir;				Executable directory	*/ // FEATURE
}			t_make_config;

/************** MAKE MY FILE ***************/
/* PROJECT DIR SETUP */
short	check_directory(void);
void	create_directory_project(t_make_config *config);

/* GENERATION MAKEFILE */
short	make_my_file(t_make_config *config);
short	init_config(t_make_config *config);
void	auto_detec_sources(t_make_config *config);
char	*auto_detect_files(const char *dir_path, const char *ext);
void	generate_makefile(t_make_config *config);
/* AUTO UPDATE */
void check_for_updates();

/****************** UTILS *******************/
void	free_malloc(t_make_config *config);
void	default_config(t_make_config *config);
char	*get_input(const char *prompt);
char	*get_default_input(const char *prompt, const char *default_value);

/****************** PRINT *******************/
void	print_banner(void);
void	print_point_loading(void);
void	print_clear(void);
void	print_documentation(t_make_config *config);
void	print_menu(t_make_config *config);
void	print_config(t_make_config *config);
void	print_config_setup_project(t_make_config *config);

#endif
