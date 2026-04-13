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
    Product* items;                    // dynamic array of products
    int* quantities;                  // quantity for each time
    int totalItems;                  // count of items in cart
    double totalCost;               // total cost before tax                                   
    double totalWithTax;            // total cost with 13% tax


public:
    Cart(); //Constructor
    ~Cart(); //Destructor - Frees dynamically allocated memory (cartItems and quantities)

    void addToCart(const Product& p, int quantity);  // Adds a product and quantity to the cart
    void listCartItems() const; //Displays all items in the cart with their quanitites and prices
    void checkout(); // Checkout of the cart
    bool isEmpty() const; //Checks if the cart is empty
    void clearCart(); //Clears the cart
    double calculateTotal() const; //calculates total cost of the cart (+ the tax)
};
    Cart();          // constructor
    ~Cart();      // destructot - free dynamic memory

 
};

    void addItem(const Product& product, int quantity);
    void listItems()
    void checkout();
    bool isEmpty() const;   

];

#endif

