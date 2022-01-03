/*

    Task 2: Treasure in tunnel

    Robot Karel was given the task of searching for treasure in the tunnel. 
    For the robot world, the tunnel is spiral in shape and the road gradually turns to the left. 
    The treasure is found when the robot finds the mark. 
    The treasure (mark) does not have to be at the end of the tunnel, 
    but it can also be located in the middle of the alley, after finding the treasure, 
    Karel returns to the beginning of the tunnel to its starting position. 

*/


#include <superkarel.h>
#define SPEED 100
#define SPEED_EQUALS_NULL 0

void turn_right();
void turn_backwards();
void find_treasure();
void come_back();

int main() {
    turn_on("treasure.kw");
    set_step_delay(SPEED);

    find_treasure();
    come_back();

    turn_off();
    return 0;
}

/*
    Simple assisting function, that makes right turn from three left turns.
    And via using set_step_delay args we are making it non-visible on the field.
*/
void turn_right() {
    set_step_delay(SPEED_EQUALS_NULL);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
    turn_left();
}

/*
    Similar to previous function, now it uses two left turns to turn Karel backwards. 
*/
void turn_backwards() {
    set_step_delay(SPEED_EQUALS_NULL);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
}

/*
    A function that implements Karel's movement across the tunnel in search of treasure. 
    When it's found, Karel picks it up, turns around in the opposite direction and finishes the function.
*/
void find_treasure() {
    while (no_beepers_in_bag()) {
        if (beepers_present()) {
            pick_beeper();
            break;
        }
        if (front_is_clear()) {
            step();
        }
        if (front_is_blocked() && no_beepers_present()) {
            turn_left();
        }
    }
    turn_backwards();
}

/*
    A function that implements the reverse movement of Karl to exit the tunnel.
*/
void come_back() {
    while (beepers_in_bag()) {
        if (front_is_clear()) {
            step();
        }

        if (facing_west() && right_is_blocked() &&
        left_is_blocked() && front_is_blocked()) {
            turn_right();
            break;
        }
    
        if (front_is_blocked()) {
            turn_right();
        }
    }
}