#include "war.h"

void war(deck deck1, int* p1s, int* p2s) {
	bool warring(true), toShuffle(false), enoughCards(true);

	system("cls");
	cout << "WAR!" << endl;
	system("pause");
	
		do {
			if (deck1.rmng(deck1.picked) > 44) {
				cout << "Not Enough Cards For A War!" << endl; warring=false;
			} else {
				do{
					toShuffle=false;
					deck1.shuf(deck1.cards, deck1.picked, deck1.values);
					deck1.check(deck1.picked);
					if (deck1.picked[0] == 1 || deck1.picked[1] == 1 || deck1.picked[2] == 1 || deck1.picked[3] == 1 || deck1.picked[4] == 1 || deck1.picked[5] == 1 || deck1.picked[6] == 1 || deck1.picked[7] == 1) {
						toShuffle=true;
					}
				} while (toShuffle);
				
				
				

				cout << "\nPlayer one puts three cards face down...";
				cout << "\nPlayer two puts three cards face down...\n";
				system("pause");
				
				
				cout << "\n\nPlayer one draws: "/*[" << deck1.picked[0] << "] "*/ << deck1.cards[0] /*<< "(" << deck1.values[0] << ")"*/ << endl
					 <<     "Player two draws: "/*[" << deck1.picked[1] << "] "*/ << deck1.cards[1] /*<< "(" << deck1.values[1] << ")\n"*/ << endl;
				deck1.picked[0] = true;
				deck1.picked[1] = true;
				system("pause");
				
				/**
				 *for (int i=0; i < 52; i++) {
				 *	cout << "[" << deck1.picked[i] << "] " << deck1.cards[i] << endl;	
				 *}
				 */

				
				for (int i=2; i <= 7; i++)
				 deck1.picked[i] = true; 
				 
					 if (deck1.values[0] > deck1.values[1]) {warring=false; p1s+=6; cout << "\nPlayer 1 wins the war!\nPlayer 1 gets: " << endl << deck1.cards[2] << endl << deck1.cards[3] << endl << deck1.cards[4] << endl << deck1.cards[5] << endl << deck1.cards[6] << endl << deck1.cards[7] << endl << endl;}
				else if (deck1.values[0] < deck1.values[1]) {warring=false; p2s+=6; cout << "\nPlayer 2 wins the war!\nPlayer 2 gets: " << endl << deck1.cards[2] << endl << deck1.cards[3] << endl << deck1.cards[4] << endl << deck1.cards[5] << endl << deck1.cards[6] << endl << deck1.cards[7] << endl << endl;}
				else 	{warring=true; cout << "\nIt's a tie! War again!\n"; system("pause");}
			}
		} while (warring);
	
}

int main () {
	srand(time(0));
	int p1s(0), p2s(0), tie(0);
	int* p1p = &p1s;
	int* p2p = &p2s;
	bool game(1);
	deck scoredeck;
	deck deck1;
	
	while (game) {
		do {
			deck1.shuf(deck1.cards, deck1.picked, deck1.values);
			deck1.check(deck1.picked);
		} while (deck1.picked[0] == 1 || deck1.picked[1] == 1);
		
		
		system("cls");
		cout << "Player one draws: "/* [" << deck1.picked[0] << "] "*/ << deck1.cards[0] /*<< "(" << deck1.values[0] << ")"*/ << endl
			 << "Player two draws: "/* [" << deck1.picked[1] << "] "*/ << deck1.cards[1] /*<< "(" << deck1.values[1] << ")\n"*/ << endl;
		deck1.picked[0] = true;
		deck1.picked[1] = true;
		/**
		 *for (int i=0; i < 52; i++) {
		 *	cout << "[" << deck1.picked[i] << "] " << deck1.cards[i] << endl;	
		 *}
		 */

		
			 if (deck1.values[0] > deck1.values[1]) {p1s++; cout << "\nPlayer one wins!\n\n";}
		else if (deck1.values[0] < deck1.values[1]) {p2s++; cout << "\nPlayer two wins!\n\n";}
		else 	{ tie++; cout << "\nWAR!\n"; system("pause"); war(deck1, p1p, p2p);}
		
		if (deck1.rmng(deck1.picked) == 52) {
		cout << "P1's score: " << p1s << endl << "P2's score: " << p2s << endl << "Ties: " << tie << endl;
				 if (p1s > p2s) cout << "\nP1 wins the game!" << endl;
			else if (p1s < p2s) cout << "\nP2 wins the game!" << endl;
			else 	cout << "\nTie game!\n";
			p1s=0; p2s = 0;
		}
		system("pause");
		
	}
	
}