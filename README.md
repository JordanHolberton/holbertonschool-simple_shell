# holbertonschool-simple_shell

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## List of allowed functions and systems calls+

    all functions from string.h
    - `access` (man 2 access)
    - `chdir` (man 2 chdir)
    - `close` (man 2 close)
    - `closedir` (man 3 closedir)
    - `execve` (man 2 execve)
    - `exit` (man 3 exit)
    - `_exit` (man 2 _exit)
    - `fflush` (man 3 fflush)
    - `fork` (man 2 fork)
    - `free` (man 3 free)
    - `getcwd` (man 3 getcwd)
    - `getline` (man 3 getline)
    - `getpid` (man 2 getpid)
    - `isatty` (man 3 isatty)
    - `kill` (man 2 kill)
    - `malloc` (man 3 malloc)
    - `open` (man 2 open)
    - `opendir` (man 3 opendir)
    - `perror` (man 3 perror)
    - `printf` (man 3 printf)
    - `fprintf` (man 3 fprintf)
    - `vfprintf` (man 3 vfprintf)
    - `sprintf` (man 3 sprintf)
    - `putchar` (man 3 putchar)
    - `read` (man 2 read)
    - `readdir` (man 3 readdir)
    - `signal` (man 2 signal)
    - `stat` (__xstat) (man 2 stat)
    - `lstat` (__lxstat) (man 2 lstat)
    - `fstat` (__fxstat) (man 2 fstat)
    - `strtok` (man 3 strtok)
    - `wait` (man 2 wait)
    - `waitpid` (man 2 waitpid)
    - `wait3` (man 2 wait3)
    - `wait4` (man 2 wait4)
    - `write` (man 2 write)

## Remarks

This simple shell is not a real shell. If you wanna go deep for real shell, go KERNEL

## Task 0

Write a - `README`
Write a man for your shell.
You should have an - `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository.

## Task 1

Write a beautiful code that passes the Betty checks

## Task 2

Write a - `UNIX` command line interpreter.

    Usage: simple_shell
Your Shell should:

    Display a prompt and wait for the user to type a command. A command line always ends with a new line.
    The prompt is displayed again each time a command has been executed.
    The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
    The command lines are made only of one word. No arguments will be passed to programs.
    If an executable cannot be found, print an error message and display the prompt again.
    Handle errors.
    You have to handle the (end of file) condition (Ctrl+D)

You dont have to:

    use the - `PATH`
    implement built-ins
    handle special characters : ", ', `, \, *, &, #
    be able to move the cursor
    handle commands with arguments

execve will be the core part of your Shell, dont forget to pass the environ to it

## Task 3

Simple shell 0.1 +

    Handle command lines with arguments

## Task 4

Simple shell 0.2 +

    Handle the - `PATH`
    fork must not be called if the command doesnt exist

## Task 5

Simple shell 0.3 +

    Implement the exit built-in, that exits the shell
    Usage: - `exit`
    You dont have to handle any argument to the built-in exit

## Task 6

Simple shell 0.4 +

    Implement the env built-in, that prints the current environment

## Task 9 

Simple shell 0.1 +

    Write your own getline function
    Use a buffer to read many chars at once and call the least possible the read system call
    You will need to use static variables
    You are not allowed to use getline

You dont have to:

    be able to move the cursor

## Task 10

Simple shell 0.2 +

    You are not allowed to use strtok

## Task 11

Simple shell 0.4 +

    handle arguments for the built-in exit
    Usage: exit status, where status is an integer used to exit the shell

## Task 12

Simple shell 0.4 +

    Handle Ctrl+C: your shell should not quit when the user inputs ^C

man 2 signal.

## Task 13

Simple shell 1.0 +

Implement the setenv and unsetenv builtin commands

   - `setenv`
        Initialize a new environment variable, or modify an existing one
        Command syntax: setenv VARIABLE VALUE
        Should print something on stderr on failure
   - `unsetenv`
        Remove an environment variable
        Command syntax: unsetenv VARIABLE
        Should print something on stderr on failure

## Task 14

Simple shell 1.0 +

Implement the builtin command - `cd`:

    Changes the current directory of the process.
    Command syntax: cd [DIRECTORY]
    If no argument is given to cd the command must be interpreted like cd $HOME
    You have to handle the command cd -
    You have to update the environment variable PWD when you change directory

man - `chdir`, man - `getcwd`

## Task 15

Simple shell 1.0 +

    Handle the commands separator - `;`

## Task 16

Simple shell 1.0 +

    Handle the - `&&` and - `||` shell logical operators

## Task 17

Simple shell 1.0 +

    Implement the alias builtin command
    Usage: alias [name[='value'] ...]
        alias: Prints a list of all aliases, one per line, in the form name='value'
        alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
        alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

## Task 18

Simple shell 1.0 +

    Handle variables replacement
    Handle the - `$?` variable
    Handle the - `$$` variable

## Task 19

Simple shell 1.0 +

    Handle comments - `(#)`

## Task 20

Simple shell 1.0 +

    Implement the help built-in
    Usage: help [BUILTIN]

## Task 21

Simple shell 1.0 +

    Implement the history built-in, without any argument
    The history built-in displays the history list, one command by line, preceded with line numbers (starting at 0)
    On exit, write the entire history, without line numbers, to a file named .simple_shell_history in the directory $HOME
    When the shell starts, read the file .simple_shell_history in the directory $HOME if it exists, and set the first line number to the total number of lines in the file modulo 4096

## Task 22

Simple shell 1.0 +

    Usage: simple_shell [filename]
    Your shell can take a file as a command line argument
    The file contains all the commands that your shell should run before exiting
    The file should contain one command per line
    In this mode, the shell should not print a prompt and should not read from stdin

