#!/bin/bash

REPO_OWNER="MathysCogne"
REPO_NAME="Make_My_File-42"
EXECUTABLE_NAME="makemyfile"
INSTALL_DIR="$HOME/.local/bin"

BOLD="\033[1m"
ITALIC="\033[3m"
GREEN="\033[32m"
CYAN="\033[36m"
RED="\033[31m"
C_RESET="\033[0m"

# Check if the installation directory exists
if [ ! -d "$INSTALL_DIR" ]; then
	mkdir -p "$INSTALL_DIR"
	echo -e "${GREEN}💾 Directory $INSTALL_DIR created for installation.${C_RESET}"
fi

# Download the latest version from GitHub
LATEST_RELEASE=$(curl -s -H "Accept: application/vnd.github.v3+json" \
	https://api.github.com/repos/$REPO_OWNER/$REPO_NAME/releases/latest | \
	grep -Po '"tag_name": "\K.*?(?=")')

if [ -z "$LATEST_RELEASE" ]; then
	echo -e "${RED}❌  Error: Could not retrieve the latest release version.${C_RESET}"
	exit 1
fi

# Check if the download was successful
echo -e "\n🚀  Downloading the latest version ${BOLD}${CYAN}[$LATEST_RELEASE] of ${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${GREEN}...${C_RESET}\n"
curl -L -o "$EXECUTABLE_NAME" "https://github.com/$REPO_OWNER/$REPO_NAME/releases/download/$LATEST_RELEASE/$EXECUTABLE_NAME"
if [ $? -ne 0 ]; then
	echo -e "${RED}❌  Error: Download failed. Please check your network connection.${C_RESET}"
	exit 1
fi

chmod +x "$EXECUTABLE_NAME"

# Move the executable to the installation directory
echo -e "\nInstalling $EXECUTABLE_NAME to ${ITALIC}$INSTALL_DIR...${C_RESET}"

mv "$EXECUTABLE_NAME" "$INSTALL_DIR"

if [ -f "$INSTALL_DIR/$EXECUTABLE_NAME" ]; then
	echo -e "${GREEN}✅  $EXECUTABLE_NAME installed successfully!\n${C_RESET}"
	echo -e "${GREEN}🔍 To create your Makefile, run the command '${C_RESET}${BOLD}${CYAN}$EXECUTABLE_NAME${C_RESET}${GREEN}${BOLD}' at the root of your project.${C_RESET}"
else
	echo -e "${RED}\n\n❌  Installation failed. Please check your permissions.${C_RESET}"
	exit 1
fi

# Add ~/bin to PATH if it is not already there
if [[ ":$PATH:" != *":$INSTALL_DIR:"* ]]; then
	echo "export PATH=\$PATH:$INSTALL_DIR" >> "$HOME/.bashrc"
	echo -e "${ITALIC}💡 $INSTALL_DIR added to PATH. Please run ${BOLD}${CYAN}'source ~/.bashrc' ${C_RESET}${ITALIC}for changes to take effect.${C_RESET}"
fi
