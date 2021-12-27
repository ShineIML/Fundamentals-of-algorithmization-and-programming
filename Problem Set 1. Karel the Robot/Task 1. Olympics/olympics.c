#include <superkarel.h>
#define SPEED 100
#define SPEED_EQUALS_NULL 0

void turn_right();
void turn_backwards();
void check_position();
void find_checkpoint();
void find_exit_checkpoint();

int main() {
    turn_on("olympics.kw"); // Turn on the field map.
    set_step_delay(SPEED); // Assigning karel's speed on the field
    
    find_checkpoint(); // Function to find first checkpoint.
    find_exit_checkpoint(); // Function to find exit checkpoint.
    
    turn_off();
    return 0;
}

/*
    Just a simple assisting function, that makes right turn from three left turns.
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
    A function that checks the environment, and depending on it performs a turn in the right direction.
*/
void check_position() {
    if (no_beepers_in_bag()) {
        if (right_is_clear()) {
            turn_right();
        } else if (front_is_blocked() && left_is_clear()) {
            turn_left();
        } else if (front_is_blocked()) {
            turn_backwards();
        }
    } else {
        if (left_is_clear()) {
            turn_left();
        } else if (front_is_blocked() && right_is_clear()) {
            turn_right();
        } else if (front_is_blocked()) {
            turn_backwards();
        }
    }
}

/*
    A function that implements movement to the first control point and completes its execution by extracting a part from it.

    At the very beginning of the game, there is one thing in our backpack that we can manipulate and set conditions with it.
    Initially, in order to understand that this is the beginning and is the final checkpoint, it was decided to put it in its original place.
    After that, an algorithm was built for moving and searching for the next thing, provided that we do not have a checkpoint item in our backpack. 
    As soon as Karel finds the thing, the loop will end, checkpoint item will be taken and the function will finish its execution.
*/
void find_checkpoint() {
    put_beeper();
    while (no_beepers_in_bag()) {
        check_position();
        if (front_is_clear()) {
            step();
        }
        if (beepers_present()) {
            pick_beeper();
            turn_backwards();
        }
    }
}


/*
    A function that implements movement in the opposite direction to the final control point and completes its execution.

    After Karel has found the first checkpoint, he needs to find the final checkpoint, pick it up and finish the program.
    In this case, a similar algorithm was developed, only now, with the condition that Karl has a checkpoint thing in his backpack
*/
void find_exit_checkpoint() {
    while (beepers_in_bag()) {
        check_position();
        if (front_is_clear()) {
            step();
        }
        if (beepers_present()) {
            pick_beeper();
            while (not_facing_west()) {
                turn_right();
            }
            break;
        }
    }
}
