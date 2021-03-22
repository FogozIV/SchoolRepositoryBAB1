// TP2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>

using namespace std;
int askNumber(string sentence, int min, int max, int tries=4);
void printTab(int tab[], int size);
int askUserFillTab(int tab[], int size);
string askUserFillStringTab(string tab[], int size);
const int ERROR_CODE = -1;
int main()
{
	const int NMAX = 10;
	int size, choix, tabInteger[NMAX], sum, matrixInteger[NMAX][NMAX];
	string tabString[NMAX], max;
	char matrixChar[NMAX][NMAX], min;
	while (1) {
		size = askNumber("Veuillez entrer un nombre entre 1 et " + to_string(NMAX), 1, NMAX);
		if (size == ERROR_CODE) {
			cout << "[ERROR] Trop de tentative infructueuse" << endl;
			return EXIT_FAILURE;
		}
		choix = askNumber("Que voulez-vous faire ?\n0. Quitter\n1. Calcul de la somme de N réels\n2. Calcul de la moyenne de N entiers \n3. Recherche du maximum de N string \n4. Recherche du minimum d’une matrice NxN de caractères\n5. Calcul de la somme des N entiers de chaque colonne d’une matrice.", 0, 5);
		switch (choix) {
		case 0:
			return EXIT_SUCCESS;
		case 1:
			sum = askUserFillTab(tabInteger, size);
			printTab(tabInteger, size);
			cout << "Et la somme est : " << sum << endl;
			break;
		case 2:
			sum = askUserFillTab(tabInteger, size);
			printTab(tabInteger, size);
			cout << "Et la moyenne est : " << (float)sum/size << endl;
			break;
		case 3:
			max = askUserFillStringTab(tabString, size);
			cout << "Le maximum est : " << max << endl;
			break;
		case 4:
			cout << "Veuillez remplir cette matrice de caractere : " << endl;
            cout << "tab[" << 0 << "]" << "[" << 0 << "]" << " ?= ";
			cin >> matrixChar[0][0];
            min = matrixChar[0][0];
			for (int col = 0; col < size; col++) {
				for (int row = 0; row < size; row++) {
                    if(col == 0 && row == 0){
                        continue;
                    }
					cout << "tab[" << col << "]" << "[" << row << "]" << " ?= ";
					cin >> matrixChar[col][row];
					if (min > matrixChar[col][row]) {
						min = matrixChar[col][row];
					}
				}
			}

			cout << "Le plus petit caractere est : " << min << endl;
			break;
		case 5:
			cout << "Veuillez remplir cette matrice d'entier : " << endl;
            cout<< "Le tableau est représenté sous la forme tab[col][row]" <<endl;
            cout << "Vous entrez donc les données lignes par lignes et non colonne par colonne" << endl;
			for (int col = 0; col < size; col++) {
				tabInteger[col] = 0;
				for (int row = 0; row < size; row++) {
					cout << "tab[" << col << "]" << "[" << row << "]" << " ?= ";
					cin >> matrixInteger[col][row];
					tabInteger[col] += matrixInteger[col][row];
				}
			}
			printTab(tabInteger, size);
			break;
		}
	}
}
int askNumber(string sentence, int min, int max, int tries) {
	int input;
	for (int i = 0; i < tries; i++) {
		cout << sentence << endl;
		cin >> input;
		if (input >= min && input <= max) {
			return input;
		}
	}
	return ERROR_CODE;
}

void printTab(int tab[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "tab[" << i << "] = " << tab[i] << endl;
	}
}

int askUserFillTab(int tab[], int size) {
	int sum = 0;
	cout << "Veuillez remplir ce tableau d'entier :" << endl;
	for (int i = 0; i < size; i++) {
		cout << "tab[" << i << "] ?= ";
		cin >> tab[i];
		sum += tab[i];
	}
	return sum;
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
