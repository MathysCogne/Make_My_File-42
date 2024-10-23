/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#include "make_my_file.h"

void	print_banner(void)
{
	printf(C_RESET RED"\n███╗   ███╗ █████╗ ██╗  ██╗███████╗       "C_RESET"███╗   ███╗██╗   ██╗       "YELLOW"███████╗██╗██╗     ███████╗\n");
	printf(RED          "████╗ ████║██╔══██╗██║ ██╔╝██╔════╝       "C_RESET"████╗ ████║╚██╗ ██╔╝       "YELLOW"██╔════╝██║██║     ██╔════╝\n");
	printf(RED          "██╔████╔██║███████║█████╔╝ █████╗         "C_RESET"██╔████╔██║ ╚████╔╝        "YELLOW"█████╗  ██║██║     █████╗  \n");
	printf(RED          "██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝         "C_RESET"██║╚██╔╝██║  ╚██╔╝         "YELLOW"██╔══╝  ██║██║     ██╔══╝  \n");
	printf(RED          "██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗       "C_RESET"██║ ╚═╝ ██║   ██║          "YELLOW"██║     ██║███████╗███████╗\n");
	printf(RED          "╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝       "C_RESET"╚═╝     ╚═╝   ╚═╝          "YELLOW"╚═╝     ╚═╝╚══════╝╚══════╝\n\n\n" C_RESET);
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

void	print_documentation(t_make_config *config)
{
	print_clear();
	print_banner();

	printf(BOLD GREEN "📄 Documentation for Make My File:\n" C_RESET);
	printf(BOLD CYAN "This Makefile is generated automatically by the Make My File program.\n" C_RESET);
	printf("It facilitates the compilation of C programs.\n\n");

	printf(BOLD CYAN "Variables:\n" C_RESET);
	printf("- " BOLD "NAME:" C_RESET " Name of the executable or library to create.\n");
	printf("- " BOLD "SRCDIR:" C_RESET " Directory where source files are located.\n");
	printf("- " BOLD "OBJDIR:" C_RESET " Directory where object files will be stored.\n");
	printf("- " BOLD "INCDIR:" C_RESET " Directory containing header files.\n");
	printf("- " BOLD "SRC:" C_RESET " List of source files to compile.\n");
	printf("- " BOLD "OBJ:" C_RESET " List of object files generated from the source files.\n");
	printf("- " BOLD "CC:" C_RESET " The compiler to use (default is 'cc').\n");
	printf("- " BOLD "CFLAGS:" C_RESET " Compilation flags (default includes warnings and debugging).\n");
	printf("- " BOLD "LDFLAGS:" C_RESET " Linker flags (if any).\n");
	printf("- " BOLD "LIBS:" C_RESET " Libraries to link against.\n\n");

	printf(BOLD CYAN "Rules:\n" C_RESET);
	printf("- " BOLD "make:" C_RESET " Builds the project.\n");
	printf("- " BOLD "make clean:" C_RESET " Removes object files.\n");
	printf("- " BOLD "make fclean:" C_RESET " Removes all generated files including the executable.\n");
	printf("- " BOLD "make re:" C_RESET " Cleans and rebuilds the project.\n\n");

	printf(BOLD CYAN "Note:\n" C_RESET);
	printf("For bonus files, set the 'src_file_bonus' parameter in the configuration.\n");
	printf("Use 'VERBOSE=1' for detailed output during compilation.\n\n");

	printf(BOLD GREEN "Happy coding! 😊" C_RESET "\n\n\n");

	print_menu(config);
}

void	print_menu(t_make_config *config)
{
	int choice;

	while (1)
	{	
		printf(BOLD CYAN "Menu:\n" C_RESET);
		printf(BOLD"'0'"C_RESET" Quit\n");
		printf(BOLD"'1'"C_RESET" View the documentation (Help)\n");
		printf(BOLD CYAN "Choose an option: " C_RESET);
		if (scanf("%d", &choice) != 1)
		{
			printf(RED "Invalid option\n\n" C_RESET);
			while (getchar() != '\n');
			continue ;
		}
		if (choice == 0)
		{
			print_clear();
		print_banner();
			printf("Thank you for using Make My File ! Enjoy your project ! 🚀\n\n");
			printf("⭐ If you like this project, please star it on GitHub: ");
			printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42" C_RESET "\n");
			printf("🤖 Report any bugs or suggestions at: ");
			printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42/issues" C_RESET "\n\n");
			printf(BOLD"\nGoodbye ! 👋\n\n");
			exit(0);
		}

		else if (choice == 1)
			print_documentation(config);
		else
			printf(RED "Invalid option.\n\n" C_RESET);
	}
}

void	print_config(t_make_config *config)
{
	print_clear();
	print_banner();

	printf(GREEN BOLD "Congratulations ! 🥳🥳🥳 Your Makefile has been generated successfully !\n\n\n" C_RESET);
	printf(BOLD CYAN "You are creating a %s", config->create_lib_or_exec ? "Library" : "Executable");
	printf(", %s\n\n", config->name);

	printf(BOLD CYAN "Here are the details of your project:\n" C_RESET);
	printf("- Source Files: " BOLD PURPLE "%s" C_RESET "\n", config->src_files);
	printf("- Bonus Source Files: " BOLD PURPLE "%s" C_RESET "\n", 
					strlen(config->src_file_bonus) > 0 ? config->src_file_bonus : RED"No bonus");
	printf("- Header Files: " BOLD PURPLE "%s" C_RESET "\n", config->header_files);
	printf("- Create an Object Directory: " BOLD "%s" C_RESET "\n", config->create_obj_dir ? GREEN"Yes" : RED"No");
	printf("- Create Dependency Files: " BOLD "%s" C_RESET "\n", config->create_dependencies ? GREEN"Yes" : RED"No");

	printf(BOLD CYAN "\nFor compilation, you will be using:\n" C_RESET);
	printf("- Compiler: " BOLD PURPLE "%s %s %s" C_RESET "\n", config->compiler, config->cflags, config->ldflags);

	printf(BOLD CYAN "About libraries:\n" C_RESET);
	printf("- Libraries included: " BOLD PURPLE "%s" C_RESET "\n",
					strlen(config->libs) > 0 ? config->libs : "None");
	printf("- Include Libft: " BOLD "%s" C_RESET "\n\n", config->include_libft ? GREEN"Yes" : PURPLE"No");

	printf("Thank you for using Make My File ! Enjoy your project ! 🚀\n\n");
	printf("⭐ If you like this project, please star it on GitHub: ");
	printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42" C_RESET "\n");
	printf("🤖 Report any bugs or suggestions at: ");
	printf(BOLD CYAN "https://github.com/MathysCogne/Make_My_File-42/issues" C_RESET "\n\n");

	print_menu(config);
}