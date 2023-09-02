#include <stdlib.h>
#include "visualiser.h"
#include "langton.h"
int main(int argc, char** argv) {
    struct ant ant;

    // if the program is called without arguments we use a default rule RL
    char *rules = argc > 1 ? argv[1] : "RL";
    start_visualisation(&ant, rules);

    // Enter loop
    do {
        visualise_and_advance(&ant);
    }
    while (not_quit());

    end_visualisation();

    return 0;
}
