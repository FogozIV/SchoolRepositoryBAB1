#include <iostream>
#include <string>
#include <locale>

const int NMAX = 20;
using namespace std;
struct Product {
    string name = "Unknown";
    char code = '?';
    float price = -1;
};

void awaitInput(int min, int max, string wim, string msg, int& value);

void showMenu();

bool isSorted(Product tab[], int size, bool(*comparator)(Product, Product));

bool isSortedByName(Product tab[], int size);

void removeElementName(Product tab[], int& size, string name);

void sort(Product tab[], int size, bool(*comparator)(Product, Product)); // with lambda parameter : [](Product a, Product b) -> bool {return ...}

void removeElement(Product tab[], int& size, int index);

int countOccurence(string word, char c);

void addElement(Product tab[], int& size, Product p);

void displayProduct(Product p);

void displayTab(Product tab[], int size);

void fillTab(Product tab[], int& size);

Product askProduct();

Product matchProductWithMostOccurrences(Product tab[], int size, char c);

int main() {
    setlocale(LC_ALL, "fra");
    Product products[NMAX];
    int size = 0, choix;
    char tempChar;
    string tempString;
    while (1) {
        showMenu();
        awaitInput(1, 8, "Le nombre entré n'est pas compris entre 1 et 8", "Veuillez entrer un nombre entre 1 et 8 en fonction de ce que vous voulez faire.", choix);
        if (size == 0 && choix != 1 && choix != 8) {
            cout << "Votre tableau est actuellement de taille nulle. \nVeuillez d'abord remplir le tableau ou quitter." << endl;
            continue;
        }
        switch (choix)
        {
        case 1:
            fillTab(products, size);
            displayTab(products, size);
            break;
        case 2:
            cout << "Not implemented" << endl;
            break;
        case 3:
            sort(products, size, [](Product a, Product b) -> bool {return a.code > b.code; }); //if b is lower swap 
            displayTab(products, size);
            break;
        case 4:
            sort(products, size, [](Product a, Product b) -> bool {return a.name > b.name; }); //if b is lower swap 
            displayTab(products, size);
            break;
        case 5:
            cout << "Veuillez entrer le nom de produit que vous voulez supprimer " << endl;
            cin >> tempString;
            removeElementName(products, size, tempString);
            displayTab(products, size);
            break;
        case 6:
            addElement(products, size, askProduct());
            displayTab(products, size);
            break;
        case 7:
            cout << "Veuillez entrer le caractère dont les occurences seront cherchées : ";
            cin >> tempChar;
            cout << "Le produit avec le plus d'occurence de " << tempChar << " est : " << matchProductWithMostOccurrences(products, size, tempChar).name << endl;
            break;
        case 8:
            cout << "Au revoir " << endl;
            system("pause");
            return EXIT_SUCCESS;
            break;
        }
    }
}


void sort(Product tab[], int size, bool(*comparator)(Product, Product)) {
    bool changed;
    do {
        changed = false;
        for (int i = 0; i < size - 1; i++) {
            if (comparator(tab[i], tab[i + 1])) {
                changed = true;
                swap(tab[i], tab[i + 1]);
            }
        }
    } while (changed);
}

void removeElement(Product tab[], int& size, int index) {
    for (int i = index; i < size - 1; i++) {
        tab[i] = tab[i + 1];
    }
    size--;
}

void addElement(Product tab[], int& size, Product p) {
    if (size >= NMAX) {
        cout << "Erreur vous avez atteint la taille max du tableau" << endl;
        return;
    }
    if (isSortedByName(tab, size)) {
        for (int i = size; i > 0; i--) {
            if (tab[i - 1].name < p.name) {
                tab[i] = p;
                size++;
                return;
            }
            tab[i] = tab[i - 1];
            
        }
        tab[0] = p;
    }
    else {
        tab[size] = p;
    }
    size++;
}

void removeElementName(Product tab[], int& size, string name) {
    int offset = 0;
    for (int i = 0; i < size; i++) {
        if (tab[i].name == name) {
            offset++;
            continue;
        }
        tab[i - offset] = tab[i];
    }
    size -= offset;
}

int countOccurence(string word, char c) {
    int occurences = 0;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == c) {
            occurences++;
        }
    }
    return occurences;
}

Product matchProductWithMostOccurrences(Product tab[], int size, char c) {
    if (size == 0) {
        cout << "Erreur : la taille du tableau est nulle." << endl;
        return Product();
    }
    Product result = tab[0];
    int occ = countOccurence(result.name, c);
    for (int i = 1; i < size; i++) {
        int occi = countOccurence(tab[i].name, c);
        if (occi > occ) {
            occ = occi;
            result = tab[i];
        }
    }
    if (occ == 0) {
        Product p;
        p.name = "Introuvable";
        return p;
    }
    return result;
}

void displayProduct(Product p) {
    cout << "Produit : " << p.name << endl;
    cout << "Code Produit : " << p.code << endl;
    cout << "Prix du produit : " << p.price << endl;
    cout << endl;
}

Product askProduct() {
    Product p;
    cout << "Veuillez entrer le nom du produit : "; //now working with spaces
    cin.ignore();
    getline(cin, p.name);
    //cin >> p.name;
    cout << "Veuillez entrer le code du produit (char) : ";
    cin >> p.code;
    cout << "Veuillez entrer le prix du produit : ";
    cin >> p.price;
    cout << endl;
    return p;
}

void displayTab(Product tab[], int size) {
    for (int i = 0; i < size; i++) {
        displayProduct(tab[i]);
    }
}

void fillTab(Product tab[], int& size) {
    awaitInput(1, NMAX, "Erreur votre nombre n'est pas compris entre 1 et " + to_string(NMAX), "Veuillez entrez la taille voulue du vecteur comprise entre 1 et " + to_string(NMAX), size);
    for (int i = 0; i < size; i++)
    {
        cout << "Veuillez entrer le produit " << i << " qui se trouve dans le  tableau\n" << endl; //2line returns
        tab[i] = askProduct();
    }
}



void awaitInput(int min, int max, string wim, string msg, int& value)
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
    cout << "1. Saisie du tableau et affichage de ses données." << endl;
    cout << "2." << endl;
    cout << "3. Trier le tableau suivant le code" << endl;
    cout << "4. Trier le tableau suivant le nom." << endl;
    cout << "5. Effacer un élément selon le nom" << endl;
    cout << "6. Ajouter un élément selon le nom." << endl;
    cout << "7. Chercher le nom qui a le plus d’occurrence d’un caractère donné" << endl;
    cout << "8. Quitter" << endl;
}

bool isSorted(Product tab[], int size, bool(*comparator)(Product, Product)) {
    for (int i = 0; i < size - 1; i++) {
        if (!comparator(tab[i], tab[i + 1])) {
            return false;
        }
    }
    return true;
}

bool isSortedByName(Product tab[], int size) {
    return isSorted(tab, size, [](Product a, Product b) -> bool {return a.name < b.name; });
}

