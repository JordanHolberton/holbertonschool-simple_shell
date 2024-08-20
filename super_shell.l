.TH SUPER_SHELL 1 "2023-10-01" "1.0" "Super Shell User Manual"
.SH NAME
super_shell \- A simple UNIX command interpreter
.SH SYNOPSIS
.B super_shell
.SH DESCRIPTION
.B super_shell
is a simple UNIX command interpreter that replicates the basic functionalities of the standard shell (sh). It is designed to execute commands read from standard input or from a file.
.SH OPTIONS
.B super_shell
does not currently support any command-line options.
.SH USAGE
To start the shell, simply run the executable:
.PP
.B ./super_shell
.PP
Once the shell is running, you can enter commands just as you would in a standard shell.
.SH EXAMPLES
.PP
.B $ ./super_shell
.PP
.B super_shell$ ls
.PP
.B super_shell$ echo "Hello, World!"
.SH FILES
The source code for
.B super_shell
is available on GitHub at:
.PP
.UR https://github.com/JordanHolberton/holbertonschool-simple_shell/tree/David-branch
.SH AUTHORS
.B simple_shell
was developed by David and Jordan Holberton from Holberton School Toulouse C24.
.SH BUGS
Report bugs to the project's issue tracker on GitHub:
.PP
.UR https://github.com/JordanHolberton/holbertonschool-simple_shell/issues
.SH SEE ALSO
sh(1), bash(1)
.SH COPYRIGHT
Copyright (C) 2024 David and Jordan from Holberton School Toulouse C24. All rights reserved.

