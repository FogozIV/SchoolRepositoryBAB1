#include <iostream>
#include <string>
#include <locale>

using namespace std;

const int NMAX = 20;

void awaitInput(int min, int max, string wim, string msg, int &value);
void showMenu();

template <typename T>
void calculateMinMaxIndex(T tab[], int size, int &indexMin, int &indexMax);

template <typename T>
void printTab(T tab[], int size);

template <typename T>
void fillTab(T tab[], int &size);

template <typename T>
void calculateMinMax(T tab[], int size, T &min, T &max);

template <typename T>
void reverseMinMax(T tab[], int size);

template<typename T>
void insertElement(T tab[], int &size, int index, T element);

template <typename T>
void insertElementMid(T tab[], int &size);

int main()
{
    int choix, min, max, size;
    int tab[NMAX];
    bool generated = false;
    while (1)
    {
        showMenu();
        awaitInput(1, 7, "Le nombre entré n'est pas compris entre 1 et 7", "Veuillez entrer un nombre entre 1 et 7 en fonction de ce que vous voulez faire.", choix);
        if (!generated && choix != 1 && choix != 7)
        {
            cout << "Erreur veuillez choisir l'option 1 pour remplir le tableau" << endl;
            continue;
        }
        switch (choix)
        {
        case 1:
            fillTab<int>(tab, size);
            printTab<int>(tab, size);
            generated = true;
            break;
        case 2:
            calculateMinMax<int>(tab, size, min, max);
            cout << "Le minimum est : " << min << " et le maximum est : " << max << endl;
            break;
        case 3:
            reverseMinMax<int>(tab, size);
            printTab<int>(tab, size);
            break;
        case 4:
            insertElementMid<int>(tab, size);
            printTab<int>(tab, size);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            cout << "Au revoir" << endl;
            system("pause");
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}

void awaitInput(int min, int max, string wim, string msg, int &value)
{
    cout << msg << endl;
    cin >> value;
    while (value > max || value < min)
    {
        cout << wim << endl;
        cin >> value;
    }
}

void showMenu()
{
    cout << "1. Saisie du vecteur et affichage de ses données." << endl;
    cout << "2. Calcul (1 seule fonction) et affichage du minimum et du maximum du vecteur." << endl;
    cout << "3. Échange de position maximum <-> minimum et affichage du vecteur." << endl;
    cout << "4. Ajout d’un élément au milieu du vecteur et affichage du vecteur." << endl;
    cout << "5." << endl;
    cout << "6." << endl;
    cout << "7. Quitter" << endl;
}

template <typename T>
void calculateMinMaxIndex(T tab[], int size, int &indexMin, int &indexMax)
{
    indexMin = 0;
    indexMax = 0;
    for (int index = 0; index < size; index++)
    {
        if (tab[indexMin] > tab[index])
        {
            indexMin = index;
        }
        else if (tab[indexMax] < tab[index])
        {
            indexMax = index;
        }
    }
}

template <typename T>
void fillTab(T tab[], int &size)
{
    awaitInput(1, NMAX, "Erreur votre nombre n'est pas compris entre 1 et " + to_string(NMAX), "Veuillez entrez la taille voulue du vecteur comprise entre 1 et " + to_string(NMAX), size);
    for (int i = 0; i < size; i++)
    {
        cout << "tab[" << i << "] ?= ";
        cin >> tab[i];
    }
}

template <typename T>
void printTab(T tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "tab[" << i << "] = " << tab[i] << endl;
    }
}
template <typename T>
void calculateMinMax(T tab[], int size, T &min, T &max)
{
    int indexMin, indexMax;
    calculateMinMaxIndex(tab, size, indexMin, indexMax);
    min = tab[indexMin];
    max = tab[indexMax];
}

template <typename T>
void reverseMinMax(T tab[], int size)
{
    int indexMin, indexMax;
    calculateMinMaxIndex(tab, size, indexMin, indexMax);
    swap(tab[indexMin], tab[indexMax]);
}

template<typename T>
void insertElement(T tab[], int &size, int index, T element){
    size++;
    for(int i = size; i > index; i--){
        tab[i] = tab[i - 1];
    }
    tab[index] = element;
}
template <typename T>
void insertElementMid(T tab[], int &size){
    T element;
    cout << "Veuillez entré l'élément que vous voulez insérer : ";
    cin >> element;
    insertElement(tab, size, size/2, element);
}
