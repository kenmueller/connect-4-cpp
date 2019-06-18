#include "main.h"
#include "Player.h"
#include "Move.h"

class Game {
public:
	Game(const short rows, const short columns);
	
	Player *board;
	const short rows;
	const short columns;
	Player currentPlayer;

	std::string currentPlayerColor();
	void changePlayer();
	bool didWin();
	bool isFull();
	Move drop(const short column);
	char displayPosition(const short row, const short column);
	void display();
};