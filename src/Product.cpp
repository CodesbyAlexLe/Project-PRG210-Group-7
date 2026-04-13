#define _CRT_SECURE_NO_WARNINGS
// Added for Windows users so Visual Studio does not warn
// about older C-style string functions.
#include <iostream>
#include <cstring>
#include "Product.h"
using namespace std;
/*
    Default constructor for the Product class.

    Purpose:
    - Creates an empty product object.
    - Sets the product name to an empty string.
    - Sets the price to 0.0.
    - Sets the quantity to 0.

    Why this matters:
    - Prevents garbage values in the object.
    - Makes the product safe to use immediately.
*/
Product::Product()
{
    m_name[0] = '\0';
    m_price = 0.0;
    m_quantity = 0;
}
/*
    Parameterized constructor for the Product class.

    Purpose:
    - Creates a product with a given name, price, and quantity.

    Parameters:
    - name: product name
    - price: product price
    - quantity: product quantity in stock

    Why set() is used:
    - Avoids repeating initialization code.
    - Keeps setup logic in one place.
*/
Product::Product(const char* name, double price, int quantity)
{
    set(name, price, quantity);
}
/*
    Sets all product information at once.

    Parameters:
    - name: product name to store
    - price: product price
    - quantity: product quantity

    What this function does:
    - Copies the product name into the fixed-size character array.
    - Stores the price.
    - Stores the quantity.

    Why strncpy is used:
    - Helps prevent copying beyond the size of the array.
    - m_name[99] = '\0' guarantees proper string termination.
*/
void Product::set(const char* name, double price, int quantity)
{
    strncpy(m_name, name, 99);
    m_name[99] = '\0';
    m_price = price;
    m_quantity = quantity;
}
/*
    Returns the product name.

    Return value:
    - A const character pointer to the product name.

    Why const is used:
    - This function only reads the object's data.
    - It does not modify the Product object.
*/
const char* Product::getName() const
{
    return m_name;
}
/*
    Returns the product price.

    Return value:
    - The price stored in m_price.

    Why const is used:
    - This function only reads data.
    - It does not change the object.
*/
double Product::getPrice() const
{
    return m_price;
}
/*
    Returns the product quantity.

    Return value:
    - The quantity stored in m_quantity.

    Why const is used:
    - This function only reads data.
    - It does not modify the object.
*/
int Product::getQuanitity() const
{
    return m_quantity;
}
/*
    Updates the quantity of the product.

    Parameter:
    - quantity: the new quantity value to store

    What this function does:
    - Replaces the current quantity with the new one.
*/
void Product::setQuantity(int quantity)
{
    m_quantity = quantity;
}
/*
    Displays the product information.

    What this function prints:
    - Product name
    - Product price
    - Product quantity

    Example format:
    ProductName - $19.99 (Qty: 5)

    Why const is used:
    - This function only displays information.
    - It does not change the object.
*/
void Product::display() const
{
    cout << m_name << " - $" << m_price << " (Qty: " << m_quantity << ")" << endl;
}

