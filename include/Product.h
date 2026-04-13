#ifndef PRODUCT_H
#define PRODUCT_H
using namespace std;
/*
Product class
It stores the basic information for each item, such as name, price, and quantity
Manages items in the store and items selected by the customer
*/
class Product {
private:
    char m_name[100]; //Item name or Product
    double m_price; //store the price of the item
    int m_quantity; //stores the available quantity of the item

public:
    Product(); //constructor default

    // Initializes product with given name, price, and quantity
    Product(const char* name, double price, int quantity);

    //Setting all product details
    void set(const char* name, double price, int quantity);

    //getter function
    const char* getName() const; //Getting name
    double getPrice() const; //Geting price
    int getQuanitity() const; //Getting quality

    void setQuantity(int quantity);

    //Displays product details
    void display() const;
};

#endif
