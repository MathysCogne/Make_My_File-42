#!/bin/bash

REPO_OWNER="MathysCogne"
REPO_NAME="Make_My_File-42"
RELEASE_VERSION="1.1.0"
EXECUTABLE_NAME="makemyfile"
INSTALL_DIR="/usr/local/bin"

BOLD="\033[1m"
ITALIC="\033[3m"
GREEN="\033[32m"
CYAN="\033[36m"
RED="\033[31m"
C_RESET="\033[0m"

# User Root
if [ "$EUID" -ne 0 ]
	then echo -e "${RED}\n\n⛔  Please run as root or use ${BOLD}sudo${C_RESET}${RED} to install the program.${C_RESET}"
	exit
fi

# Download @latest version on gh
echo -e "${GREEN}\n🚀  Downloading the latest version of ${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${GREEN}...${C_RESET}\n"
curl -L -o "$EXECUTABLE_NAME" "https://github.com/$REPO_OWNER/$REPO_NAME/releases/download/$RELEASE_VERSION/$EXECUTABLE_NAME"

chmod +x "$EXECUTABLE_NAME"

# Move executable to install dir
echo -e "${GREEN}\n💾  Installing ${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${GREEN} to ${BOLD}${CYAN}$INSTALL_DIR${C_RESET}${GREEN}...${C_RESET}"
mv "$EXECUTABLE_NAME" "$INSTALL_DIR"

if [ -f "$INSTALL_DIR/$EXECUTABLE_NAME" ]; then
    echo -e "${GREEN}✅  ${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${GREEN} installed successfully!${C_RESET}"
	echo -e "${ITALIC}🔍 To create your Makefile, run the command '${C_RESET}${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${ITALIC}' at the root of your project.${C_RESET}"
else
    echo -e "${RED}\n\n❌  Installation failed. Please check your permissions.${C_RESET}"
fi