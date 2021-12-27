## Karel the Robot

Karel the robot is in general an educational programming language for beginners,
created by Richard E. Pattis. This is implementation of Karel the Robot for C
programming language. More info at https://en.wikipedia.org/wiki/Karel_(programming_language)


## Usage

Firstly, you need to install open source university API, called Karel the Robot to make project work properly.
https://git.kpi.fei.tuke.sk/kpi/karel-the-robot

To compile program you can use two different ways:
1.  Using Makefile:
```bash
make task
```
2.  Using command line in bash:
```bash
gcc -std=c11 -Werror -Wall -lsuperkarel -lcurses
```