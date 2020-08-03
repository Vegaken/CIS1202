#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class BookClass {

private:
	string title = "";
	string author = "";
	string publisher = "";
	string isbn = "";
	double price = 0;
	int year = 0;
	int numInStock = 0;


public:
	BookClass();
	
	void storeBook(string bookTitle, string authorName, string bookPublisher, string bookISBN, double bookPrice, int bookYear, int booksInStock);
	void displayBookInfo();
	void checkOutBook();
	void returnBook() { numInStock++; };
	
	string getTitle() { return title; };
	int getNumInStock() { return numInStock; };
};




