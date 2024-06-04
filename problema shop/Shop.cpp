#include <iostream>
#include "Shop.h"
using namespace std;

void Shop::Add(Article* newitem)
{
	this->items.push_back(newitem);
}
int Shop::GetTotalPrice()
{
	int price = 0;
	for (int i = 0; i <= items.size(); i++)
		price = price + items[i]->GetPrice() * items[i]->GetQuantity();
	return price;
}
int Shop::GetQuantity(string type)
{
	int quantity = 0;
	for (int i = 0; i <= items.size(); i++)
		if (items[i]->GetType() == type)
			quantity = quantity + items[i]->GetQuantity();
	return quantity;
}
void Shop::List()
{
	for(int i=0;i<items.size();i++)
		items[i]->Print();
}