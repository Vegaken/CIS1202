/*
Kenji Hirai
CIS 1202
04/05/2019
Week 11 - More About Classes
Enhancing the Library Program
*/

#include <iostream>
#include <iomanip>
#include "BookClass.h"
#include <fstream>

using namespace std;

void getBookInfo(BookClass &);
void getBooks(BookClass[], int &);
void showBooks(BookClass[], int);
void showTitles(BookClass[], int);
int findBook(string, BookClass[], int);
int getMenuChoice();


int main() {
	const int MAX_BOOKS = 100;
	BookClass books[MAX_BOOKS];
	int librarySize = 0;
	int searchIn;
	string searchString;
	
	getBooks(books, librarySize);

	bool loop = true;
	while(loop){ 
		int choice = getMenuChoice();
			switch (choice) {
			case 1: showBooks(books, librarySize);
				break;
			case 2: showTitles(books, librarySize);
				break;
			case 3: cout << "Enter book title: ";
				getline(cin, searchString);
				searchIn = findBook(searchString, books, librarySize);
				cout << endl;
				if (searchIn)
					cout << books[searchIn].getNumInStock() << "Copies of " << books[searchIn].getTitle() << " in stock" << endl;
				else
					cout << "No copies of " << searchString << " in stock";
				break;
			case 4: cout << "Enter title of book to check out: ";
				getline(cin, searchString);
				searchIn = findBook(searchString, books, librarySize);
				cout << endl;
				if (searchIn)
					books[searchIn].checkOutBook();
				else
					cout << "No copies of " << searchString << " in stock";
				break;
			case 5: cout << "Enter title of book to check in: ";
				getline(cin, searchString);
				searchIn = findBook(searchString, books, librarySize);
				cout << endl;
				if (searchIn)
					books[searchIn].returnBook();
				else
					cout << "No copies of " << searchString << " in stock";
				break;
			case 6: cout << "You have chosen to exit the program." << endl;
				loop = false;
				break;
			default: cout << "Incorrect menu selection, please enter a choice from 1 to 5." << endl;
			}
			cout << endl;
		} 
	system("pause");
	return 0;
}

void getBookInfo(BookClass &book){
	string bookTitle, authorName, bookPublisher, bookISBN;
	double bookPrice;
	int bookYear, booksInStock;

	cout << "Enter book information:" << endl;
	cout << "Enter the book title: ";
	getline(cin, bookTitle);
	cout << "Enter the author name: ";
	getline(cin, authorName);
	cout << "Enter the publisher: ";
	getline(cin, bookPublisher);
	cout << "Enter the book ISBN: ";
	getline(cin, bookISBN);
	cout << "Enter the book price: ";
	cin >> bookPrice;
	cout << "Enter the year published: ";
	cin >> bookYear;
	cout << "Enter the number of stock: ";
	cin >> booksInStock;

	book.storeBook(bookTitle, authorName, bookPublisher, bookISBN, bookPrice, bookYear, booksInStock);
}

void getBooks(BookClass books[], int &size) {
	string bookTitle, authorName, bookPublisher, bookISBN;
	double bookPrice;
	int bookYear, booksInStock;

	ifstream f("books.txt");
	if (f.fail())
		return;

	while (!f.eof()) {
		getline(f, bookTitle);
		getline(f, authorName);
		getline(f, bookPublisher);
		f >> bookISBN >> bookPrice >> bookYear >> booksInStock;
		f.ignore(1, '\n'); 

		books[size].storeBook(bookTitle, authorName, bookPublisher, bookISBN, bookPrice, bookYear, booksInStock);
		size++;
	}
}

void showBooks(BookClass books[], int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		books[i].displayBookInfo();
	}
}

void showTitles(BookClass books[], int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "\t" << books[i].getTitle() << endl;
	}
}

int findBook(string title, BookClass books[], int size) {
	for (int i = 0; i < size; i++) {
		if (title == books[i].getTitle())
			return i;
	}
	return NULL;
}

int getMenuChoice() {
	
	int choice = 0;

	cout << "\nKenji's Library" << endl << endl;
	cout << "Please select from the menu below" << endl << endl;
	cout << "1 - Display all books" << endl;
	cout << "2 - Display Book titles" << endl;
	cout << "3 - Find book" << endl;
	cout << "4 - Check out" << endl;
	cout << "5 - Check in" << endl;
	cout << "6 - Exit program" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;

	return choice;
}
