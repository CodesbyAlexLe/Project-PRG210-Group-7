#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

/*
  Product class
  It stores the basic information for each item, such as name, price, and quantity 
*/

class Product {
private:
  char m_name[100]; //Item name (Product)
  double m_price; //store the price of the item
  int m_quantity; //stores the available quantity of the item

public:
  Product(); //Default constructor

  // Initializes product with given name, price, and quantity
  Product(const char* name, double price, int quantity);

};
#endif
