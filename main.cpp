#include "Game.h"

using namespace std;

Game::Game(const short rows, const short columns)
	: rows(rows)
	, columns(columns)
	, currentPlayer(red) {
		board = new Player[rows * columns];
		for (int i = 0; i < rows * columns; i++)
			board[i] = none;
	}

string Game::currentPlayerColor() {
	switch (currentPlayer) {
	case red:
		return "red";
	case black:
		return "black";
	case none:
		return "none";
	}
}

void Game::changePlayer() {
	currentPlayer = currentPlayer == red ? black : red;
}

bool Game::didWin() {
	return false;
}

bool Game::isFull() {
	for (int column = 0; column < columns; column++)
		if (board[column] == none)
			return false;
	return true;
}

Move Game::drop(const short column) {
	for (int row = rows - 1; row >= 0; row--) {
		Player &boardPosition = board[row * columns + column - 1];
		if (boardPosition == none) {
			boardPosition = currentPlayer;
			if (didWin())
				return won;
			else if (isFull())
				return full;
			else {
				changePlayer();
				return valid;
			}
		}
	}
	return invalid;
}

char Game::displayPosition(const short row, const short column) {
	return board[row * columns + column];
}

void Game::display() {
	for (int column = 1; column <= columns; column++)
		cout << "  " << column << ' ';
	cout << endl;
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++)
			cout << "| " << displayPosition(row, column) << ' ';
		cout << '|' << endl;
	}
}

int main() {
	system("clear");
	cout << "GRID SIZE" << endl << "Rows: ";
	short rows;
	cin >> rows;
	cout << "Columns: ";
	short columns;
	cin >> columns;
	system("clear");
	Game game(rows, columns);
	while (true) {
		game.display();
		cout << "Drop " << game.currentPlayerColor() << " into which column? ";
		short column;
		cin >> column;
		system("clear");
		switch (game.drop(column)) {
		case won:
			game.display();
			cout << endl << "Player " << game.currentPlayerColor() << " wins!" << endl << endl;
			return 0;
		case full:
			game.display();
			cout << endl << "It's a tie!" << endl << endl;
			return 0;
		default:
			break;
		}
	}
}