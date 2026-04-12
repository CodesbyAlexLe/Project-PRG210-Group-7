#ifndef CART_H
#define CART_H
#include "Product.h."

class Cart 
{
private:
  Product* cartItems;
  int* quantities;
  int totalItems;
  double totalCost;

public:
  Cart();
  ~Cart();

  void addToCart(const Product& p, int quantity);
  void listCartItems() const;
  void checkout();
  bool isEmpty() const;
  void clearCart();
  double calculateTotal() const;
};

#endif
