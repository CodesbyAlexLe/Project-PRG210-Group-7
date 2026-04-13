#define _CRT_SECURE_NO_WARNINGS
// Added for Windows users so older C string functions can be used
// without Visual Studio showing secure function warnings.
#include <iostream>
#include <cstring>
#include "Department.h"
using namespace std;
/*
    Default constructor for the Department class.

    Purpose:
    - Creates an empty department object.
    - Sets the department name to an empty string.
    - Sets the items pointer to nullptr because no products
      have been added yet.
    - Sets totalItems to 0 since the department starts empty.

    Why this matters:
    - Prevents garbage values in the object.
    - Makes the object safe to use immediately.
*/
Department::Department()
{
    departmentName[0] = '\0';
    items = nullptr;
    totalItems = 0;
}
/*
    Parameterized constructor for the Department class.

    Purpose:
    - Creates a department with a given name.
    - Initializes the items pointer to nullptr because
      no products exist yet.
    - Sets totalItems to 0.

    Parameter:
    - name: the name to store in the departmentName array

    Why strncpy is used:
    - It copies up to a limited number of characters.
    - This helps avoid overflowing the character array.
    - departmentName[99] = '\0' ensures the string is properly terminated.
*/
Department::Department(const char* name)
{
    strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
    items = nullptr;
    totalItems = 0;
}
/*
    Destructor for the Department class.

    Purpose:
    - Frees the dynamically allocated array of products.

    Why this matters:
    - Prevents memory leaks when the Department object
      is destroyed.
*/
Department::~Department()
{
    delete[] items;
}
/*
    Sets or changes the department name.

    Parameter:
    - name: the new name to copy into departmentName

    Why strncpy is used:
    - Prevents writing beyond the fixed-size array.
    - The last character is manually set to '\0'
      to guarantee proper string termination.
*/
void Department::setDepartmentName(const char* name)
{
    strncpy(departmentName, name, 99);
    departmentName[99] = '\0';
}
/*
    Returns the name of the department.

    Return value:
    - A const character pointer to the departmentName array.

    Why const is used:
    - This function only reads data.
    - It does not modify the object.
*/
const char* Department::getDepartmentName() const
{
    return departmentName;
}
/*
    Returns the total number of products in the department.

    Return value:
    - totalItems, which tracks how many Product objects
      are currently stored.

    Why const is used:
    - The function only reads the value.
*/
int Department::getTotalItems() const
{
    return totalItems;
}
/*
    Returns the dynamic array of products stored in the department.

    Return value:
    - A pointer to the Product array.

    Why this is useful:
    - Lets other parts of the program access the products
      inside the department.

    Why const is used:
    - This function does not change the Department object.
*/
Product* Department::getItems() const
{
    return items;
}
/*
    Adds a new product to the department.

    Steps:
    1. Create a new dynamic array one element larger
       than the current array.
    2. Copy all existing products into the new array.
    3. Store the new product in the last position.
    4. Delete the old array to avoid memory leaks.
    5. Point items to the new array.
    6. Increase totalItems.

    Why this is needed:
    - Normal arrays in C++ cannot resize automatically.
    - To grow the list, a new larger array must be created manually.
*/
void Department::addItem(const Product& p)
{
    Product* temp = new Product[totalItems + 1];
// Copy old products into the new larger array
    for (int i = 0; i < totalItems; i++)
    {
        temp[i] = items[i];
    }
    // Add the new product at the end of the array
    temp[totalItems] = p;
// Delete old memory and replace it with the new array
    delete[] items;
    items = temp;
    // Increase the number of stored items
    totalItems++;
}
/*
    Displays all products in the department.

    What this function does:
    - Checks if the department is empty.
    - If empty, prints a message and returns.
    - Otherwise, loops through each product and displays:
      * item number
      * product name
      * price
      * quantity

    Why const is used:
    - The function only displays information.
    - It does not modify the department object.
*/
void Department::listItems() const
{
    if (totalItems == 0)
    {
        cout << "No items in this department." << endl;
        return;
    }
    // Loop through each product and print its details
    for (int i = 0; i < totalItems; i++)
    {
        cout << i + 1 << ". "
             << items[i].getName()
             << " - $" << items[i].getPrice()
             << " - Qty: " << items[i].getQuanitity() << endl;
    }
}

