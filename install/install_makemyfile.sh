#!/bin/bash

REPO_OWNER="MathysCogne"
REPO_NAME="Make_My_File-42"
EXECUTABLE_NAME="makemyfile"
INSTALL_DIR="/usr/local/bin"

BOLD="\033[1m"
ITALIC="\033[3m"
GREEN="\033[32m"
CYAN="\033[36m"
RED="\033[31m"
C_RESET="\033[0m"

# Root verif
if [ "$EUID" -ne 0 ]; then
	echo -e "${RED}\n\n⛔  Please run as root or use ${BOLD}sudo${C_RESET}${RED} to install the program.${C_RESET}"
	exit
fi

# Download latest version on GH
LATEST_RELEASE=$(curl -s -H "Accept: application/vnd.github.v3+json" \
	https://api.github.com/repos/$REPO_OWNER/$REPO_NAME/releases/latest | \
	grep -Po '"tag_name": "\K.*?(?=")')

if [ -z "$LATEST_RELEASE" ]; then
	echo -e "${RED}❌  Error: Could not retrieve the latest release version.${C_RESET}"
	exit 1
fi

echo -e "${GREEN}\n🚀  Downloading the latest version ($LATEST_RELEASE) of ${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${GREEN}...${C_RESET}\n"
curl -L -o "$EXECUTABLE_NAME" "https://github.com/$REPO_OWNER/$REPO_NAME/releases/download/$LATEST_RELEASE/$EXECUTABLE_NAME"

chmod +x "$EXECUTABLE_NAME"

# Move to directory install
echo -e "${GREEN}\n💾  Installing ${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${GREEN} to ${BOLD}${CYAN}$INSTALL_DIR${C_RESET}${GREEN}...${C_RESET}"
mv "$EXECUTABLE_NAME" "$INSTALL_DIR"

if [ -f "$INSTALL_DIR/$EXECUTABLE_NAME" ]; then
	echo -e "${GREEN}✅  ${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${GREEN} installed successfully!${C_RESET}"
	echo -e "${ITALIC}🔍 To create your Makefile, run the command '${C_RESET}${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${ITALIC}' at the root of your project.${C_RESET}"
else
	echo -e "${RED}\n\n❌  Installation failed. Please check your permissions.${C_RESET}"
fi
