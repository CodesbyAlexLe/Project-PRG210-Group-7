#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Product.h"
using namespace std;

Product::Product()
{
    m_name[0] = '\0';
    m_price = 0.0;
    m_quantity = 0;
}

Product::Product(const char* name, double price, int quantity)
{
    set(name, price, quantity);
}

void Product::set(const char* name, double price, int quantity)
{
    strncpy(m_name, name, 99);
    m_name[99] = '\0';
    m_price = price;
    m_quantity = quantity;
}

const char* Product::getName() const
{
    return m_name;
}

double Product::getPrice() const
{
    return m_price;
}

int Product::getQuanitity() const
{
    return m_quantity;
}

void Product::setQuantity(int quantity)
{
    m_quantity = quantity;
}

void Product::display() const
{
    cout << m_name << " - $" << m_price << " (Qty: " << m_quantity << ")" << endl;
}

