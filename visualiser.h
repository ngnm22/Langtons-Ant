#ifndef visualiser_h
#define visualiser_h
//#include "libant.so"
#include "langton.h"
#include <stdbool.h>


typedef enum colour cell;
void setRules(char * r);
cell cell_under_ant(struct ant ant);
void start_visualisation();
void visualise_and_advance();
bool not_quit();
cell cell_at_fct(int y, int x);
void end_visualisation();

#endif
