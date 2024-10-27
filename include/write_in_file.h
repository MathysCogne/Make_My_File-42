/************************************************************************************************/
/*	███╗   ███╗ █████╗ ██╗  ██╗███████╗    ███╗   ███╗██╗   ██╗    ███████╗██╗██╗     ███████╗	*/
/*	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ████╗ ████║╚██╗ ██╔╝    ██╔════╝██║██║     ██╔════╝	*/
/*	██╔████╔██║███████║█████╔╝ █████╗      ██╔████╔██║ ╚████╔╝     █████╗  ██║██║     █████╗  	*/
/*	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║╚██╔╝██║  ╚██╔╝      ██╔══╝  ██║██║     ██╔══╝  	*/
/*	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██║ ╚═╝ ██║   ██║       ██║     ██║███████╗███████╗	*/
/* 	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝     ╚═╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚══════╝	*/
/************************************************************************************************/

#ifndef WRITE_IN_FILE_H
# define WRITE_IN_FILE_H

/***************** DEFAULT_PROJECT_GEN ******************/
#define MAIN_C_CONTENT \
	"#include \"%s.h\"\n\n" \
	"int	main(int argc, char **argv)\n" \
	"{\n" \
	"	(void)argc;\n" \
	"	(void)argv;\n" \
	"	%s();\n" \
	"	return (0);\n" \
	"}\n"

#define PROJECT_C_CONTENT \
	"#include \"%s.h\"\n\n" \
	"int	%s(void)\n" \
	"{\n" \
	"	printf(\"This is the main logic of %s!\\n\");\n" \
	"	return (0);\n" \
	"}\n"

#define PROJECT_H_CONTENT \
	"#ifndef %s_H\n" \
	"# define %s_H\n\n" \
	"/* #include \"libft.h\" */\n" \
	"/* #include \"mlx.h\" */\n\n" \
	"#include <stdio.h>\n\n" \
	"/************** %s **************/\n" \
	"int %s(void);\n\n" \
	"#endif\n"

#define GITIGNORE_CONTENT \
    "# Compiled object files\n" \
    "*.o\n" \
	"*.d\n" \
	"obj/\n" \
    "*.obj\n\n" \
    "# Executables\n" \
    "*.exe\n" \
    "*.out\n" \
    "*.app\n\n" \
    "# Libraries\n" \
    "*.a\n" \
    "*.so\n" \
    "# Backup files\n" \
    "*~\n" \
    "*.bak\n\n" \
    "# CMake files\n" \
    "CMakeFiles/\n" \
    "CMakeCache.txt\n" \
    "cmake_install.cmake\n\n" \
    "# IDE specific files\n" \
    ".vscode/\n" \
    ".idea/\n" \
    "*.swp\n\n" \
    "*.log\n\n"


/***************** MAKE_GEN ******************/

#define MAKEFILE_DOC \
	"# 📄 Documentation:\n" \
	"# This Makefile is generated automatically by the Make My File program.\n" \
	"# It facilitates the compilation of C programs.\n" \
	"# For further details on Makefile usage, you can consult the official GNU Make documentation:\n" \
	"# https://www.gnu.org/software/make/manual/make.html \n" \
	"#\n" \
	"# 🔧 Variables:\n" \
	"# - NAME: Name of the executable or library to create.\n" \
	"# - SRCDIR: Directory where the source (.c) files are located.\n" \
	"# - OBJDIR: Directory where object files will be stored.\n" \
	"# - INCDIR: Directory containing header (.h) files for inclusion.\n" \
	"# - SRC: List of source files to compile.\n" \
	"# - OBJ: Object files generated from the source files.\n" \
	"# - CC: The compiler to use. Default is 'cc', but you can modify it if needed.\n" \
	"# - CFLAGS: Compilation flags (default includes warnings and debugging).\n" \
	"# - LDFLAGS: Linker flags (if any).\n" \
	"# - LIBS: Libraries to link against.\n" \
	"# - LIBFT_DIR: Directory where Libft is located.\n" \
	"# - MINILIBX_DIR: Directory where MiniLibX will be cloned automatically.\n" \
	"#\n" \
	"# 🚀 Rules:\n" \
	"# - 'make': Compiles the entire project by generating the executable defined in NAME.\n" \
	"# - 'make clean': Deletes only the compiled object (.o) files, keeping the executable.\n" \
	"# - 'make fclean': Deletes all generated files, including the executable and object files.\n" \
	"# - 'make re': Cleans (fclean) and then rebuilds the project from scratch.\n" \
	"# - 'make bonus': Compiles additional bonus source files if defined in the project.\n" \
	"# - 'make regen': Re-generates the Makefile if Make My File configuration has changed.\n" \
	"#\n" \
	"# 📚 Usage of Libft:\n" \
	"# - Default Directory: 'libft'.\n" \
	"# - If your Libft is located in a different directory, customize the 'LIBFT_DIR' variable in the Makefile accordingly.\n" \
	"# - Include the header in your source files: #include \"libft.h\"\n" \
	"# - Example usage: int result = ft_strlen(\"Hello\");\n" \
	"#\n" \
	"# 🖼️ Usage of MiniLibX:\n" \
	"# - MiniLibX will be cloned and included automatically. Choose this option during configuration.\n" \
	"# - Include the header in your source files: #include \"mlx.h\"\n" \
	"# - Example usage: mlx_init();\n" \
	"#\n" \
	"# 💡 Tips:\n" \
	"# - Use 'VERBOSE=1' when running make (e.g., 'make VERBOSE=1') to see detailed command outputs.\n" \
	"#\n" \
	"# Please report any bugs or suggestions at: https://github.com/MathysCogne/Make_My_File-42/issues\n\n"

#endif