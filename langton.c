#include <string.h>
#include "langton.h"
#include <stdio.h>
char *rules; //RLRLRLs
int n_colors; // number of colors
// Set the ants direction so that it turns left
void turn_left(struct ant *ant) {
    if (ant->direction == UP)
        ant->direction = LEFT;
    else if (ant->direction == DOWN)
        ant->direction = RIGHT;
    else if (ant->direction == LEFT)
        ant->direction = DOWN;
    else if (ant->direction == RIGHT)
        ant->direction = UP;
}

// Set the ants direction so that it turns right
void turn_right(struct ant *ant) {
    if (ant->direction == UP)
        ant->direction = RIGHT;
    else if (ant->direction == DOWN)
        ant->direction = LEFT;
    else if (ant->direction == LEFT)
        ant->direction = UP;
    else if (ant->direction == RIGHT)
        ant->direction = DOWN;
}

// Actually move the ant forward based on it's current direction
// Should only be called after turn_left or turn_right
void move_forward(struct ant *ant) {
    if (ant->direction == UP)
        ant->y--;
    else if (ant->direction == DOWN)
        ant->y++;
    else if (ant->direction == LEFT)
        ant->x--;
    else if (ant->direction == RIGHT)
        ant->x++;
}

// Do not modify
const char *direction_to_s(enum direction d) {
   return UP   == d ? "^" :
          DOWN == d ? "v" :
          LEFT == d ? "<" :
          /* else */  ">" ;
}
void set_rules(char *r) {
    // the string of RLRLs
    rules = r;

    // number of colors is the length of the rules,
    n_colors = strlen(r);
}

// Call turn_left, or turn_right depending on the color of the current square,
// or in other words: apply the rule:
// * When at a white square, turn 90° clockwise, flip the color of the square to black and then move forward one unit.
// * When at a black square, turn 90° counter-clockwise, flip the color of the square to white and then move forward one unit.
void apply_rule(enum colour *colour, struct ant *ant) {
	//white goes to black, black goes to the next colour etc
	if (n_colors == 0){
		if(*colour == WHITE){
			turn_right(ant);
			*colour = BLACK;
		}
		else{
			turn_left(ant);
			*colour = WHITE;
		}
	}
	else{
				
    		if (rules[*colour] == 'R')
        		turn_right(ant);
    		else
        		turn_left(ant);
		if(rules[*colour+1] != '\0')
			*colour = (*colour + 1) % n_colors;
		else
			*colour = WHITE;
	}
}
