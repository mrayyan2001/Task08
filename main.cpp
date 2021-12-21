#include <iostream>
#include"Josephus.h"
using namespace std;

int main() {
	Josephus game;

	game.startGame(5,6);
	game.startGame(5,1);
	game.startGame(5,2);
	game.startGame(1,2);
	game.startGame(0,2);

	return 1;
}