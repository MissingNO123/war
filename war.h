#include <conio.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define RAND 1000

class deck {
public:
	string* cards;// = new string;[52];
	bool* picked;// = new bool[52];
	int* values;// = new int[52];
	
	deck () {
		cards = new string[52];
		picked = new bool[52];
		values = new int[52];
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