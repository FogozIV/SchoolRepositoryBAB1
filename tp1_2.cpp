// TP1_2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <time.h>
#include <iostream>
using namespace std;
int askUserNumberBetween(int min, int max);
bool mainLoop(int numberToFind);
int main()
{
	bool wantToPlay;
	int gamemode = 0;
	srand(time(0));
	do {
		wantToPlay = false;
		int number, numberToFind;
		/*numberToFind = askUserNumberBetween(1, 100);
		for (int i = 0; i < 100; i++)
			cout << endl;
			*/
		do {
			cout << "Quel mode de jeu voulez-vous jouer ? (0 pour infinité d'essai et 1 pour 5 essais max)" << endl;
			cin >> gamemode;
		} while (gamemode < 0 && gamemode > 1);
		numberToFind = 1 + rand() % 100;
		cout << "Un nombre a été choisis aléatoirement" << endl;
		if (gamemode) {
			bool win = false;
			int i;
			for (i = 1; i <= 5 && !win; i++) {
				cout << "Vous avez maintenant " <<  5 - i + 1<<" essai(s)" << endl;
				win = mainLoop(numberToFind);
			}
			if (win) {
				cout << "Bravo vous avez gagné en " << i - 1 << " essai(s)" << endl;
			}
			else {
				cout << "Vous avez perdu, malheureusement vous n'avez pas réussi à trouver le nombre : " << numberToFind << " en 5 essais" << endl;
			}
		}
		else {
			bool win = false;
			int tries = 0;
			cout << "Vous avez une infinité d'essai pour trouver le nombre" << endl;
			while (!win) {
				tries++;
				win = mainLoop(numberToFind);
			}

			cout << "Bravo vous avez gagné en " << tries << " essai(s)" << endl;
		}
		cout << "Voulez vous rejouer ? (Entrez 0 pour non ou tout autre chiffre pour oui)" << endl;
		cin >> wantToPlay;

	} while (wantToPlay);

	return EXIT_SUCCESS;
}

int askUserNumberBetween(int min, int max) {
	int input;
	do {
		cout << "Entrez un chiffre entre " << min << " et " << max << endl;
		cin >> input;
	} while (input < min || input > max);
	return input;
}
bool mainLoop(int numberToFind) {
	int number;
	cout << "Maintenant entrez votre supposition : " << endl;
	number = askUserNumberBetween(1, 100);
	if (number > numberToFind) {
		cout << " Votre chiffre est Trop grand \n";
	}
	else if (number == numberToFind) {
		cout << " Bravo c’est trouve \n";
		return true;
	}
	else {
		cout << " Votre chiffre est Trop petit \n";
	}
	return false;
}
