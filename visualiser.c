#include <ncursesw/ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"
// wrap around boundary torus 
#define cell_at(y,x) cells[((((y)%(max_y))+max_y)%max_y)*max_x + ((((x)%(max_x))+max_x)%max_x)]  // Modify for correct boundary behaviour
#define cell_under_ant cell_at(ant->y, ant->x)
cell *cells;
// turn length into hexadecimal so it prints unique items for very large strings
int hexa_num(long int quotient){
	int a = 1 , b , var;
	char hexanum_decimal[ 100 ] ;
	while( quotient != 0 ) {
		var = quotient % 16 ;
	if( var < 10 )
		var = var + 48 ;
	else
		var = var + 55 ;
		hexanum_decimal[ a++ ]= var ;
		quotient = quotient / 16;
	}
	for ( b = a -1 ; b > 0 ; b-- ){
		char jo =  hexanum_decimal[ b ];
		return jo ;
	}
return 0 ;
}
//colours number alowed with ncurses
#define N_COLOR_PAIRS 8 

static int max_x;
static int max_y;


void start_visualisation(struct ant* ant, char* r) {
    setlocale(LC_ALL, "");

    initscr();
    start_color();
    curs_set(FALSE);
    max_x = getmaxx(stdscr);
    max_y = getmaxy(stdscr);
    cells = calloc(max_y * max_x, sizeof(int));
	if(r != NULL)
	{
		set_rules(r);
	}
    ant->x = max_x / 2;
    ant->y = max_y / 2;
    ant->direction = RIGHT;
}

void visualise_and_advance(struct ant* ant) {
    /* Draw cells and ant */
    //colour pairs
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(7, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    init_pair(6, COLOR_BLACK, COLOR_BLUE);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    for (int y = 0; y < max_y; y++)
    {
        for (int x = 0; x < max_x; x++)
        {
            if (ant_is_at(y, x))
	    {
		//refresh square to change colour
		attron(COLOR_PAIR(1));
	        mvprintw(y, x,direction_to_s(ant->direction));
	    }
            else
            {
		if(cell_at(y,x) == BLACK)
		{
			mvprintw(y, x,"█");
		}
		else{
			//set new square/colour
                	int g = cell_at(y,x);
                	// set the color of the output                
			int pair = (g%N_COLOR_PAIRS) + 1;
                	attron(COLOR_PAIR(pair));
			//character being output
                	char s[2]; //character + empty
			if ((g/N_COLOR_PAIRS) < 63)
				if ((g/N_COLOR_PAIRS) > 0){
					s[0] = (char)(g/N_COLOR_PAIRS+64);
				}
				else 
					s[0] = ' ';
			else{
				s[0] = hexa_num(g/N_COLOR_PAIRS);
			}
			
                	s[1] = '\0';
			mvprintw(y, x,s);
		}

            }
        }
    }
    refresh();

    /* Advance to next step */
    apply_rule(&cell_under_ant, ant);
    move_forward(ant);
}

// Check if the user has input "q" to quit
bool not_quit() {
    return 'q' != getch();
}

void end_visualisation() {
    free(cells);
    endwin();
}
