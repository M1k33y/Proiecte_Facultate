#pragma once
#include "Article.h"
#include <vector>
class Book :public Article
{
private:
	string title;
	string author;
	int quantity;
	int price;
public:
	Book(int price,int quantity,string Title,string Author);
	string GetType() override;
	int GetQuantity() override;
	int GetPrice() override;
	void Print() override;
};
