# Make My File
&nbsp;

### ⚠️ This project is in beta testing.
### Please report any bugs you find on Discord (@mrmilkshakes) or GitHub!
&nbsp;

**Make My File** is a fully automated Makefile generator for C projects, optimized for 42 school.

Run the executable in your project directory and follow the prompts in the console GUI.

&nbsp;

## Features

- Auto-detect source files, headers and bonus files, including in subdirectories.
- Detect C project structure and Create project structure automatically if not present, including:
	- main.c, name_app.c, and name_app.h
	- Directories: include/ and src/
	- A corresponding Makefile
	- A .gitignore file for c project

- Link against the `libft` library (42).
- Include and auto-download `MiniLibX` library (42).
- Create object directories and dependency files.

&nbsp;

## Disclaimer

While **Make My File** automates Makefile generation, knowing how to create one manually is essential, especially during 42 school pool sessions.


&nbsp;

## Installation

1. Run the installer script: (Note: Script work on Linux and macOS.)
```bash
sudo bash -c "$(curl -L https://github.com/MathysCogne/Make_My_File-42/releases/download/1.2.3/install_makemyfile.sh)"
```

&nbsp;

2. To create a Makefile, navigate to the root of your project and run:
```bash
makemyfile
```

Tip: If you don’t have a project structure yet (meaning there are no .c files in the directory), the app will offer to create one for you. It's a great way to save time if you want to get started quickly!

&nbsp;

3. Follow the on-screen instructions.

![Screen](screenshots/screen.gif)

&nbsp;

## Contributing

Contributions are welcome! Feel free to submit a pull request or open an issue for suggestions.

&nbsp;
