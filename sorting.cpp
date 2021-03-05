
#include <iostream>

using namespace std;

void insertion_sort(int tab[], int tabLength);
void tricolor_flag(int tab[], int tabLength);
void selection_sort(int tab[], int tabLength);
void better_tricolor_flag(int tab[], int tabLength);

void printTab(int tab[], int tabLength);
int main()
{

	//Test use purpose
	/*int tab[] = {0,1,0,1,2,0,1,0,2,0,1,2,1,0,1,2,0,1,0,1,2,0,1,1,1,2,0};
	const int size = 27;
	tricolor_flag(tab, size);
	printTab(tab, size);*/

	//Test use purpose
	/*int iTab[] = { 1,4,2,6,7,2,1,0,19,25,155,785,02,21,45,6,17 };
	const int iSize = 17;
	selection_sort(iTab, iSize);
	printTab(iTab, iSize);*/
}

//No need to study that X)
void printTab(int tab[], int tabLength) {
	for (int i = 0; i < tabLength; i++) {
		cout << " " << tab[i];
	}
	cout << endl;
}

//Insertion sort see slide 158
void insertion_sort(int tab[], int tabLength) {
	//variable that will store the element we take from the list
	double current_element;
	//go through the entire tab
	int j;
	for (int i = 0; i < tabLength; i++) {

		current_element = tab[i]; //assign current_element value to element in current tab index
		//This loop go from the current index to 1 only if the current element is lower than the index we currently are looking
		for (j = i; j > 0 && tab[j - 1] > current_element; j--) {
			tab[j] = tab[j - 1];
		}
		//now that we are out it means that either the entire tab moved from one up or that the variable j is the new index for the current_element
		tab[j] = current_element;
	}
}
/*Tricolor flag
for this example we will assume that:
 - 0 is blue 
 - 1 is white
 - 2 is red 
 //slide 171
*/
void tricolor_flag(int tab[], int tabLength) {
	const int BLUE = 0; //Const so that we can express tab index == color
	const int WHITE = 1;
	const int RED = 2;
	int zw = 0; //Start of the white zone
	int zr = 0; //Start of the red zone
	int zac; //Start of the zone to store
	for (zac = 0; zac < tabLength; zac++) {
		if (tab[zac] == RED) {
			//Nothing to do because we are using for loop which will increase the zac every single time.
		}
		else if (tab[zac] == WHITE) {
			swap(tab[zac], tab[zr]);
			zr++;
		}
		else {
			//It's blue
			swap(tab[zac], tab[zr]);
			swap(tab[zr], tab[zw]);
			zr++;
			zw++;
		}
	}
}
/*
A better version of tricolor flag slide 176
same assumption as above
*/
void better_tricolor_flag(int tab[], int tabLength) {
	const int BLUE = 0; //Const so that we can express tab index == color
	const int WHITE = 1;
	const int RED = 2;
	int zw = 0; //Start of the white zone
	int zr = tabLength; //Start of the red zone //more like the end
	int zac = 0; //Start of the zone to store
	while (zac != zr) {
		if (tab[zac] == RED) {
			swap(tab[zac], tab[zr - 1]);
			zr--;
		}
		else if (tab[zac] == WHITE) {
			zac++;
		}
		else {
			swap(tab[zac], tab[zw]);
			zac++;
			zw++;
		}
	}
}

/*
Selection sort see slide 140

*/
void selection_sort(int tab[], int tabLength) {
	int i, min, j;
	for (i = 0; i < tabLength - 1; i++) {
		min = i; // Initializing variable to the current value of i it in fact means that we assume the current is the smaller one
		for (j = i + 1; j < tabLength; j++) {
			if (tab[j] < tab[min]) { //Chack if the current min is really smaller than the current index
				min = j;
			}
		}
		if (min != i) {
			swap(tab[i], tab[min]);
		}
	}
}
