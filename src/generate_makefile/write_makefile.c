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

void generate_makefile(t_make_config *config)
{
	FILE *file = fopen("Makefile", "w");
	if (!file)
	{
		printf("Error.\n Could not create Makefile.\n");
		return;
	}

	/*** Doc ***/
	fprintf(file, "# Makefile generated by Make My File: https://github.com/MathysCogne/Make_My_File-42\n\n");
	fprintf(file, MAKEFILE_DOC);

	/*** Header ***/
	fprintf(file, "NAME = %s\n\n", config->name);
	fprintf(file, "SRCDIR = %s\n", config->src_dir);
	fprintf(file, "OBJDIR = %s\n", config->obj_dir);
	fprintf(file, "INCDIR = %s\n\n", config->header_dir);

	/*** Source Files ***/
	fprintf(file, "# Source Files\n");
	fprintf(file, "SRC = %s\n", config->src_files);
	fprintf(file, "OBJ = $(SRC:.c=.o)\n\n");

	fprintf(file, "SRC := $(addprefix $(SRCDIR)/, $(SRC))\n");
	fprintf(file, "OBJ := $(patsubst $(SRCDIR)/%%, $(OBJDIR)/%%, $(OBJ))\n\n");

	/*** Bonus Files ***/
	if (config->src_file_bonus && strlen(config->src_file_bonus) > 0)
	{
		fprintf(file, "# Bonus Files\n");
		fprintf(file, "BONUS_SRC = %s\n", config->src_file_bonus);
		fprintf(file, "BONUS_OBJ = $(BONUS_SRC:.c=.o)\n\n");

		fprintf(file, "BONUS_SRC := $(addprefix $(SRCDIR)/, $(BONUS_SRC))\n");
		fprintf(file, "BONUS_OBJ := $(addprefix $(OBJDIR)/, $(notdir $(BONUS_OBJ)))\n\n");
	}

	/*** Compiler and Flags ***/
	fprintf(file, "# Compiler and Flags\n");
	fprintf(file, "CC = %s\n", config->compiler);
	fprintf(file, "CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3\n\n");

	/*** Linker Flags and Libraries ***/
	fprintf(file, "# Linker Flags and Libraries\n");
	fprintf(file, "LDFLAGS = %s\n", (config->ldflags && strlen(config->ldflags) > 0) ? config->ldflags : "");
	fprintf(file, "LIBS = %s\n\n", (config->libs && strlen(config->libs) > 0) ? config->libs : "");

	/*** Colors ***/
	fprintf(file, "# Colors\n");
    fprintf(file, "RED     := \"\\033[1;31m\"\n");
    fprintf(file, "GREEN   := \"\\033[1;32m\"\n");
    fprintf(file, "RESET   := \"\\033[0m\"\n\n");

	/*** Silence Compil ***/
	fprintf(file, "# Compilation mode (silent by default, set VERBOSE=1 to show commands)\n");
	fprintf(file, "VERBOSE ?= 0\n");
	fprintf(file, "ifeq ($(VERBOSE),1)\n");
	fprintf(file, "  V := \n");
	fprintf(file, "else\n");
	fprintf(file, "  V := @\n");
	fprintf(file, "endif\n\n");

	/*** All Rule ***/
	fprintf(file, "# All Rule\n");
	fprintf(file, "all: $(OBJDIR) $(NAME)\n\n");

	/*** Object Directory Rule ***/
	fprintf(file, "# Object Directory Rule\n");
	fprintf(file, "$(OBJDIR):\n");
	fprintf(file, "\t$(V)mkdir -p $(OBJDIR) || true\n\n");

	/*** Dependency ***/
	if (config->create_dependencies)
	{
		fprintf(file, "# Dependency Files\n");
		fprintf(file, "DEPDIR = $(OBJDIR)/deps\n");
		fprintf(file, "DEP = $(OBJ:.o=.d)\n\n");

		fprintf(file, "$(DEPDIR):\n");
		fprintf(file, "\t$(V)mkdir -p $(DEPDIR) || true\n\n");

		fprintf(file, "$(OBJDIR)/%%.o: $(SRCDIR)/%%.c\n");
		fprintf(file, "\t@mkdir -p $(dir $@)\n");
		fprintf(file, "\t$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@\n\n");

		fprintf(file, "-include $(DEP)\n\n");
	}

	/*** Compilation Rules ***/
	fprintf(file, "# Compilation Rules\n");
	fprintf(file, "$(OBJDIR)/%%.o: $(SRCDIR)/%%.c | $(OBJDIR) $(DEPDIR)\n");
	fprintf(file, "\t$(V)$(CC) $(CFLAGS) -MMD -c $< -o $@\n");


	/*** Linking Rule ***/
	fprintf(file, "# Linking Rule\n");
	fprintf(file, "$(NAME): $(OBJ)");
	if (config->src_file_bonus && strlen(config->src_file_bonus) > 0)
	{
		fprintf(file, " $(BONUS_OBJ)");
	}
	fprintf(file, "\n");

	if (config->create_lib_or_exec == 1) /* lib */
	{
		fprintf(file, "\t$(V)$(AR) rcs $@ $^\n");
		fprintf(file, "\t$(V)echo $(GREEN)\"🤖 [$(NAME)] Library created ✅\"$(RESET)\n\n");
	}
	else /* exec */
	{
		fprintf(file, "\t$(V)$(CC) $(OBJ) $(BONUS_OBJ) -o $@ $(LDFLAGS) $(LIBS)\n");
		fprintf(file, "\t$(V)echo $(GREEN)\"🤖 [$(NAME)] Executable created ✅\"$(RESET)\n\n");
	}

	/*** Clean Rules ***/
	fprintf(file, "# Clean Rules\n");
	fprintf(file, "clean:\n");
	fprintf(file, "\t$(V)echo $(RED)\"🗑️  CLEANING OBJS\"$(RESET)\n");
	fprintf(file, "\t$(V)rm -rf $(OBJDIR)\n");

	if (config->create_dependencies)
	{
		fprintf(file, "\t$(V)rm -rf $(DEPDIR)\n");
	}

	fprintf(file, "\n");

	fprintf(file, "fclean: clean\n");
	fprintf(file, "\t$(V)echo $(RED)\"🔥 CLEANING ALL\"$(RESET)\n");
	fprintf(file, "\t$(V)rm -f $(NAME)\n\n");

	fprintf(file, "re: fclean all\n\n");

	/*** If Use Libft ***/
	if (config->include_libft)
	{
		fprintf(file, "# Configuration for libft\n");
		fprintf(file, "LIBFT_DIR := path/to/libft\n");  // TODO LIST CHANGE
		fprintf(file, "LIBFT := $(LIBFT_DIR)/libft.a\n\n");

		fprintf(file, "all: $(LIBFT) $(NAME)\n\n");

		fprintf(file, "$(LIBFT):\n");
		fprintf(file, "\t$(V)$(MAKE) -C $(LIBFT_DIR)\n");
		fprintf(file, "\t$(V)echo '📚 Libft built successfully!'\n\n");

		fprintf(file, "$(NAME): $(OBJ) $(LIBFT)\n");
		fprintf(file, "\t$(V)$(CC) $(OBJ) $(LIBFT) -o $@ $(LDFLAGS) $(LIBS)\n");
		fprintf(file, "\t$(V)echo $(GREEN)\"🤖 [$(NAME)] Executable with libft created\"$(RESET)\n\n");
	}

	/*** Bonus Rule ***/
	if (config->src_file_bonus && strlen(config->src_file_bonus) > 0)
	{
		fprintf(file, "bonus: $(OBJDIR) $(BONUS_OBJ) $(NAME)\n");
		fprintf(file, "\t$(V)echo $(GREEN)\"🤖 BONUS OBJECTS READY\"$(RESET)\n\n");
	}

	/*** Re Gen Rule ***/
	fprintf(file, "# Makefile Reconfiguration \n");
	fprintf(file, "regen:\n");
	fprintf(file, "\tmakemyfile");

	fprintf(file, ".PHONY: all clean fclean re bonus regen\n");
	fprintf(file, ".DEFAULT_GOAL := all\n");

	fclose(file);
}