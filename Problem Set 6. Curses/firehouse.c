#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#define LEN 78
#define R 23
#define TRUE 1
#define FALSE 0
#define UP 3
#define DOWN 2
#define RIGHT 5
#define LEFT 4

void dispMap(int x, int y, char map[R][LEN]);
void key_management(char map[R][LEN]);
void level1();
void level2();

int main(void){
  // activate the keypad to read from this terminal
  keypad(initscr(),TRUE);
  noecho();
  //don't show cursor
  curs_set(0);

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);
  WINDOW *win = newwin(yMax,xMax,0,0);
  box(win, 0, 0);
  wattron(win, COLOR_PAIR(4));
  mvwprintw(win, 0, 30, "LVL1(1)");
  mvwprintw(win, 0, 39, "LVL2(2)");
  mvwprintw(win, 0, 49, "About(3)");
  mvwprintw(win, 0, 58, "Quit(4)");
  wattroff(win, COLOR_PAIR(4));

  wattron(win, COLOR_PAIR(1));
  mvwprintw(win, 3, 30, "         )                       ");
  mvwprintw(win, 4, 30, "        ( _   _._                ");
  mvwprintw(win, 5, 30, "          |_|-'_~_`-._           ");
  mvwprintw(win, 6, 30, "       _.-'-_~_-~_-~-_`-._       ");
  mvwprintw(win, 7, 30, "   _.-'_~-_~-_-~-_~_~-_~-_`-._   ");
  mvwprintw(win, 8, 30, "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ");
  mvwprintw(win, 9, 30, "    |  []  []   []   []  [] |    ");
  mvwprintw(win, 10, 30, "    |           __    ___   |    ");
  mvwprintw(win, 11, 30,"  ._|  []  []  | .|  [___]  |_.  ");
  mvwprintw(win, 12, 30,"  |=|________()|__|()_______|=|  ");
  mvwprintw(win, 13, 30,"^^^^^^^^^^^^^^^ === ^^^^^^^^^^^^^");

  mvwprintw(win, 15, 25, " ______ _          _    _                      ");
  mvwprintw(win, 16, 25, "|  ____(_)        | |  | |                     ");
  mvwprintw(win, 17, 25, "| |__   _ _ __ ___| |__| | ___  _   _ ___  ___ ");
  mvwprintw(win, 18, 25, "|  __| | | '__| _ |  __  || _ || | | | __|| _ |");
  mvwprintw(win, 19, 25, "| |    | | | |  __| |  | | (_) | |_| |__ |  __|");
  mvwprintw(win, 20, 25, "|_|    |_|_|  |___|_|  |_||___| |__,_|___||___|");


  wattroff(win, COLOR_PAIR(1));

  keypad(win, TRUE);
  
  
  bool quit_pressed = false;
  char ch;
  while (ch != 'q') {
      if (quit_pressed == true) {
      	break;
      }
      ch = wgetch(win);
      switch (ch) {
        case '1':
          	wattron(win, COLOR_PAIR(1));
          	mvwprintw(win, 0, 30, "LVL1(1)");
          	wattroff(win, COLOR_PAIR(1));
          	level1();
          	break;
        case '2':
          	wattron(win, COLOR_PAIR(1));
          	mvwprintw(win, 0, 39, "LVL2(2)");
          	wattroff(win, COLOR_PAIR(1));
          	level2();
          	break;
        case '3':
          	wattron(win, COLOR_PAIR(2));
          	mvwprintw(win, 0, 49, "About(3)");
          	wattroff(win, COLOR_PAIR(2));
          	wattron(win, COLOR_PAIR(3));
          	mvwprintw(win, 2, 2,"The idea of the game is that you are in a burning house");
          	mvwprintw(win, 3, 2,"and you need to find all the valuables to save them from fire.");
          	mvwprintw(win, 4, 2,"You also have a life counter, if you step on fire 3 times, you will lose.");
          	mvwprintw(win, 5, 2,"                                                     ");
          	mvwprintw(win, 6, 2,"Controls:                                                              ");
          	mvwprintw(win, 7, 2,"(W/Upwards Arrow) move to the up.                                      ");
          	mvwprintw(win, 8, 2,"(S/Downwards Arrow) move to the down.                                      ");
          	mvwprintw(win, 9, 2,"(A/Leftwards Arrow) move to the left.                                      ");
          	mvwprintw(win, 10, 2,"(D/Rightwards Arrow) move to the right.                                      ");
          	mvwprintw(win, 11, 2,"                                                                        ");
          	mvwprintw(win, 12, 2,"FireHouse game was maded by student TUKE, FEI: Rabin Ihor 1.bc                      ");
          	mvwprintw(win, 13, 2,"                                                                        ");
          	mvwprintw(win, 14, 2,"                                                                        ");
          	wattroff(win, COLOR_PAIR(3));
          	break;
        case '4':
          	wattron(win, COLOR_PAIR(1));
          	mvwprintw(win, 0, 58, "Quit");
          	wattroff(win, COLOR_PAIR(1));
          	quit_pressed = true;
          	break;
          default:
          	break;
        }
    }

  endwin();
}


void level1() {
   // empty space to fill array to length of LEN
    char map[R][LEN]={"                                                                              ",
                      " ---------------------------------------------------------------------------- ", 
                      "|    @* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@ @        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@ @@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@        @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@         *@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@ @@@@@@@@@@ @                                                             *|",
                      "|@            @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@ @@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      " ---------------------------------------------------------------------------- ",    
                      "                                                                              ", 
                      "                                                                              ",
                      "                                                                              ", 
  };
  
  // activate the keypad to read from this terminal
  keypad(initscr(),TRUE);
  
  //don't show cursor
  curs_set(0);
  attron(COLOR_PAIR(1));
  key_management(map);
  getch();
  endwin();
}


void level2() {
   // empty space to fill array to length of LEN
   
    char map[R][LEN]={"                                                                              ",
                      " ---------------------------------------------------------------------------- ", 
                      "|                             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|                             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|  @@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|  @@@@@@@@@@ @*     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|        *@@@ @@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@@@ @@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|@@@@@@@@@@@@      @ @@@@@@@                                                 |",
                      "|@@@@@@@@@@@@@@@@@ @         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ |",
                      "|@@@@@@@@@@@@      @@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ |",
                      "|             @@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ |",
                      "| @@@@@@@@@@@@@@@@@@@@@@@@@@ @                                               |",
                      "| @@@@@@@@@@@@@@@@@@@@@@@@@@ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "| @@@@@@@@@@@@@@@@@@@@@@@@@@ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "| @@@@@@@@@@@@@@@@@@@@@@@@@@ @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "| @@@@@@@@@@@@@              @ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      "|                @@@@@@@@@@@@@ *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|",
                      " ---------------------------------------------------------------------------- ",    
                      "                                                                              ", 
                      "                                                                              ",
                      "                                                                              ", 
  };

  
  // activate the keypad to read from this terminal
  keypad(initscr(),TRUE);
  
  //don't show cursor
  curs_set(0);
  attron(COLOR_PAIR(1));
  key_management(map);

  getch();
  endwin();
}


void dispMap(int x, int y, char map[R][LEN]) {
  
  int row,col;
  
  // draw basic map
  for (row=0;row<R;row++) {
    for (col=0;col<LEN;col++) {
      mvaddch(row+1,col+1,map[row][col]);
    }
  }
  
  // cursor symbol
  attron(COLOR_PAIR(2));
  mvaddch(y+1,x+1,'~');
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(1));
  
}
 
   
//func for setting correct binds
void key_management(char map[R][LEN]) {

  char output[3];
  FILE *fp;
  // init x and y pos of the cursor
  int xPos=1;
  int yPos=2;
  int count = 0;
  int first_step = 0;
  bool obstacle_stepped = false;
  
  // input character init to null
  char c='\0';
  int lives = 3;
  
    
  while (c!='q' || c!='Q') {
    
    if (obstacle_stepped == true) {
    	break;
    }
    
    dispMap(xPos,yPos,map);
    // read a single character
    c=getch();
    // erase old position
    
    if (first_step == 0) {
    	mvaddch(yPos,xPos,'#');
    	first_step++;
    }
    // move cursor

    
    switch(c){
    case 'q':
    case 'Q':
      obstacle_stepped = true;
      break;
    case UP:
    case 'w':
    case 'W':
      if (map[yPos-1][xPos] == ' ') {
          yPos--;
      }
      else if (map[yPos-1][xPos] == '@') {
      	map[yPos-1][xPos] = ' ';
      	yPos--;
      	lives--;
      	if(lives == 0) {
      	    obstacle_stepped = true;
      	}
      }
      else if (map[yPos-1][xPos] == '*') {
      	map[yPos-1][xPos] = ' ';
      	yPos--;
      	count += 1;
      }
      break;
    case DOWN:
    case 's':
    case 'S':
      if (map[yPos+1][xPos] == ' ') {
        yPos++;
      }
      else if (map[yPos+1][xPos] == '@') {
      	map[yPos+1][xPos] = ' ';
      	yPos++;
      	lives--;
      	if(lives == 0) {
      	    obstacle_stepped = true;
      	}
      }
      else if (map[yPos+1][xPos] == '*') {
      	map[yPos+1][xPos] = ' ';
      	yPos++;
      	count += 1;
      }
      break;
    case LEFT:
    case 'a':
    case 'A':
      if (map[yPos][xPos-1] == ' ') {
        xPos--;
      }
      else if (map[yPos][xPos-1] == '@') {
      	map[yPos][xPos-1] = ' ';
      	xPos--;
      	lives--;
      	if(lives == 0) {
      	    obstacle_stepped = true;
      	}
      }
      else if (map[yPos][xPos-1] == '*') {
      	map[yPos][xPos-1] = ' ';
      	xPos--;
      	count += 1;
      }
      break;
    case RIGHT:
    case 'd':
    case 'D':
      if (map[yPos][xPos+1] == ' ') {
        xPos++;
      }
      else if (map[yPos][xPos+1] == '@') {
      	map[yPos][xPos+1] = ' ';
      	xPos++;
      	lives--;
      	if(lives == 0) {
      	    obstacle_stepped = true;
      	}
      }
      else if (map[yPos][xPos+1] == '*') {
      	map[yPos][xPos+1] = ' ';
      	xPos++;
      	count += 1;
      }
      break;
    }
    
    if (count == 3) {
    	attron(COLOR_PAIR(3));
    	mvprintw(1,2, "Congratulations!!! You win!!! Press double q to quit the game.");
    	attroff(COLOR_PAIR(3));
    	fp = fopen(output, "w");
    	putc('W', fp);
    	putc('I', fp);
    	putc('N', fp);
    	fclose(fp);
    	break;
    }
    else if(count != 3 && lives == 0){
    	attron(COLOR_PAIR(2));
    	mvprintw(1,2, "Sorry, you burned out :( Press double q to quit the game.");
    	attroff(COLOR_PAIR(2));
    	fp = fopen(output, "w");
    	putc('L', fp);
    	putc('S', fp);
    	putc('E', fp);
    	fclose(fp);
    	break;
    }
  }
}   