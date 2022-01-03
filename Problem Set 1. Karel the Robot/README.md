## Karel the Robot

Karel the robot is in general an educational programming language for beginners,
created by Richard E. Pattis. 

This is implementation of [Karel the Robot for C
programming language](https://en.wikipedia.org/wiki/Karel_(programming_language)).


## Usage

First, you need to install an open source university [API](https://git.kpi.fei.tuke.sk/kpi/karel-the-robot) called Karel the Robot into your OS.


You can use two different ways to compile a program:
1. Using Makefile:
  ```bash
  make *
  ```
2. Using command line in bash:
  ```bash
  gcc *.c -o * -std=c11 -Werror -Wall -lsuperkarel -lcurses
  ```
`*` is the name of the task.

## Dependencies

To compile the tasks, you need to have a copy of the `ncurses` library and `gcc-package`.


