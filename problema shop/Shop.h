#pragma once

#include "Article.h"
#include <vector>
class Shop
{
private:
	vector<Article*>items;
public:
	void Add(Article* newitem);
	int GetTotalPrice();
	int GetQuantity(string type);
	void List();
};