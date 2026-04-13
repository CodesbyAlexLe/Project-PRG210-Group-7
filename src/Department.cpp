#define _CRT_SECURE_NO_WARNINGS
// Added for Windows users so older C string functions can be used
// without Visual Studio showing secure function warnings.
#include <iostream>
#include <cstring>
#include "Department.h"
using namespace std;

// Default constructor initializes department with empty name and no items
Department::Department()
{
    departmentName[0] = '\0';
    items = nullptr;
    totalItems = 0;
}

// Parameterized constructor sets the department name and initializes empty item list
Department::Department(const char* name)
{
    strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
    items = nullptr;
    totalItems = 0;
}

// Copy constructor performs a deep copy so each department has its own items array
Department::Department(const Department& other)
{
    strncpy(departmentName, other.departmentName, 99);
    departmentName[99] = '\0';
    totalItems = other.totalItems;
    if (other.items != nullptr && totalItems > 0)
    {
        items = new Product[totalItems];
        for (int i = 0; i < totalItems; i++)
        {
            items[i] = other.items[i];
        }
    }
    else
    {
        items = nullptr;
    }
}

// Assignment operator performs a deep copy and handles self-assignment safely
Department& Department::operator=(const Department& other)
{
    if (this == &other)
        return *this;

    delete[] items;

    strncpy(departmentName, other.departmentName, 99);
    departmentName[99] = '\0';
    totalItems = other.totalItems;

    if (other.items != nullptr && totalItems > 0)
    {
        items = new Product[totalItems];
        for (int i = 0; i < totalItems; i++)
        {
            items[i] = other.items[i];
        }
    }
    else
    {
        items = nullptr;
    }
    return *this;
}

// Destructor frees the dynamically allocated items array
Department::~Department()
{
    delete[] items;
}

// Sets the department name safely using strncpy
void Department::setDepartmentName(const char* name)
{
    strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
}

// Returns the department name
const char* Department::getDepartmentName() const
{
    return departmentName;
}

// Returns the total number of items in the department
int Department::getTotalItems() const
{
    return totalItems;
}

// Returns a pointer to the items array
Product* Department::getItems() const
{
    return items;
}

// Adds a new product by creating a larger array, copying existing items, and appending the new one
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

// Prints all items in the department with their name, price, and quantity
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

