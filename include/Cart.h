#ifndef CART_H
#define CART_H
#include "Product.h"

    /*
        Cart class
        This class represents the customer's shopping cart
        It stores selected products along with their quantities
    */
class Cart
{
private:
    Product* cartItems; 
    int* quantities;
    int totalItems; //Total number of different items in the cart
    double totalCost; //Total cost of items in the cart (including the tax)

public:
    Cart(); //Constructor
    ~Cart(); //Destructor - Frees dynamically allocated memory (cartItems and quantities)

    void addToCart(const Product& p, int quantity);
    void listCartItems() const;
    void checkout();
    bool isEmpty() const;
    void clearCart();
    double calculateTotal() const;
};

#endif

