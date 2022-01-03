/*

    Task 6: Pirate Treasure

    Robot Karel set out again to look for treasure. This time he has a blind map with numbers. The rules are as follows:

    Karel is still going straight in the direction of his turn
    Karel will change direction if he finds the brand (s):
        1 means turning north
        2 means turning west
        3 means turning south
        4 means turning east
        5 means treasure
    On the way, Karel collects all the brands he finds
    If Charles finds the treasure, he picks it up and stops

*/

#include <superkarel.h>
#define SPEED 50

void turn_right();
void face_north();
void face_east();
void face_south();
void face_west();
void go_find_treasure();


int main(){

    turn_on("pirate.kw");
    set_step_delay(SPEED);
    
    go_find_treasure();
    
    turn_off();
    return 0;
}

void turn_right() {
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
    turn_left();
}

void face_north() {
    while( not_facing_north() ) {
        turn_left();
    }
}

void face_east() {
    while( not_facing_east() ) {
        turn_left();
    }
}
void face_south() {
    while( not_facing_south() ) {
        turn_left();
    }
}

void face_west() {
    while( not_facing_west() ) {
        turn_left();
    }
}

/*

    The main function of the program, which will first go straight until it steps on the condition, 
    has an implicit counter implemented in the function using 5 ifs. For example, in the first case, 
    we will step on the number 4, which means that it will pass 4 ifs, in each of which, Karel will pick up one beeper and turn in one direction.
    After all the turns, Karel will continue on his way to the next condition. And only when he reaches the 5th if, he will finish his search.

*/
void go_find_treasure() {
    while( front_is_clear() && no_beepers_present() ) {
        step();
        if( beepers_present() ) {
            pick_beeper();
            face_north();
        }
        if( beepers_present() ) {
            pick_beeper();
            face_west();
        }
        if( beepers_present() ) {
            pick_beeper();
            face_south();
        }
        if( beepers_present() ) {
            pick_beeper();
            face_east();
        }
        if( beepers_present() ) {
            pick_beeper();
            break;
        }
    }
}
