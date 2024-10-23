# Makefile generated by Make My File: https://github.com/MathysCogne/Make_My_File-42

# Documentation:
# This Makefile is generated automatically by the Make My File program.
# It facilitates the compilation of C programs.
#
# Variables:
# - NAME: Name of the executable or library to create.
# - SRCDIR: Directory where source files are located.
# - OBJDIR: Directory where object files will be stored.
# - INCDIR: Directory containing header files.
# - SRC: List of source files to compile.
# - OBJ: List of object files generated from the source files.
# - CC: The compiler to use (default is 'cc').
# - CFLAGS: Compilation flags (default includes warnings and debugging).
# - LDFLAGS: Linker flags (if any).
# - LIBS: Libraries to link against.
#
# Rules:
# - 'make': Builds the project.
# - 'make clean': Removes object files.
# - 'make fclean': Removes all generated files including the executable.
# - 'make re': Cleans and rebuilds the project.
# - 'make bonus': Builds and includes bonus source files if they exist.
#
# Note: For bonus files, set the 'src_file_bonus' parameter in the configuration. (AUTOMATIC DETECTION COMING SOON!)
# Use 'VERBOSE=1' for detailed output during compilation.
#
# Please report any bugs or suggestions at: https://github.com/MathysCogne/Make_My_File-42/issues

NAME = MakeMyFile

SRCDIR = src
OBJDIR = obj
INCDIR = include

# Source Files
SRC = auto_detec.c make_gen.c print.c make_my_file.c main.c config.c utils.c 
OBJ = $(SRC:.c=.o)

SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ := $(addprefix $(OBJDIR)/, $(notdir $(OBJ)))

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3

# Linker Flags and Libraries
LDFLAGS = 
LIBS = 

# Colors
RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"

# Compilation mode (silent by default, set VERBOSE=1 to show commands)
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
  V := 
else
  V := @
endif

# All Rule
all: $(OBJDIR) $(NAME)

# Object Directory Rule
$(OBJDIR):
	$(V)mkdir -p $(OBJDIR) || true

# Dependency Files
DEPDIR = $(OBJDIR)/deps
DEP = $(OBJ:.o=.d)

$(DEPDIR):
	$(V)mkdir -p $(DEPDIR) || true

-include $(DEP)

# Compilation Rules
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	$(V)$(CC) $(CFLAGS) -MMD -c $< -o $@
# Linking Rule
$(NAME): $(OBJ)
	$(V)$(CC) $(OBJ) $(BONUS_OBJ) -o $@ $(LDFLAGS) $(LIBS)
	$(V)echo $(GREEN)"🤖 [$(NAME)] Executable created ✅"$(RESET)

# Clean Rules
clean:
	$(V)echo $(RED)"🗑️  CLEANING OBJS"$(RESET)
	$(V)rm -rf $(OBJDIR)
	$(V)rm -rf $(DEPDIR)

fclean: clean
	$(V)echo $(RED)"🔥 CLEANING ALL"$(RESET)
	$(V)rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus