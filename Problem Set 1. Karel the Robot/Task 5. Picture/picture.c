/*

    Task 5: Picture

    Robot Karel was given the task to frame the picture. 
    This can be achieved by the robot marking all four boundary walls of the world. 
    In addition, after completing the task, Karel moves to the center of the world. 

    Robot Karel starts at any position, turned at will, and has a sufficient number of marks in his backpack. 
    The dimensions of the world are always odd, the smallest size of the world is 3x3. 

*/

#include <superkarel.h>
#define SPEED 40
#define SPEED_EQUALS_NULL 0

void turn_right();
void double_left();
void turn_south();
void step_forward();
void to_begin();
void put_n_step();
void find_left_middlepoint();
void find_center();
void to_the_middleX();
void picture_func();

int main() {

    turn_on("picture.kw");
    set_step_delay(SPEED);

    picture_func();

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

void turn_south() {
    while(not_facing_south()) {
        turn_left();
    }
}

void step_forward() {
    while(front_is_clear()) {
        step();
    }
}

/*

    A function that moves Karel to the lower left corner for the correct start of the program.

*/
void to_begin() {
    turn_south();
    step_forward();
    turn_right();
    step_forward();
    double_left();
}

/*

    A function that runs along the edge of the picture and draws frames, 
    except for the left side of the square (for further search of the center of the picture).

*/
void put_n_step() {
    while (front_is_clear()) {
        if (no_beepers_present()) {
            put_beeper();
        }
        step();
        if (front_is_blocked() && facing_east()) {
            turn_left();
        } else if (front_is_blocked() && facing_north()) {
            turn_left();
        } else if (front_is_blocked() && facing_west()) {
            put_beeper();
        }
    }
}

/*

    A function that finds the center point along the left wall by passing along it.

*/
void find_left_middlepoint() {
    while (no_beepers_present()) {
        step();
        if (beepers_present()) {
            double_left();
            step();
            if (no_beepers_present()) {
                put_beeper();
            }
            step();
            if (beepers_present()) {
                double_left();
                step();
            }
        }
    }
}

/*

    This function searches for the center point by analogy with the previous function, 
    after the center point is found along the left wall, but now on the X axis, not Y.

*/
void find_center() {
    while (not_facing_east()) {
        turn_left();
    }
    step();
    find_left_middlepoint();
    while (front_is_clear()) {
        step();
        if (beepers_present() && front_is_clear()) {
            pick_beeper();
        } else if (beepers_present() && front_is_blocked()) {
            double_left();
            step();
            while (no_beepers_present()) {
                step();
            }
            if (front_is_clear()) {
                step();
                if (no_beepers_present()) {
                    double_left();
                    step();
                    pick_beeper();
                    while (not_facing_north()) {
                        turn_left();
                    }
                    turn_off();
                }
            }
            while (beepers_present() && front_is_clear()) {
                pick_beeper();
                step();
            }
            double_left();
            step();
            while (no_beepers_present()) {
                step();
            }
        }
    }
}

/*

    A function that combines subtasks into a single task

*/
void to_the_middleX() {
    turn_left();
    step();
    find_left_middlepoint();
}

/*

    A function that combines single tasks into a final function.

*/
void picture_func() {
    to_begin();
    put_n_step();
    to_the_middleX();
    find_center();
}
