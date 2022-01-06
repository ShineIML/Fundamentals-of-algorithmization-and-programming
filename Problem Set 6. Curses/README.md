## Curses

The wording of the assignment

Use the library to ncurses create any program (game, presentation, or other work of art), and the resulting project must meet the following conditions:

    - The project must contain a 2D world.
    - Together, the project must include at least 3 of the following calls:
        -- Working with colors
        -- Keyboard control (no Entrom confirmation required)
        -- Multiple levels (levels)
        -- Working with a timer or. work in time (the program changes with time)
        -- Working with command line arguments
        -- Working with files
    - The project must be more complex than the demonstrations and its level must be sufficient.


Goals

   - Familiarize yourself with the ASCII-graphics library ncurses .
   - Show your creativity.
   - Learn to create assignment documentation.


## Usage

To compile the program you have to run your terminal and type:

  ```bash
  gcc firehouse.c -o firehouse -std=c11 -Werror -Wall -lm
  ```

To run the program:

  ```bash
  ./firehouse
  ```

## Dependencies

To compile the tasks, you need to have a copy of the `ncurses` library and `gcc-package`.