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
# include <sys/types.h>
# include <fcntl.h>

# define MAX_FILES	4096

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
# define YorN		"( "BOLD GREEN"y"C_RESET BOLD" / "BOLD RED"n"C_RESET" )"

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
	char	*obj_files;				/* Generated obj files		*/ // DELETE ?
	char	*compiler;				/* Compiler					*/
	char	*cflags;				/* Compilation flags		*/
	char	*ldflags;				/* Linker flags				*/
	char	*libs;					/* Libraries to link		*/
	bool	create_obj_dir;			/* Create object directory	*/
	bool	create_dependencies;	/* Generate dependency files*/
	bool	include_libft;			/* Include libft library	*/
	short	create_lib_or_exec;		/* 0 executable, 1 library	*/
	/* char	*output_dir;			/* Executable directory		*/ // FEATURE
}			t_make_config;

/************** MAKE MY FILE ***************/
short	make_my_file(void);
short	init_config(t_make_config *config);
void	auto_detec_sources(t_make_config *config);
void	generate_makefile(t_make_config *config);

/****************** UTILS *******************/
void	free_malloc(t_make_config *config);

/****************** PRINT *******************/
void	print_banner(void);
void	print_point_loading(void);
void	print_clear(void);
void	print_documentation(t_make_config *config);
void	print_menu(t_make_config *config);
void	print_config(t_make_config *config);

#endif
