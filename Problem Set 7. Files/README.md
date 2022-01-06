## Files

Goals

  - Learn to work with command line arguments.
  - Acquire work with files.
  - Deal with specific limitations (when a simple problem is not that simple).

## Usage

To compile the program you have to run your terminal and type:

  ```bash
  gcc count_words.c -o count_words -std=c11 -Werror -Wall -lm
  ```
  and
  ```bash
  gcc every_second.c -o every_second -std=c11 -Werror -Wall -lm
  ```

To run the program:

  ```bash
  ./count_words bananas1.txt
  ```
  and
  ```bash
  ./every_second input.txt output.txt
  ```

## Dependencies

To compile the tasks, you need to have a `gcc-package`.