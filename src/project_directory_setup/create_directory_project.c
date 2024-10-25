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

static void	config_default_project(t_make_config *config)
{
	char src_files[52];
	char header_files[52];
	
	config->name = get_default_input(BOLD"1/1. "C_RESET BOLD CYAN"Enter the name"C_RESET" of the project: \n\n > "ITALIC"No space in name please\n\n"C_RESET BOLD CYAN"➜"C_RESET" ", "ProjectName");
	config->create_lib_or_exec = false;
	config->src_dir = strdup("src");
	config->header_dir = strdup("include");
	default_config(config);
	snprintf(src_files, sizeof(src_files), "main.c %s.c", config->name);
	snprintf(header_files, sizeof(header_files), "%s.h", config->name);
	config->src_files = strdup(src_files);
	config->header_files = strdup(header_files);
}

void	create_directory_project(t_make_config *config)
{
	config_default_project(config);

	mkdir(config->src_dir, 0755);
	mkdir(config->header_dir, 0755);

	/* MAIN.C */
	FILE *main_c = fopen("src/main.c", "w");
	if (main_c)
	{
		fprintf(main_c, MAIN_C_CONTENT, config->name, config->name);
		fclose(main_c);
	}
	/* PROJECT.C */
	char *project_c_path;
	asprintf(&project_c_path, "%s/%s.c", config->src_dir, config->name);
	FILE *project_c = fopen(project_c_path, "w");
	if (project_c)
	{
		fprintf(project_c, PROJECT_C_CONTENT, config->name, config->name, config->name);
		fclose(project_c);
	}
	/* PROJECT.H */
	char *project_h_path;
	asprintf(&project_h_path, "%s/%s.h", config->header_dir, config->name);
	FILE *project_h = fopen(project_h_path, "w");
	if (project_h)
	{
		char *uppercase_name = strdup(config->name);
		int	i = 0;
		while(uppercase_name[i])
		{
			uppercase_name[i] = toupper(uppercase_name[i]);
			i++;
		}
		fprintf(project_h, PROJECT_H_CONTENT, uppercase_name, uppercase_name, uppercase_name, config->name);
		fclose(project_h);
		free(uppercase_name);
	}
	/* .GITIGNORE */
	FILE *gitignore = fopen(".gitignore", "w");
	if (gitignore)
	{
		fprintf(gitignore, GITIGNORE_CONTENT);
		fprintf(gitignore, "# Customize Executable Makefile\n%s\n", config->name);
		fclose(gitignore);
	}
	free(project_h_path);
	free(project_c_path);

	generate_makefile(config);
	print_config_setup_project(config);
}