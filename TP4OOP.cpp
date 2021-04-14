#include <iostream>
#include <string>
#include <locale>

using namespace std;

const int NMAX = 20;

void awaitInput(int min, int max, string wim, string msg, int &value);
void showMenu();
template<typename T>
class Vector{

    private:
        Vector calculateMinMax(){
            if(!generated){
                cout << "Erreur ! Vous n'avez pas encore entré les valeurs du tableau" << endl;
                return *this;
            }
            calculated = true;
            for(int i =0; i < size; i++){
                if(tab[indexMin] > tab[i]){
                    indexMin = i;
                }else if(tab[indexMax] < tab[i]){
                    indexMax = i;
                }
            }
            return *this;
        }
    public:
        int size = 0, indexMin = 0, indexMax = 0;
        bool generated = false, calculated = false;
        T* tab = new T[0];

        Vector fillTab(){
            generated = true;
            calculated = false;
            awaitInput(1, NMAX, "Erreur votre nombre n'est pas compris entre 1 et " + to_string(NMAX), "Veuillez entrez la taille voulue du vecteur comprise entre 1 et "+ to_string(NMAX), size);
            delete [] tab;
            tab = new T[size];
            for(int i =0; i<size; i++){
                cout<<"tab[" <<i << "] ?= ";
                cin >> tab[i];
            }
            return *this;
        }

        Vector print(){
            if(!generated){
                cout << "Erreur ! Vous n'avez pas encore entré les valeurs du tableau" << endl;
                return *this;
            }
            for(int i =0;i <size; i++){
                cout << "tab[" << i << "] = " << tab[i] << endl;
            }
            return *this;
        }

        Vector getMinAndMax(T &min, T &max){
            if(!generated){
                cout << "Erreur ! Vous n'avez pas encore entré les valeurs du tableau" <<endl;
                return *this;
            }
            if(!calculated){
                calculateMinMax();
            }
            min = tab[indexMin];
            max = tab[indexMax];
            return *this;
        }

        Vector reverseMinMax(){
            if(!generated){
                cout << "Erreur ! Vous n'avez pas encore entré les valeurs du tableau" <<endl;
                return *this;
            }
            swap(tab[indexMin], tab[indexMax]);
            swap(indexMin, indexMax);
            return *this;
        }

        Vector insertElement(int index, T element){
            if(!generated){
                cout << "Erreur ! Vous n'avez pas encore entré les valeurs du tableau" << endl;
                return *this;
            }
            if(size >= NMAX){
                cout << "Warning ! La taille du tableau dépasse la taille max." << endl; // Seulement un warning vu que tableau avec taille dynamique
            }
            calculated = false;
            T* tempTab = new T[size +1];
            for(int i = size+1; i> index; i--){
                tempTab[i] = tab[i - 1];
            }
            for(int i =0; i< index; i++){
                tempTab[i] = tab[i];
            }
            size++;
            tempTab[index] = element;
            delete [] tab;
            tab = tempTab;
            return *this;
        }

        Vector insertElementMid(){
            if(!generated){
                cout << "Erreur ! Vous n'avez pas encore entré les valeurs du tableau" << endl;
                return *this;
            }
            T element;
            cout << "Quel élément voulez vous insérer au milieu ? " <<endl;
            cin >> element;
            insertElement(size/2, element);
            return *this;
        }

};



int main(){
    Vector<int> vector;
    int choix, min, max;
    while(1){
        showMenu();
        awaitInput(1, 7, "Le nombre entré n'est pas compris entre 1 et 7", "Veuillez entrer un nombre entre 1 et 7 en fonction de ce que vous voulez faire.", choix);
        if(!vector.generated && choix!=1 && choix!=7){
            cout << "Erreur veuillez choisir l'option 1 pour remplir le tableau" << endl;
            continue;
        }
        switch(choix){
            case 1:
                vector.fillTab().print();
                break;
            case 2:
                vector.getMinAndMax(min, max);
                cout << "Le minimum est : " << min << " et le maximum est : " << max <<endl;
                break;
            case 3:
                vector.reverseMinMax().print();
                break;
            case 4:
                vector.insertElementMid().print();
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

void awaitInput(int min, int max, string wim, string msg, int &value){
    cout << msg << endl;
    cin >> value;
    while(value > max || value < min){
        cout << wim << endl;
        cin >> value;
    }
}

void showMenu(){
    cout << "1. Saisie du vecteur et affichage de ses données." << endl;
    cout << "2. Calcul (1 seule fonction) et affichage du minimum et du maximum du vecteur." << endl;
    cout << "3. Échange de position maximum <-> minimum et affichage du vecteur." <<endl;
    cout << "4. Ajout d’un élément au milieu du vecteur et affichage du vecteur." << endl;
    cout << "5." << endl;
    cout << "6." << endl;
    cout << "7. Quitter" << endl;
}
