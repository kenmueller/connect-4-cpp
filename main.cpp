#include "main.h"

using namespace std;

void initializeGrid() {
	for (int row = 0; row < GRID_ROWS; row++)
		for (int column = 0; column < GRID_COLUMNS; column++)
			grid[row][column] = PLACEHOLDER_POSITION;
}

void displayGrid() {
	cout << HEADER << endl;
	for (int row = 0; row < GRID_ROWS; row++) {
		for (int column = 0; column < GRID_COLUMNS; column++)
			cout << grid[row][column] << ' ';
		cout << endl;
	}
}

const bool move(const int &column) {
	char *position = availablePosition(column);
	if (position == nullptr)
		return false;
	*position = currentPlayer;
	return true;
}

char *availablePosition(const int &column) {
	for (int row = GRID_ROWS - 1; row >= 0; row--)
		if (available(grid[row][column]))
			return &grid[row][column];
	return nullptr;
}

const bool available(const char &position) {
	return position == PLACEHOLDER_POSITION;
}

void getPlayers() {
	cout << "Player 1: ";
	cin >> players[0];
	cout << "Player 2: ";
	cin >> players[1];
	newPlayer();
}

const bool input() {
	cout << "Player " << currentPlayer << ": ";
	int column;
	cin >> column;
	return column >= 1 && column <= GRID_COLUMNS && move(column - 1);
}

const char &newPlayer() {
	currentPlayer = players[currentPlayer == players[0] ? 1 : 0];
	return currentPlayer;
}

const bool win() {
	for (int i = 0; i < WIN_LAYOUTS_COUNT; i++)
		if (conformsToLayout(winLayouts[i]))
			return true;
	return false;
}

const bool conformsToLayout(const bool layout[GRID_ROWS][GRID_COLUMNS]) {
	for (int row = 0; row < GRID_ROWS; row++)
		for (int column = 0; column < GRID_COLUMNS; column++)
			if (layout[row][column] && grid[row][column] != currentPlayer)
				return false;
	return true;
}

const bool gridIsFull() {
	for (int row = 0; row < GRID_ROWS; row++)
		for (int column = 0; column < GRID_COLUMNS; column++)
			if (grid[row][column] == PLACEHOLDER_POSITION)
				return false;
	return true;
}

int main() {
	system("clear");
	getPlayers();
	system("clear");
	initializeGrid();
	displayGrid();
	while (true) {
		cout << endl;
		const bool &validInput = input();
		system("clear");
		displayGrid();
		if (win()) {
			cout << endl << "Player " << currentPlayer << " wins!" << endl << endl;
			break;
		}
		if (gridIsFull()) {
			cout << endl << "It's a tie!" << endl << endl;
			break;
		}
		if (validInput)
			newPlayer();
	}
}