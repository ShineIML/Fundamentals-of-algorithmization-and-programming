## Karel the Robot

Karel the robot is in general an educational programming language for beginners,
created by Richard E. Pattis. 

This is implementation of [Karel the Robot for C
programming language](https://en.wikipedia.org/wiki/Karel_(programming_language)).

## Usage

First, you need to install an open source university [API](https://git.kpi.fei.tuke.sk/kpi/karel-the-robot) called Karel the Robot into your OS.

Also, you can build your own world map for some test-cases with [Karel Map Builder](http://karelmapbuilder.surge.sh/)

You can use two different ways to compile a program:

`*` is the name of the task, which is always referred to as the name of the file where the code is located.

1. Using Makefile:
  ```bash
  make *
  ```
2. Using command line in bash:
  ```bash
  gcc *.c -o * -std=c11 -Werror -Wall -lsuperkarel -lcurses
  ```
  
To run the program after compilation you need to type:
```bash
./*
```

## Dependencies

To compile the tasks, you need to have a copy of the `ncurses` library and `gcc-package`.


