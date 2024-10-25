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
	"# include <stdio.h>\n\n" \
	"/************** %s **************/\n" \
	"int	%s(void);\n\n" \
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
	"#\n" \
	"# Variables:\n" \
	"# - NAME: Name of the executable or library to create.\n" \
	"# - SRCDIR: Directory where source files are located.\n" \
	"# - OBJDIR: Directory where object files will be stored.\n" \
	"# - INCDIR: Directory containing header files.\n" \
	"# - SRC: List of source files to compile.\n" \
	"# - OBJ: List of object files generated from the source files.\n" \
	"# - CC: The compiler to use (default is 'cc').\n" \
	"# - CFLAGS: Compilation flags (default includes warnings and debugging).\n" \
	"# - LDFLAGS: Linker flags (if any).\n" \
	"# - LIBS: Libraries to link against.\n" \
	"#\n" \
	"# Rules:\n" \
	"# - 'make': Builds the project.\n" \
	"# - 'make clean': Removes object files.\n" \
	"# - 'make fclean': Removes all generated files including the executable.\n" \
	"# - 'make re': Cleans and rebuilds the project.\n" \
	"# - 'make bonus': Builds and includes bonus source files if they exist.\n" \
	"# - 'make regen': Regenerates the Makefile \n" \
	"#\n" \
	"# Note: Use 'VERBOSE=1' for detailed output during compilation.\n" \
	"#\n" \
	"# Please report any bugs or suggestions at: https://github.com/MathysCogne/Make_My_File-42/issues\n\n"

#endif