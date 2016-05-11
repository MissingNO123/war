#include <string>
#include <iostream>

using namespace std;

int main () {
	int k=0;
	string cards[52];
	string temp("");
	string crdNames[] = {
		"Two" , "Three" , "Four" , "Five" , 
		"Six" , "Seven" , "Eight" , "Nine" , "Ten" , 
		"Jack" , "Queen" , "King" , "Ace"
	};
	string suits[] = {"Hearts" , "Clubs" , "Diamonds" , "Spades"};
	for (int i=0; i < 4; i++) {
		for (int j=0; j < 13; j++) {
			k = j*i;
			temp.assign(crdNames[j]);
			temp.append(" of "); 
			temp.append(suits[i]);
			cards[k].assign(temp);
			cout << cards[k] << endl;
			temp.assign("");
			k++;
		}
		cout << endl;
	}
}