/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#include "make_my_file.h"
#include "write_in_file.h"

void	print_banner(void)
{
	printf(C_RESET RED"\n███╗   ███╗ █████╗ ██╗  ██╗███████╗ "C_RESET"███╗   ███╗██╗   ██╗ "YELLOW"███████╗██╗██╗     ███████╗\n");
	printf(RED          "████╗ ████║██╔══██╗██║ ██╔╝██╔════╝ "C_RESET"████╗ ████║╚██╗ ██╔╝ "YELLOW"██╔════╝██║██║     ██╔════╝\n");
	printf(RED          "██╔████╔██║███████║█████╔╝ █████╗   "C_RESET"██╔████╔██║ ╚████╔╝  "YELLOW"█████╗  ██║██║     █████╗  \n");
	printf(RED          "██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝   "C_RESET"██║╚██╔╝██║  ╚██╔╝   "YELLOW"██╔══╝  ██║██║     ██╔══╝  \n");
	printf(RED          "██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗ "C_RESET"██║ ╚═╝ ██║   ██║    "YELLOW"██║     ██║███████╗███████╗\n");
	printf(RED          "╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝ "C_RESET"╚═╝     ╚═╝   ╚═╝    "YELLOW"╚═╝     ╚═╝╚══════╝╚══════╝\n\n\n" C_RESET);
}

void	print_point_loading(void)
{
	int	i;
	
	i = 0;
	printf(GREEN BOLD"\n\nLoading");
	while (i < 3)
	{
		printf(".");
		fflush(stdout);
		sleep(1);
		i++;
	}
}

void	print_clear(void)
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void	print_config(t_make_config *config)
{
	print_clear();
	print_banner();

	printf(GREEN BOLD "Congratulations ! 🥳🥳🥳 Your Makefile has been generated successfully !\n\n\n" C_RESET);
	printf(CYAN BOLD"You are creating a Makefile that generates an "BOLD PURPLE"%s", config->create_lib_or_exec ? "library" : "executable");
	printf(CYAN", named "PURPLE"%s"C_RESET":\n", config->name);

	printf("\n- For compilation, you will be using: " BOLD PURPLE "%s %s %s" C_RESET "\n", config->compiler, config->cflags, config->ldflags);
	printf("- Use and create an Object Directory / Dependency Files: " BOLD "%s" C_RESET "\n\n", config->create_obj_dir ? GREEN"Yes" : RED"No");

	printf("- Source Files: " BOLD PURPLE "%s" C_RESET "\n", config->src_files);
	printf("- Header Files: " BOLD PURPLE "%s" C_RESET "\n", config->header_files);
	printf("- Bonus Source Files: " BOLD PURPLE "%s" C_RESET "\n\n", 
					strlen(config->src_file_bonus) > 0 ? config->src_file_bonus : RED"No bonus");

	printf("- Libraries included: " BOLD PURPLE "%s" C_RESET "\n",
					strlen(config->libs) > 0 ? config->libs : "None"C_RESET);
	printf("- Libft inclusion: " BOLD "%s" C_RESET "\n", config->include_libft ? GREEN"Yes" : PURPLE"No");
	printf("- MLX inclusion: " BOLD "%s" C_RESET "\n\n\n", config->include_mlx ? GREEN"Yes" : PURPLE"No");

	printf("Thank you for using Make My File ! Enjoy your project ! 🚀\n\n");
	printf("⭐ If you like this project, please star it on GitHub: ");
	printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42" C_RESET "\n");
	printf("🤖 Report any bugs or suggestions at: ");
	printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42/issues" C_RESET "\n\n");

	exit(EXIT_SUCCESS);
}

void	print_config_setup_project(t_make_config *config)
{
	print_clear();
	print_banner();

	printf(GREEN BOLD "Congratulations ! 🥳🥳🥳 Your basic C project has been generated successfully !\n\n" C_RESET);

	printf("\n- For compilation, you will be using: " BOLD PURPLE "%s %s %s" C_RESET "\n", config->compiler, config->cflags, config->ldflags);
	printf("- Source Files: " BOLD PURPLE "%s" C_RESET "\n", config->src_files);
	printf("- Header Files: " BOLD PURPLE "%s" C_RESET "\n\n", config->header_files);

	printf("Thank you for using Make My File ! Enjoy your project ! 🚀\n\n");
	printf("⭐ If you like this project, please star it on GitHub: ");
	printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42" C_RESET "\n");
	printf("🤖 Report any bugs or suggestions at: ");
	printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42/issues" C_RESET "\n\n");

	exit(EXIT_SUCCESS);
}
/* ARCHIVE ******************************************************************************
*void	print_documentation(t_make_config *config)
*{
*	print_clear();
*	print_banner();
*
*	printf(MAKEFILE_DOC);
*
*	print_menu(config);
*}
*
*void	print_menu(t_make_config *config)
*{
*	int choice;
*
*	while (1)
*	{	
*		printf(BOLD CYAN"\n0 ➤"C_RESET" View the documentation\n");
*		printf(BOLD CYAN"1 ➤"C_RESET" Exit\n");
*		printf(BOLD CYAN "\n➜ " C_RESET);
*		if (scanf("%d", &choice) != 1)
*		{
*			printf(RED "Invalid option\n\n" C_RESET);
*			while (getchar() != '\n');
*			continue ;
*		}
*
*		if (choice == 0)
*			print_documentation(config);
*		if (choice == 1)
*		{
*			print_clear();
*			print_banner();
*			printf("Thank you for using Make My File ! Enjoy your project ! 🚀\n\n");
*			printf("⭐ If you like this project, please star it on GitHub: ");
*			printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42" C_RESET "\n");
*			printf("🤖 Report any bugs or suggestions at: ");
*			printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42/issues" C_RESET "\n\n");
*			printf(BOLD"\nGoodbye ! 👋\n\n");
*			exit(0);
*		}
*		else
*			printf(RED "Invalid option.\n\n" C_RESET);
*	}
*}
***********************************************************************************************/