#include <iostream>
#include "Book.h"
using namespace std;

Book::Book(int price, int quantity, string Title, string Author)
{
	this->price = price;
	this->quantity = quantity;
	this->title = Title;
	this->author = Author;
}

string Book::GetType()
{
	string v = "Book";
	return v;
}
int Book::GetQuantity()
{
	return this->quantity;
}
int Book::GetPrice()
{
	return this->price;
}
void Book::Print()
{
	cout << "Book (Title=" << this->title << ", Author=" << this->author << ") Price=" << this->price << " Quantity=" << this->quantity << endl;
}