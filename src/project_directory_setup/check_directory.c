/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#include "make_my_file.h"

static short	is_critical_directory(const char *cwd)
{
	return (strcmp(cwd, "/") == 0 ||
			strcmp(cwd, "/home") == 0 ||
			strcmp(cwd, "/usr") == 0 ||
			strcmp(cwd, "/var") == 0 ||
			strcmp(cwd, "/tmp") == 0 ||
			strcmp(cwd, "/etc") == 0 ||
			strcmp(cwd, "/proc") == 0 ||
			strcmp(cwd, "/sys") == 0 ||
			strcmp(cwd, "/boot") == 0 ||
			strcmp(cwd, "/lib") == 0 ||
			strcmp(cwd, "/lib64") == 0 ||
			strcmp(cwd, "/opt") == 0 ||
			strcmp(cwd, "/sbin") == 0 ||
			strcmp(cwd, "/bin") == 0 ||
			strcmp(cwd, "/root") == 0 ||
			strcmp(cwd, "/dev") == 0);
}


short	check_directory(void)
{
	char message[1400];
	char cwd[MAX_FILES];
	char *c_files;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		exit(EXIT_FAILURE);

	if (is_critical_directory(cwd))
	{
		printf(RED BOLD"\n\nWARNING: You are running the program in a critical system directory: %s\n" C_RESET, cwd);
		printf(RED BOLD"Please run the program in the root of your project directory.\n\n" C_RESET);
		exit(EXIT_FAILURE);
	}

	c_files = auto_detect_files(cwd, ".c");
	print_clear();

	if (c_files && strlen(c_files) > 0)
	{
		snprintf(message, sizeof(message),
				BOLD YELLOW"WARNING: "C_RESET YELLOW"You must be in the project's root directory to proceed.\n" C_RESET
				GREEN BOLD"\n🤖 Auto-Detect - C project detected in current directory: "C_RESET"%s\n\n" 
				CYAN BOLD"\nPress any key to continue... "C_RESET"For confirm you're in the root directory of your project.\n" C_RESET, cwd);
		get_input(message);
		free(c_files);
		return (0);
	}
	else
	{
		snprintf(message, sizeof(message),
				BOLD YELLOW"WARNING: "C_RESET YELLOW"You must be in the project's root directory to proceed.\n" C_RESET
				YELLOW BOLD"🤖 Auto-Detect - No C project detected in directory: "C_RESET"%s\n" 
				CYAN BOLD"\nWould you like to generate a basic C project in this directory ? "YorN"\n\n" C_RESET, cwd);
		char *input = get_default_input(message, "n");
		if (input[0] == 'y' || input[0] == 'Y')
			return (1);
		else
		{
			printf(CYAN BOLD"\nNo project will be generated. Exiting.\n" C_RESET);
			printf(BOLD"Goodbye ! 👋\n");
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}