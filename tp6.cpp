#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int NC_MAX = 5;
const int NE_MAX = 6;
#define COTE_SPACE 9
struct Etudiant{
    int cotes[NC_MAX];
    string nom;
};

void showMenu();

void awaitInput(int min, int max, string wim, string msg, int &value);

void readFile(Etudiant tab[], int &NC, int &NE, string filename);

void printTab(Etudiant tab[], int NC, int NE);

void printEtudiant(Etudiant e, int NC);

void writeFile(Etudiant tab[], int NC, int NE, string filename);

void insert(Etudiant tab[], int &NE, Etudiant toInsert, int index);

void removeEtudiant(Etudiant tab[], int &NE, int index);

Etudiant askEtudiant(int NC);

int main(){
    int choix;
    string filename;
    int tempInt;
    int NE = 0;
    int NC = 0;
    Etudiant tab[NE_MAX];
    while(1){
        showMenu();
        awaitInput(1,5,"Le nombre entré n'est pas compris entre 1 et 5", "Veuillez entrer un nombre entre 1 et 5 en fonction de ce que vous voulez faire.", choix);
        switch(choix){
            case 1:
                cout << "Veuillez entrer le nom du fichier : ";
                cin >> filename;
                readFile(tab, NC, NE, filename);
                printTab(tab, NC, NE);
                break;
            case 2:
                cout << "Où voulez vous ajouter un étudiant ? ";
                cin >> tempInt;
                insert(tab, NE, askEtudiant(NC), tempInt);
                printTab(tab, NC, NE);
                break;
            case 3:
                cout << "Not implemented" << endl; 
                break;
            case 4:
                cout << "Quel index voulez-vous supprimer ? ";
                cin >> tempInt;
                removeEtudiant(tab, NE, tempInt);
                printTab(tab, NC, NE);
                break;
            case 5:
                cout << "Veuillez entrer le nom du fichier : ";
                cin >> filename;
                writeFile(tab, NC, NE, filename);
                cout << endl << "Sauvegardé ! " << endl;
                break;
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

void showMenu(){
    cout << "1 - Lire les données dans un fichier et AFFICHAGE du tableau" << endl;
    cout << "2 - Ajouter à la position P et affichage" << endl;
    //cout << "3 – Calculer les moyennes" << endl;
    cout << "3. Not implemented" << endl;
    cout << "4 – Supprimer à la position P et affichage" << endl;
    cout << "5 - Sauvegarder" << endl;
}

Etudiant askEtudiant(int NC){
    Etudiant e;
    cout << "Quel est le nom de l'étudiant ?" << endl;
    cin.ignore();
    getline(cin, e.nom);
    for(int i = 0; i<NC; i++){
        cout << "Quelle est la côte : " << i << " ? ";
        cin >> e.cotes[i];
    }
    return e;
}

void printEtudiant(Etudiant e, int NC){
    for(int i =0; i < NC; i++){
        cout << setw(COTE_SPACE) << left << e.cotes[i];
    }
    cout << e.nom << endl;
}

void removeEtudiant(Etudiant tab[], int &NE, int index){
    if(index < 0 || index >= NE){
         cout << "L'index ne peut pas être négatif ou plus grand ou égal à la taille" << endl;
         return;
    }
    for(int i = index; i < NE-1; i++){
        tab[i] = tab[i+1];
    }
    NE--;
}

void insert(Etudiant tab[], int &NE, Etudiant toInsert, int index){
    if(NE >= NE_MAX){
        cout << "Erreur taille max atteinte" << endl;
        return;
    }
    if(index > NE){
        cout << "Erreur au dessus de l'index maximum actuel " << endl;
        return;
    }
    for(int i = NE; i > index; i--){
        tab[i] = tab[i - 1];
    }
    tab[index] = toInsert;
    NE++;
}

void printTab(Etudiant tab[], int NC, int NE){
    for(int i = 0; i < NC; i++){
        cout << setw(COTE_SPACE)<< left << "Cote[" + to_string(i) + "]";
    }
    cout << "Nom" << endl;
    for(int i = 0; i<NE; i++){
        printEtudiant(tab[i], NC);
    }
}

void writeFile(Etudiant tab[], int NC, int NE, string filename){
    ofstream output(filename);
    output.clear();
    output << NC << " " << NE << endl;
    for(int i = 0; i < NE; i++){
        Etudiant c = tab[i];
        for(int cote = 0; cote < NC; cote++){
            output << c.cotes[cote] << " ";
        }
        output << c.nom << endl;
    }
    output.close();
}

void readFile(Etudiant tab[], int &NC, int &NE, string filename){
    ifstream reading(filename);
    reading >> NC >> NE;
    cout << NC << endl;
    cout << NE << endl;
    for (int i = 0; i < NE; i++){
        Etudiant e;
        for(int j = 0; j < NC; j++){
            reading >> e.cotes[j];
        }
        reading >> e.nom;
        tab[i] = e;
    }
    reading.close();
}
