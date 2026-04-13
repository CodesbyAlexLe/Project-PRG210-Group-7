#define _CRT_SECURE_NO_WARNINGS
// ADDEDED FOR WINDOWS USER
#include <iostream>
#include <cstring>
#include "Department.h"
using namespace std;

Department::Department()
{
    departmentName[0] = '\0';
    items = nullptr;
    totalItems = 0;
}

Department::Department(const char* name)
{
    strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
    items = nullptr;
    totalItems = 0;
}

Department::~Department()
{
    delete[] items;
}

void Department::setDepartmentName(const char* name)
{
    strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
}

const char* Department::getDepartmentName() const
{
    return departmentName;
}

int Department::getTotalItems() const
{
    return totalItems;
}

Product* Department::getItems() const
{
    return items;
}

void Department::addItem(const Product& p)
{
    Product* temp = new Product[totalItems + 1];

    for (int i = 0; i < totalItems; i++)
    {
        temp[i] = items[i];
    }
    temp[totalItems] = p;

    delete[] items;
    items = temp;
    totalItems++;
}

void Department::listItems() const
{
    if (totalItems == 0)
    {
        cout << "No items in this department." << endl;
        return;
    }
    for (int i = 0; i < totalItems; i++)
    {
        cout << i + 1 << ". "
             << items[i].getName()
             << " - $" << items[i].getPrice()
             << " - Qty: " << items[i].getQuanitity() << endl;
    }
}

