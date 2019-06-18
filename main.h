#include <iostream>

#include "win_layouts.h"

#define GRID_SIZE 4
#define PLACEHOLDER_POSITION '*'
#define HEADER "1 2 3 4"

char players[2] = {'x', 'o'};
char currentPlayer;
char grid[GRID_SIZE][GRID_SIZE] = {
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION,
	PLACEHOLDER_POSITION
};

void displayGrid();
const bool move(const int &column);
char *availablePosition(const int &column);
const bool available(const char &position);
void getPlayers();
const bool input();
const char &newPlayer();
const bool win();
const bool conformsToLayout(const bool layout[GRID_SIZE][GRID_SIZE]);
const bool gridIsFull();
int main();