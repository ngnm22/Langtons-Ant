references: https://www.educba.com/decimal-to-hexadecimal-in-c/

## Langton's Ant

![ant](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/CA3061-81k7.png/1024px-CA3061-81k7.png)

Langton's ant is a two-dimensional [universal Turing machine](https://web.mit.edu/manoli/turing/www/turing.html) that can demonstrate complex emergent behavior based on a very simple set of rules. First created by Chris Langton in 1986, Langton's ant runs on a square lattice of black and white cells. This project is an implementation of Langton's Ant in C.
## Background

The original Langton's ant progresses by colouring squares on a plane either black or white. One square is first determined to be the "ant" arbitrarily. This ant can then travel in any of the four cardinal directions at each iteration (step) of the game. The movement of the ant is controlled by the following simple rules:

* When at a white square, turn 90° clockwise, flip the color of the square to black and then move forward one unit.
* When at a black square, turn 90° counter-clockwise, flip the color of the square to white and then move forward one unit.

Following these rules, the ant will move in simple symmetric patterns for the first few hundred iterations of the game, after which chaotic irregular patterns of black and white squares appear. Towards the end, the ant will start steadily moving away from the starting location in a diagonal corridor about 10 cells wide. The ant can then be conceptually moving away infinitely.

An extension to Langton's Ant involves more general *n*-state ants. This is also known as the multi-colour version of Langton's Ant. The squares can be in states 1 through *n* and for each state (sometimes demonstrated with different colours), "L" or "R" is used to indicate whether a left or right turn is taken by the ant. For instance, in LRRRRRLLR, the ant will turn left on visiting squares in states 1, 7 and 8 and will turn right on squares in states 2, 3, 4, 5, 6 and 9. 

When the ant arrives at an "L" square, it turns left and when it arrives at an "R" square, it turns right. After the ant has left a square at state *i*, the square's state changes to *i+1*.

Further details of this can be found in the corresponding paper (https://arxiv.org/pdf/math/9501233.pdf).

## Visualiser

The repository already contains functionality for visualising the result using the [ncurses](https://en.wikipedia.org/wiki/Ncurses) library. In order to use it you need to link it at compile time using -lncurses.

All functions relating to visualisation are contained in visualiser.c and visualiser.h. For the generalisation you will need to add additional "colors" (may be represented as letters) to the visualiser.

- Pressing any key (except q) will advance the ant and pressing "q" will close the window.


MakeFile options:
    - all: create an executable called **ant** that takes the variant of the game (e.g. LLRR) as the input and runs the game.
    - library: compile the dynamically-linked library libant.so
    - clean: remove all executables and library files
    - test: manually run the tests in test


The assignment must be submitted by deadline, which is **2pm (UK time) on 7th February 2022**.

**Reminder**: You must commit and push your final changes before the deadline.

Note that late submissions will be penalized following departmental policy.
