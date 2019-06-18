#include <iostream>

#include "win_layouts.h"

#define GRID_ROWS 6
#define GRID_COLUMNS 7
#define PLACEHOLDER_POSITION '*'
#define HEADER "1 2 3 4 5 6 7"

char players[2] = {'x', 'o'};
char currentPlayer;
char grid[GRID_ROWS][GRID_COLUMNS];

void initializeGrid();
void displayGrid();
const bool move(const int &column);
char *availablePosition(const int &column);
const bool available(const char &position);
void getPlayers();
const bool input();
const char &newPlayer();
const bool win();
const bool conformsToLayout(const bool layout[GRID_ROWS][GRID_COLUMNS]);
const bool gridIsFull();
int main();