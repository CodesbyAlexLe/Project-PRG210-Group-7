#include <iostream>
#include "Cart.h"
using namespace std;

Cart::Cart()
{
  cartItems = nullptr;
  quantities = nullptr;
  totalItems = 0;
  totalCost = 0.0;
}

Cart::~Cart()
{
  delete[] cartItems;
  delete[] quantities;
}

void Cart::addToCart(const Product& p, int quantity)
{
    Product* newCartItems = new Product[totalItems + 1];
    int* newQuantities = new int[totalItems + 1];

    for (int i = 0; i < totalItems; i++)
    {

        newCartItems[i] = cartItems[i];
        newQuantities[i] = quantities[i];
    }

    newCartItems[totalItems] = p;
    newQuantities[totalItems] = quantity;

    delete[] cartItems;
    delete[] quantities;

    cartItems = newCartItems;
    quantities = newQuantities;

    totalItems++;

    totalCost += p.getPrice() * quantity;
}

void Cart::listCartItems() const
{
  if (totalItems == 0)
  {
      cout << "No items in the cart." << endl;
      return;
  }

  for (int i = 0; i < totalItems; i++)
  {
      cout << i + 1 << ". " 
           << cartItems[i].getName()
           << " | Qty: " << quantities[i]
           " | Price: $" << cartItems[i].getPrice() << endl;
  }
  cout << "Total with tax: $" << calculateTotal() << endl;
}

