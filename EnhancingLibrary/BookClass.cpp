#include "BookClass.h"

BookClass::BookClass() {

}


void BookClass::storeBook(string bookTitle, string authorName, string bookPublisher, string bookISBN, double bookPrice, int bookYear, int booksInStock)
{
	title = bookTitle;
	author = authorName;
	publisher = bookPublisher;
	isbn = bookISBN;
	price = bookPrice;
	year = bookYear;
	numInStock = booksInStock;
}

void BookClass::displayBookInfo()
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "ISBN: " << isbn << endl;
	cout << "Price: " << price << endl;
	cout << "Year: " << year << endl;
	cout << "Number of stock: " << numInStock << endl << endl;
}

void BookClass::checkOutBook()
{
	if (numInStock > 0)
	{
		numInStock--;
		cout << "Checked out one copy of " << title << endl;
	}
	else {
		cout << "ERROR: No copies of " << title << " in stock.";
	}
}

