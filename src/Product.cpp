#include <iostream>
#include <cstring>
#include "Product.h"
using namespace std;

Product::Product()
{
  name[0] = '\0';
  price = 0.0;
  quantity = 0;
}

Product::Product(const char* n, double p, int q)
{
  strcpy(name, n);
}

void Product::setPrice(double p)
{
  price = p;
}

void Product::setQuantity(int q)
{
  quantity = q;
}

const char* Product::getName() const
{
  return name;
}

double Product::getPrice() const
{
  return price;
}

int Product::getQuantity() const
{
  return quantity;
}

void Product::display() const
{
  cout << "Name: " name
       << ", Price: " << price
       << ", Quantity: " << quantity << endl;
}
