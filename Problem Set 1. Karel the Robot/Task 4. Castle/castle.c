/*

    Task 4: Castle

    Karel was hired to help repair the damage caused to Castle. 
    So Karel has to repair a set of stone pillars (represented, of course, by brands), 
    in which some stones are missing. When the repairs are completed, all missing holes in the columns will be filled again.
    The columns are different heights and they are different distances from each other. 

*/

#include <superkarel.h>
#define SPEED 40
#define SPEED_EQUALS_NULL 0

void turn_right();
void double_left();
void repair();
void go_n_repair();

int main() {

    turn_on("castle.kw");
    set_step_delay(SPEED);

    go_n_repair();
    turn_off();
    return 0;
}

void turn_right() {
    set_step_delay(SPEED_EQUALS_NULL);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
    turn_left();
}

void double_left() {
    turn_left();
    turn_left();
}

void repair() {
    while(front_is_clear()) {
        step();
    }
    double_left();
    while (front_is_clear()) {
        if (!beepers_present()) {
            put_beeper();
        }
        step();
        if (no_beepers_present()) {
            put_beeper();
        }
    }
}

void go_n_repair() {
    while (front_is_clear()) {
        while (not_facing_north()) {
            turn_left();
        }
        while (front_is_clear()) {
            if (beepers_present()) {
                repair();
                turn_left();
                if (front_is_clear()) {
                    step();
                    if (front_is_clear()) {
                        turn_left();
                    }
                } else if (front_is_blocked() && facing_east() && right_is_blocked()) {
                    turn_off();
                }
                if (front_is_blocked() && facing_east() && right_is_blocked()) {
                    turn_off();
                }
            }
            if (front_is_clear()) {
                step();
            }
        }
        double_left();
        while (front_is_clear()) {
            step();
        }
        turn_left();
        if (front_is_clear()) {
            step();
        }
        if (front_is_blocked()) {
            turn_left();
        }
    }
}
