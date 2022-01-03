/*

    Task 3: Wardrobe

    Karel was warned by his wife to get her closet in order. In the columns of the map hang pieces of clothes that are hung on a hanger.
    Karel's task is to arrange things in the wardrobe so that they hang from the longest to the shortest in the direction from right to left. 
    Things can only hang on the hanger, and the wardrobe can contain partitions that can divide the hanger into several parts. 
    Karel returns to his original position after a successful wash. 

*/

#include <superkarel.h>
#define SPEED 100
#define SPEED_EQUALS_NULL 0

void turn_right();
void double_left();
void check_hanger();
void hanger_sort();

int main() {

	turn_on("wardrobe.kw");
	set_step_delay(SPEED);

	check_hanger();
	hanger_sort();

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

/*

    A function that runs the first cycle along the hangers and checks for parts of things, 
    if there are any, then Karel collects them and returns them in sorted form from right to left and returns to its original position,
    moving to the next level of the wardrobe (below).

*/
void check_hanger() {
 	while(front_is_clear()) {
		step();
		if(beepers_present()) {
			pick_beeper();
		}
		if(front_is_blocked() && facing_west()) {
			turn_left();
			step();
			turn_left();
			break;
		}
		if(front_is_blocked()) {
			double_left();
		}
		if(right_is_blocked() && beepers_in_bag()) {
			put_beeper();
		}
	}
}

/*

    The main sorting function, which is exactly the same as the last one, 
    will collect all the parts of things, but on the way back there will be a check of the previous level and the presence of things, 
    and not the hanger itself, as in the previous function. At the end of the algorithm, 
    the function will return Karl to his original position at the start of the program.

*/
void hanger_sort() {
	while(front_is_clear()) {
		step();
		if(beepers_present()) {
			pick_beeper();
		}
		if(front_is_blocked()) {
			double_left();
			break;
		}
	}
	while(front_is_clear()) {
		if(front_is_clear() && facing_west()) {
			turn_right();
			step();
			if(front_is_clear() && !beepers_present()) {
				double_left();
				step();
				turn_right();
				step();
				if(front_is_blocked() && facing_west() &&
					left_is_clear()) {
					turn_left();
					step();
					turn_left();
					hanger_sort();
				} else if(front_is_blocked() && facing_west() 
						  && left_is_blocked()) {
					turn_right();
					while(front_is_clear()) {
						step();
					}
					double_left();
					step();
					turn_left();
					step();
					if(right_is_blocked()) {
						double_left();
						step();
						turn_left();
						step();
						turn_left();
						turn_off();
					}
					else if(left_is_blocked()) {
						double_left();
						step();
						double_left();
						turn_off();
					}
				}
			}
			if(beepers_present()) {
				double_left();
				step();
				if(beepers_in_bag()) {
					put_beeper();
				}
				turn_right();
				step();
				if(front_is_blocked() && facing_west()) {
					turn_left();
					step();
					turn_left();
					hanger_sort();
				}
			} else if(no_beepers_present() && facing_north()) {
				double_left();
				step();
				turn_right();
				step();
				if(front_is_blocked() && facing_west()) {
					turn_left();
					step();
					turn_left();
					hanger_sort();
				}
			}
		}
	}
}
