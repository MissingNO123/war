#include <conio.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define RAND 1000

class deck {
public:
	string* cards = new string[52];
	bool* picked = new bool[52];
	int* values = new int[52];
	
	deck () {
		int k=0;
		string temp("");
		string crdNames[] = {
			"Two" , "Three" , "Four" , "Five" , 
			"Six" , "Seven" , "Eight" , "Nine" , "Ten" , 
			"Jack" , "Queen" , "King" , "Ace"
		};
		string suits[] = {"Hearts" , "Clubs" , "Diamonds" , "Spades"};
		for (int i=0; i < 4; i++) {
			for (int j=0; j < 13; j++) {
				temp.assign(crdNames[j]);
				temp.append(" of "); 
				temp.append(suits[i]);
				cards[k].assign(temp);
				picked[k]=false;
				//cout << k << ": " << cards[k] << endl;
				temp.assign("");
				values[k] = j;
				k++;
			}
			//cout << endl;
		}
	
	}
	
	void initDeck (bool *p) {
		for (int i=0; i < 52; i++) p[i]=false;
	}
	
	int rmng (bool *p) {
		int chk(0);
		for (int i=0; i < 52; i++) {
			if (p[i]) chk++;
		}
		return chk;
	}
	
	bool check (bool *p) {
		int chk=rmng(p);
		if (chk == 52) {
			cout << "\nPlease wait, now re-shuffling...\n";
			//system("sleep 0.5");
			initDeck(p);
			return 1;
		}
		else return 0;
	}
	
	void shuf (string *d, bool *p, int *v) {
		string temp("");
		bool bemp = 0;
		int rint(0), vemp(0), j(0);
		for (int i=0; i < RAND; i++) {
			rint = rand()%51;
			
			temp.assign(d[rint]);
			bemp   =    p[rint];
			vemp   =    v[rint];
			
			d[rint].assign(d[rint+1]);
			p[rint]    =   p[rint+1];
			v[rint]    =   v[rint+1];
			
			d[rint+1].assign(temp);
			p[rint+1] =      bemp;
			v[rint+1] =      vemp;
		}
		
		for (int i = 1; i < 52; i++) {
            j = i;
			
            while (j > 0 && p[j - 1] > p[j]) {
                temp.assign(d[j]);
				d[j].assign(d[j-1]);
				d[j-1].assign(temp);
				
				bemp   = p[j];
				p[j]   = p[j-1];
				p[j-1] = bemp;
				
				vemp   = v[j];
				v[j]   = v[j-1];
				v[j-1] = vemp;
				j--;
            }
		}
	}
};

void war(deck deck1, int* p1s, int* p2s) {
	bool warring(true), toShuffle(false), enoughCards(true);
	
		do {
			if (deck1.rmng(deck1.picked) <= 8) {cout << "Not Enough Cards For A War!" << endl; system("pause"); warring=false;}
			else {
				do{
					toShuffle=false;
					deck1.shuf(deck1.cards, deck1.picked, deck1.values);
					deck1.check(deck1.picked);
					if (deck1.picked[0] == 1 || deck1.picked[1] == 1 || deck1.picked[2] == 1 || deck1.picked[3] == 1 || deck1.picked[4] == 1 || deck1.picked[5] == 1 || deck1.picked[6] == 1 || deck1.picked[7] == 1) {
						toShuffle=true;
					}
				} while (toShuffle);
				
				
				system("cls");
				cout << "WAR!" << endl << endl;
				system("sleep 1");
				cout << "Player one puts three cards face down...\t";
				for (int i=0; i < 3; i++) {cout << "*\t"; system("sleep 0.1");}
				cout << "\n\nPlayer two puts three cards face down...\t";
				for (int i=0; i < 3; i++) {cout << "*\t"; system("sleep 0.1");}
				
				system("sleep 2");
				cout << "\n\nPlayer one draws: [" << deck1.picked[0] << "] " << deck1.cards[0] /*<< "(" << deck1.values[0] << ")"*/ << endl
					 << "Player two draws: [" << deck1.picked[1] << "] " << deck1.cards[1] /*<< "(" << deck1.values[1] << ")\n"*/ << endl;
				deck1.picked[0] = true;
				deck1.picked[1] = true;
				system("sleep 1");
				
				/**
				 *for (int i=0; i < 52; i++) {
				 *	cout << "[" << deck1.picked[i] << "] " << deck1.cards[i] << endl;	
				 *}
				 */

				
				for (int i=2; i <= 7; i++)
				 deck1.picked[i] = true; 
				 
					 if (deck1.values[0] > deck1.values[1]) {warring=false; p1s+=6; cout << "\nPlayer 1 wins the war!\nPlayer 1 gets: " << endl << deck1.cards[2] << endl << deck1.cards[3] << endl << deck1.cards[4] << endl << deck1.cards[5] << endl << deck1.cards[6] << endl << deck1.cards[7] << endl << endl;}
				else if (deck1.values[0] < deck1.values[1]) {warring=false; p2s+=6; cout << "\nPlayer 2 wins the war!\nPlayer 2 gets: " << endl << deck1.cards[2] << endl << deck1.cards[3] << endl << deck1.cards[4] << endl << deck1.cards[5] << endl << deck1.cards[6] << endl << deck1.cards[7] << endl << endl;}
				else 	{warring=true; cout << "\nIt's a tie! War again!\n"; system("sleep 0.5"); system("pause");}
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

		
			 if (deck1.values[0] > deck1.values[1]) {p1s++; cout << "\nPlayer one wins!\n";}
		else if (deck1.values[0] < deck1.values[1]) {p2s++; cout << "\nPlayer two wins!\n";}
		else 	{ tie++; cout << "\nWAR!\n"; system("pause"); war(deck1, p1p, p2p);}
		
		if (deck1.rmng(deck1.picked) == 52) {
		cout << "p1s: " << p1s << endl << "p2s: " << p2s << endl << "ties: " << tie << endl;
				 if (p1s > p2s) cout << "\np1 win game" << endl;
			else if (p1s < p2s) cout << "\np2 win game" << endl;
			else 	cout << "\ntie game\n";
			system("sleep 1");
			p1s=0; p2s = 0;
		}
		system("pause");
		
	}
	
}