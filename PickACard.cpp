/*
Kenji Hirai
CIS1202
03/04/2019
Week 7
 Assignment 8 – Pick a Card
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum suits {CLUBS, DIAMONDS, HEARTS, SPADES};
enum cardValues {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct cards { 
	suits suit; 
	cardValues card; 
};

cards deck[52];
cards card1, card2;

const string CARD_LABELS[] = { "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE" };
const string SUIT_LABELS[] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES" };

void createDeck(cards[]);
void printDeck(cards[]);
void printCard(cards);
void deal(cards[], cards&);
void winner(cards, cards);

int main() {

	cout << "Pick a card" << endl << endl;
	cout << "THe card deck" << endl << endl;
	createDeck(deck);
	printDeck(deck);

	system("pause");
	return 0;
}

void createDeck(cards deck[52]) {
	int i = 0;
	for (suits suit = CLUBS; suit <= SPADES; suit = suits(suit + 1)) {
		for (cardValues card = TWO; card <= ACE; card = cardValues(card + 1)) {
			deck[i].suit = suit;
			deck[i].card = card;
			i++;
		}
	}
}

void printDeck(cards deck[52]) {
	for (int i = 0; i < 52; i++) {
		cout << CARD_LABELS[deck[i].card] << " of "
			<< SUIT_LABELS[deck[i].suit] << endl;
	}
}

void printCard(cards) {
	cout << "Card1 = " << endl << endl;
	cout << "Card2 = " << endl << endl;
}