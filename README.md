# automaton
Conway's Game of Life 
The Game of Life was invented by John Conway in 1970. You can think of it as an example of a
zero-player game. On more scientific terms, it is known as a cellular automaton. The game
consists of a two-dimensional matrix, divided into cells. Each cell is either dead or alive at a
given generation. The game consists of a set of rules that describe how the cells evolve from
generation to generation. These rules calculate the state of a cell in the next generation as a
function of the states of its neighboring cells in the current generation. A cell’s neighbors are
those 8 cells vertically, horizontally, or diagonally adjacent to that cell. You can learn more
about Conway’s game of life here:
http://en.wikipedia.org/wiki/Conway’s_Game_of_Life
Conway’s set of rules are summarized as follows:
1. An alive cell with fewer than two alive neighbors dies in the next generation.
2. An alive cell with more than three alive neighbors also dies in the next generation.
3. An alive cell with exactly two or three alive neighbors stays alive in the next generation.
4. A dead cell with exactly three alive neighbors becomes alive in the next generation.
Even though the 2D world is suppose to be infinite, we will restrict it for this project to be a 10x10
matrix. Those neighbors of border cells which are outside the boundaries are assumed to be dead
and will never be alive even if they satisfy condition 4 above.
Each entry contains a cell that can be ALIVE or DEAD.
The program needs two arguments:
1. The number of generations
2. A filename of the file that contains the initial matrix. The format of the file is a 10x10
matrix of integers. Cells at each row are separated by a space. An alive cell is presented
by a 1, while a dead one is presented by a 0.
For example, the first generation above is presented in the file as (in the project it will be 10x10):
0 0 0 0 0
0 1 1 0 0
0 0 1 0 0
0 0 1 0 0
0 0 0 0 0
