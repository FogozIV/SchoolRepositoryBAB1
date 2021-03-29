#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

const int NMAX = 10, ERROR_CODE = -1;
/**
 * @param sentence The sentence that is printed everytime
 * @param min Minimum number
 * @param max Maximum number
 * @param tries default : 4 The maximum tries before return ERROR_CODE
 **/
int askNumber(string sentence, int min, int max, int tries = 4);

/**
 * Will print the tab value per value
 * @param tab a tab which can be of any type
 * @param size the size of the tab
 **/
template<typename T>
void printTab(T tab[], int size);
/**
 * Will print the matrix values row by row
 * @param matrix A matrix of char
 * @param size The size of the matrix selected by the user
 **/
template<typename T>
void printMatrix(T matrix[][NMAX], int size);

template<typename T>
void askUserFillTab(T tab[], int size, string message);

template<typename T>
void askUserFillMatrix(T matrix[][NMAX], int size, string message);

template<typename T>
void calculateColSum(T matrix[][NMAX], int tab[], int size);

template<typename T>
T calculateSum(T tab[], int size);

template<typename T>
T compare(T tab[], int size, T(*function)(T, T));

template<typename T>
T compare(T matrix[][NMAX], int size, T(*function)(T, T));

int main()
{
	int size, choix, tabInteger[NMAX], sumInt, matrixInteger[NMAX][NMAX];
	float tabFloat[NMAX], sumFloat;
	string tabString[NMAX], max;
	char matrixChar[NMAX][NMAX], min;
	while (1) {
		size = askNumber("Veuillez entrer un nombre entre 1 et " + to_string(NMAX), 1, NMAX);
		if (size == ERROR_CODE) {
			cout << "[ERROR] Trop de tentative infructueuse !" << endl;
			system("pause");
			return EXIT_FAILURE;
		}
		choix = askNumber("Que voulez-vous faire ?\n0. Quitter\n1. Calcul de la somme de N réels\n2. Calcul de la moyenne de N entiers \n3. Recherche du maximum de N string \n4. Recherche du minimum d’une matrice NxN de caractères\n5. Calcul de la somme des N entiers de chaque colonne d’une matrice.", 0, 5);
		switch (choix) {
		case 0:
			cout << "Au revoir ! " << endl;
			system("pause");
			return EXIT_SUCCESS;
		case 1:
			askUserFillTab<float>(tabFloat, size, "Veuillez entrer " + to_string(size) + " nombres reels");
			printTab<float>(tabFloat, size);
			cout << "Et la somme est : " << calculateSum<float>(tabFloat, size) << endl;
			break;
		case 2:
			askUserFillTab<int>(tabInteger, size, "Veuillez entrer " + to_string(size) + " nombres entiers");
			printTab<int>(tabInteger, size);
			cout << "Et la moyenne est : " <<(float)calculateSum<int>(tabInteger, size) / size << endl;
			break;
		case 3:
			askUserFillTab(tabString, size, "Veuillez remplir ce tableau de " + to_string(size) + " mots/caractères") ;
			printTab<string>(tabString, size);
			cout << "Le maximum est : " << compare<string>(tabString, size, [](string a, string b) -> string {if (a > b) return a; else return b; }) << endl;
			break;
		case 4:
			askUserFillMatrix<char>(matrixChar, size, "Veuillez remplir cette matrice de caractère");
			printMatrix<char>(matrixChar, size);
			cout << "Le plus petit caractere est : " << compare<char>(matrixChar, size, [](char a, char b) -> char {if (a > b) return b; else return a; }) << endl;
			break;
		case 5:
			askUserFillMatrix<int>(matrixInteger, size, "Veuillez remplir cette matrice d'entier. \nLe matrice est sous la forme matrix[row][col]");
			calculateColSum<int>(matrixInteger, tabInteger, size);
			printMatrix<int>(matrixInteger, size);
			printTab<int>(tabInteger, size);
			break;
		default:
			cout << "[ERROR] Trop de tentative infructueuse !" << endl;
			system("pause");
			return EXIT_FAILURE;
		}
	}
}


int askNumber(string sentence, int min, int max, int tries) {
	int input;
	for (int i = 0; i < tries; i++) {
		cout << sentence << endl;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Veuillez entrer un nombre !" << endl;
			continue;
		}
		if (input >= min && input <= max) {
			return input;
		}
	}
	return ERROR_CODE;
}



template<typename T>
void printTab(T tab[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "tab[" << i << "] = " << tab[i] << endl;
	}
}
template<typename T>
void printMatrix(T matrix[][NMAX], int size) {
	for (int col = 0; col < size; col++) {
		for (int row = 0; row < size; row++) {
			cout << matrix[col][row] << " ";
		}
		cout << endl;
	}
}

template<typename T>
void askUserFillMatrix(T matrix[][NMAX], int size, string message) {
	cout << message << endl;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			cout << "matrix[" << row << "][" << col << "] ?=";
			cin >> matrix[row][col];
		}
	}
}

template<typename T>
void calculateColSum(T matrix[][NMAX], int tab[], int size) {
	for (int col = 0; col < size; col++) {
		tab[col] = 0;
		for (int row = 0; row < size; row++) {
			tab[col] += matrix[row][col];
		}
	}
}
template<typename T>
void askUserFillTab(T tab[], int size, string message) {
	cout << message << endl;
	for (int i = 0; i < size; i++) {
		cout << "tab[" << i << "] ?= ";
		cin >> tab[i];
	}
}

template<typename T>
T calculateSum(T tab[], int size) {
	T sum = 0;
	for (int i = 0; i < size; i++) {
		sum += tab[i];
	}
	return sum;
}

template<typename T>
T compare(T tab[], int size, T(*function)(T, T)) {
	T comp = tab[0];
	for (int i = 1; i < size; i++) {
		comp = function(tab[i], comp);
	}
	return comp;
}

template<typename T>
T compare(T matrix[][NMAX], int size, T(*function)(T, T)) {
	T comp = matrix[0][0];
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			comp = function(matrix[row][col], comp);
		}
	}
	return comp;
}
