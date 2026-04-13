#ifndef CART_H
#define CART_H

#include "Product.h."

class Cart {

private:
    Product* items;                    // dynamic array of products
    int* quantities;                  // quantity for each time
    int totalItems;                  // count of items in cart
    double totalCost;               // total cost before tax                                   
    double totalWithTax;            // total cost with 13% tax


public:
    Cart();          // constructor
    ~Cart();      // destructot - free dynamic memory

 
};

    void addItem(const Product& product, int quantity);
    void listItems()
    void checkout();
    bool isEmpty() const;   

];

#endif
