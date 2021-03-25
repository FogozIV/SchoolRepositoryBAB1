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
int askNumber(string sentence, int min, int max, int tries=4);

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
void printMatrix(char matrix[NMAX][NMAX], int size);
/**
 * This function will print the message and ask the user to fill the tab
 * @param tab The tab that needs to be filled
 * @param size The size the user choosed 
 * @param message The message that will be printed 
 * @return This function will return the sum of all the elements that the user filled
 **/
template<typename T>
T askUserFillTabAndReturnSum(T tab[], int size, string message);

string askUserFillStringTab(string tab[], int size);
char askUserFillCharMatrix(char matrixChar[NMAX][NMAX], int size); 
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
			cout << "Au revoir ! " <<endl; 
			system("pause");
			return EXIT_SUCCESS;
		case 1:
			sumFloat = askUserFillTabAndReturnSum<float>(tabFloat, size, "Veuillez entrer " + to_string(size) + " nombres réels");
			printTab<float>(tabFloat, size);
			cout << "Et la somme est : " << sumFloat << endl;
			break;
		case 2:
			sumInt = askUserFillTabAndReturnSum<int>(tabInteger, size, "Veuillez entrer " + to_string(size) + " nombres entiers");
			printTab<int>(tabInteger, size);
			cout << "Et la moyenne est : " << (float)sumInt/size << endl;
			break;
		case 3:
			max = askUserFillStringTab(tabString, size);
			printTab<string>(tabString, size);
			cout << "Le maximum est : " << max << endl;
			break;
		case 4:
			min = askUserFillCharMatrix(matrixChar, size);
			printMatrix(matrixChar, size);
			cout << "Le plus petit caractere est : " << min << endl;
			break;
		default:
			cout << "[ERROR] Trop de tentative infructueuse !" <<endl;
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
		if(cin.fail()){
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Veuillez entrer un nombre !" <<endl;
			continue;
		}
		if (input >= min && input <= max) {
			return input;
		}
	}
	return ERROR_CODE;
}


string askUserFillStringTab(string tab[], int size) {
	string max = "";
	cout << "Veuillez remplir ce tableau de mots" << endl;
	for (int i = 0; i < size; i++) {
		cout << "tab[" << i << "] ?= ";
		cin >> tab[i];
		if (max == "" || max < tab[i]) {
			max = tab[i];
		}
	}
	return max;
}
char askUserFillCharMatrix(char matrix[NMAX][NMAX], int size){
	char min = SCHAR_MAX;
	for (int col = 0; col < size; col++) {
		for (int row = 0; row < size; row++) {
			cout << "tab[" << col << "]" << "[" << row << "]" << " ?= ";
			cin >> matrix[col][row];
			if (min > matrix[col][row]) {
				min = matrix[col][row];
			}
		}
	}
	return min;
}

template<typename T>
void printTab(T tab[], int size){
	for(int i = 0; i<size; i++){
		cout << "tab[" << i << "] = " << tab[i] << endl;
	}
}

void printMatrix(char matrixChar[NMAX][NMAX], int size){
	for(int col = 0; col< size; col++){
		for(int row = 0; row < size; row++){
			cout << matrixChar[col][row] << " ";
		}
		cout <<endl;
	}
}

template<typename T>
T askUserFillTabAndReturnSum(T tab[], int size, string message){
	T sum = 0;
	cout << message << endl;
	for (int i = 0; i < size; i++) {
		cout << "tab[" << i << "] ?= ";
		cin >> tab[i];
		sum += tab[i];
	}
	return sum;
}
