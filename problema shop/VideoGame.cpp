#include <iostream>
#include "VideoGame.h"
using namespace std;

VideoGame::VideoGame(int price, int quantity, string platform, string name)
{
	this->price = price;
	this->quantity = quantity;
	this->platform = platform;
	this->name = name;
}
string VideoGame::GetType()
{
	string v = "VideoGame";
	return v;
}
int VideoGame::GetPrice()
{
	return this->price;
}
int VideoGame::GetQuantity()
{
	return this->quantity;
}
void VideoGame::Print()
{
	cout << "VideoGame (Platoform=" << this->platform << ", Name=" << this->name << ") Price=" << this->price << " Quantity=" << this->quantity << endl;
}