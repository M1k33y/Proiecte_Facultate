#pragma once

#include "Article.h"

class Apple :public Article
{
private:
	int price;
	int quantity;
	string country;
public:
	Apple(int price, int quantity,string country);
	string GetType() override;
	int GetQuantity() override;
	int GetPrice() override;
	void Print() override;
};
