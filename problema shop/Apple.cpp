#include <iostream>
#include "Apple.h"
using namespace std;

Apple::Apple(int price, int quantity, string country)
{
	this->price = price;
	this->quantity = quantity;
	this->country = country;
}
string Apple::GetType()
{
	string v = "Apple";
	return v;
}
int Apple::GetQuantity()
{
	return this->quantity;
}
int Apple::GetPrice()
{
	return this->price;
}

void Apple::Print()
{
	cout << "Apple (from=" << this->country << ") Price=" << this->price<<" Quantity=" << this->quantity<<endl;
}