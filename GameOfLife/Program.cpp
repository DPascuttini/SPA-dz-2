#include <iostream>
#include <string>
#include <fstream>
#include "gameOfLife.h"
using namespace std;

int main() {
	gameOfLife the_game;

	bool dalje;
	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();

		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);

	return 0;
}