#ifndef __SHOP__
#define __SHOP__
#include "Category.h"
#include "Product.h"
#include <vector>

class Shop
{
public:
	Shop(Category* category);
	void showProducts();
	void showProduct(unsigned int index);
	void removeProducts();
	void removeProduct(unsigned int index);
	void addProduct();
	void load();
	void save();
	~Shop();
private:
	std::vector<Product*> m_products;
	Category* m_category;
};

#endif