# Simple Shell

> This UNIX shell can read, interpret, and execute commands. It handles the PATH variable, and supports the `env` and `exit` builtin commands

## Environment
Built and tested with Ubuntu 14.04 LTS

## Installing/ Getting Started
Clone this repository and compile:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
```

## Usage
Run shell with the executable:
```./shell```

Example commands: ```ls -la```, ```pwd```,  ```cat```, ```/bin/echo "hello"``` etc.

### Example
```
vagrant:simple_shell$ ./hsh
$ ls -l
total 116
-rw-rw-r-- 1 vagrant vagrant   241 Mar 18 22:00 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  4087 Mar 28 21:12 README.md
-rw-rw-r-- 1 vagrant vagrant  1020 Mar 28 21:09 appendcmd.c
-rw-rw-r-- 1 vagrant vagrant   307 Mar 28 21:09 checkbuiltins.c
-rw-rw-r-- 1 vagrant vagrant   707 Mar 28 18:55 checkpath.c
-rw-rw-r-- 1 vagrant vagrant   990 Mar 28 21:09 exit.c
-rw-rw-r-- 1 vagrant vagrant   870 Mar 28 18:55 findpathvar.c
-rw-rw-r-- 1 vagrant vagrant   245 Mar 28 18:55 free2pointer.c
-rw-rw-r-- 1 vagrant vagrant   282 Mar 28 18:55 freelist.c
-rw-rw-r-- 1 vagrant vagrant   443 Mar 28 18:55 helpers.c
-rw-rw-r-- 1 vagrant vagrant  1747 Mar 28 21:09 holberton.h
-rwxrwxr-x 1 vagrant vagrant 32434 Mar 28 21:09 hsh
-rw-rw-r-- 1 vagrant vagrant   717 Mar 28 18:55 launch.c
-rw-rw-r-- 1 vagrant vagrant   940 Mar 28 21:09 looper.c
-rw-rw-r-- 1 vagrant vagrant   803 Mar 28 18:06 man_simple_shell
-rw-rw-r-- 1 vagrant vagrant  1363 Mar 28 21:09 pathtolinkedlist.c
-rw-rw-r-- 1 vagrant vagrant   395 Mar 28 18:55 printenv.c
-rw-rw-r-- 1 vagrant vagrant  1391 Mar 28 18:55 printerror.c
-rw-rw-r-- 1 vagrant vagrant   389 Mar 28 21:09 prompt.c
-rw-rw-r-- 1 vagrant vagrant   257 Mar 28 18:55 shellmain.c
-rw-rw-r-- 1 vagrant vagrant  1650 Mar 28 18:55 tokenize.c
```
### Builtins
This shell supports the following built-in commands:
+ ```env``` - Prints current environmental variables
+ ```exit``` - Exit out of the shell

### Return Value
Shell will exit with the status of 0 unless otherwise specified.

## File Descriptions

|  **File**  |   **Description**   |
| ------------ | --------------------- |
| holberton.h | Contains the C standard library header files, and struct and function declarations |
| shellmain.c | Main function, prompt, and simple shell loop |
| tokenize.c | Parses user input into tokens |
| launch.c | Checks PATH for existing executable, checks for builtins, forks the process and executes commands |
| builtins.c | Custom exit and env builtins |
| findpathvar.c | Searchs for environmental variable string for the PATH name, returns executable path |
| pathtolinkedlist.c | Splits the PATH string into tokens, and converts tokens to linked list |
| free_memory.c | Functions to free memory |
| helpers.c | Helper functions |
| printerror.c | Prints error messages |




### Authors
* [**Germaine Balmania**](https://github.com/guccigerm)
* [**Mikaela Gurney**](https://github.com/Mikaelia)
* [**Victor Nguyen**](https://github.com/vmdn23)
