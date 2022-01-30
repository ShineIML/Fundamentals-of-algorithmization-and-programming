#include <superkarel.h>
#define SP_NULL 0
#define SP 60

void turn_right();
void pick_all();
void find_south_east();
bool facing_vertical();
void climb_stairs();
void olympics();
void divide_even_beepers();
bool no_beepers();
void turn_to_south();
void mark_empty_line();
void chessboard();
void x_mas();


int main () {
//	turn_on("r_climb.kw");
//	turn_on("r_olympics.kw");
	turn_on("x_mas.kw");
//	turn_on("x_mas2.kw");
	set_step_delay(SP);
//	climb_stairs();
//	olympics();
//	divide_even_beepers();
//	chessboard();
	x_mas();
	turn_off();
	return 0;
}

void x_mas() {

	while(left_is_clear()) {
		step();
		if(left_is_blocked()) {
			turn_left();
			turn_left();
			step();
			turn_right();
			step();
			turn_right();
			break;
		}
	}

	while(left_is_clear() && front_is_clear()) {
		step();
		if(right_is_clear()) {
			put_beeper();
			put_beeper();
			step();
			turn_right();
			while(front_is_clear()) {
				step();
			}
			turn_left();
			put_beeper();
			break;
		}
		if(front_is_blocked() && facing_east() && left_is_clear()) {
			put_beeper();
			turn_left();
			step();
			turn_right();
		}
		if(left_is_blocked() && right_is_blocked()) {
			turn_left();
			turn_left();
			step();
			if(left_is_clear()) {
				turn_left();
				turn_left();
				step();
				turn_left();
				turn_left();
			}
			put_beeper();
			if(right_is_clear()) {
				turn_right();
			}
			step();
			turn_right();
		}
	}


	while(right_is_blocked()) {
		step();
		if(front_is_blocked()) {
			break;
		}
		if(right_is_clear()) {
			turn_left();
			turn_left();
			step();
			if(no_beepers_present()) {
				put_beeper();
				turn_left();
				turn_left();
			} else if(beepers_present()) {
				turn_left();
				turn_left();
				while(right_is_blocked()) {
					step();
				}
				turn_right();
				step();
				if(front_is_blocked()) {
					turn_left();
				}
			}
		}
	}


}

void chessboard() {

	while(1) {
		put_beeper();
		if(front_is_clear()) {
			step();
		}
		if(front_is_clear()) {
			step();
		} else if(front_is_blocked() && facing_east() && no_beepers_present()) {
			turn_left();
			if(front_is_blocked()) {
                turn_left();
                while(front_is_clear()) {
                    step();
                }
                turn_right();
                break;
            }
			step();
			put_beeper();
			turn_left();
			if(front_is_clear()) {
				step();
			}
			if(front_is_clear()) {
				step();
			}
		} else if(front_is_blocked() && facing_west() && no_beepers_present()) {
			turn_right();
			if(front_is_blocked()) {
				break;
			}
			step();
			put_beeper();
			turn_right();
			step();
			step();
		} else if(front_is_blocked() && facing_east() && beepers_present()) {
			turn_left();
			if(front_is_blocked()) {
				turn_left();
				while(front_is_clear()) {
					step();
				}
				turn_right();
				break;
			}
			step();
			turn_left();
			step();
			put_beeper();
			if(front_is_clear()) {
                step();
            }
            if(front_is_clear()) {
                step();
            }
		} else if(front_is_blocked() && facing_west() && beepers_present()) {
			turn_right();
			if(front_is_blocked()) {
				break;
			}
			step();
			turn_right();
			step();
			put_beeper();
			if(front_is_clear()) {
                step();
            }
            if(front_is_clear()) {
                step();
            }
		}
	}
}

void turn_right() {
	set_step_delay(SP_NULL);
	turn_left();
	turn_left();
	set_step_delay(SP);
	turn_left();

}

void pick_all() {
	while(beepers_present()) {
		pick_beeper();
	}
}

void find_south_east() {
	while(not_facing_south()) {
		turn_left();
	}
	while(front_is_clear()) {
		step();
	}
	while(not_facing_east()) {
		turn_left();
	}
	while(front_is_clear()) {
		step();
	}
}

bool facing_vertical() {
	if(facing_north() || facing_south()) {
		return true;
	} else {
		return false;
	}
}

void climb_stairs() {
	while(front_is_blocked()) {
		turn_left();
		while(right_is_blocked()) {
			step();
		}
		turn_right();
		while(front_is_clear()) {
			step();
			if(right_is_clear()) {
				turn_left();
				turn_left();
				step();
				turn_left();
				turn_left();
				while(beepers_in_bag()) {
					put_beeper();
				}
				break;
			}
			while(beepers_present()) {
				pick_beeper();
			}
		}
	}
}


void olympics() {
	while(no_beepers_present()) {

		if(right_is_clear()) {
			turn_right();
		} else if (front_is_blocked() && left_is_clear()) {
			turn_left();
		} else if (front_is_blocked()) {
			turn_left();
			turn_left();
		}

		if(front_is_clear()) {
			step();
		}
	}
}


void divide_even_beepers() {
	while(front_is_clear() && no_beepers_present()) {
		step();
		while(beepers_present()) {
			pick_beeper();
		}
		turn_left();
		turn_left();
		while(front_is_clear()) {
			step();
		}
		while(beepers_in_bag()) {
			put_beeper();
		}
		turn_left();
		turn_left();
	}
	while(beepers_present()) {
		pick_beeper();
		pick_beeper();
		step();
		put_beeper();
		step();
		put_beeper();
		turn_left();
		turn_left();
		while(front_is_clear()) {
			step();
		}
		turn_left();
		turn_left();
	}
}

bool no_beepers() {
	if(no_beepers_present()) {
		return true;
	} else {
		return false;
	}
}

void find_center() {
	while(not_facing_north()) {
		turn_left();
	}
	while(front_is_clear()) {
		step();
	}
	while(not_facing_west()) {
		turn_left();
	}
	while(front_is_clear()) {
		step();
	}
	turn_left();
	put_beeper();
	step();

}

void turn_to_south() {
	while(not_facing_south()) {
		turn_left();
	}
}

void mark_empty_line() {
	while(front_is_clear()) {
		put_beeper();
		step();
	}
}
