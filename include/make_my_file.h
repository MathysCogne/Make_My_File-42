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
	char	*name;					/* Nom de l'exécutable ou lib */
	char	*src_dir;				/* Src Include */
	char	*src_files;				/* Fichiers sources */
	char	*src_file_bonus;		/* Fichiers bonus */
	char	*header_dir;			/* Dir Include */
	char	*header_files;			/* Fichiers d'en-tête */
	char	*obj_dir;				/* Dossier pour les fichiers objets */
	char	*obj_files;				/* Liste des fichiers objets générés */
	char	*compiler;				/* Compilateur */
	char	*cflags;				/* Options de compilation */
	char	*ldflags;				/* Options de linker */
	char	*libs;					/* Bibliothèques à lier */
	bool	create_obj_dir;			/* Créer le dossier des objets */
	bool	create_dependencies;	/* Générer des fichiers de dépendance */
	bool	include_libft;			/* Inclure la bibliothèque libft */
	short	create_lib_or_exec;		/* 0 pour exécutable, 1 pour bibliothèque */

}			t_make_config;
	// char	*output_dir;			/* Dossier de sortie pour l'exécutable */

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
