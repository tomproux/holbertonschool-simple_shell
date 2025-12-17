# TITLE #

Simple Shell

# DESCRIPTION #

The project consist to create a little shell with different fonctionality from several version of it

# ALLOWED EDITORS #

vi, vim, emacs

# DEVELOPPEMENT ENVIRONMENT #

1. All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
2. All your files should end with a new line

# REQUIREMENTS #

1. Your code should use the Betty style
2. Your shell should not have any memory leaks
3. No more than 5 functions per file
4. All your header files should be include guarded
5. Use system calls only when you need to

# OUTPUT #

Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh:

    julien@ubuntu:/# echo "qwerty" | /bin/sh
    /bin/sh: 1: qwerty: not found
    julien@ubuntu:/# echo "qwerty" | /bin/../bin/sh
    /bin/../bin/sh: 1: qwerty: not found

Same error with your program hsh:

    julien@ubuntu:/# echo "qwerty" | ./hsh
    ./hsh: 1: qwerty: not found
    julien@ubuntu:/# echo "qwerty" | ./././hsh
    ./././hsh: 1: qwerty: not found

# LIST OF ALLOWED FUNCTIONS AND SYSTEM CALLS+ #

all functions from string.h

access (man 2 access)

chdir (man 2 chdir)

close (man 2 close)

closedir (man 3 closedir)

execve (man 2 execve)

exit (man 3 exit)

_exit (man 2 _exit)

fflush (man 3 fflush)

fork (man 2 fork)

free (man 3 free)

getcwd (man 3 getcwd)

getline (man 3 getline)

getpid (man 2 getpid)

isatty (man 3 isatty)

kill (man 2 kill)

malloc (man 3 malloc)

open (man 2 open)

opendir (man 3 opendir)

perror (man 3 perror)

printf (man 3 printf)

fprintf (man 3 fprintf)

vfprintf (man 3 vfprintf)

sprintf (man 3 sprintf)

putchar (man 3 putchar)

read (man 2 read)

readdir (man 3 readdir)

signal (man 2 signal)

stat (__xstat) (man 2 stat)

lstat (__lxstat) (man 2 lstat)

fstat (__fxstat) (man 2 fstat)

strtok (man 3 strtok)

wait (man 2 wait)

waitpid (man 2 waitpid)

wait3 (man 2 wait3)

wait4 (man 2 wait4)

write (man 2 write)

# FLOWCHART # 

<img width="2613" height="1532" alt="mermaid-diagram-2025-12-16-160545" src="https://github.com/user-attachments/assets/318c4ed7-5a5b-4c2b-b49d-5fd117b7da8c" />

# COMPILATION #

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# TESTING #



# AUTHOR #

@ Tom Proux : https://github.com/tomproux

@ Denis Gavaud : https://github.com/Denis12306
