#define _CRT_SECURE_NO_WARNINGS
// Added for Windows users so Visual Studio does not warn about older C-style functions.
#include <iostream>
#include <fstream>
#include <cstring>
#include "ManagerInterface.h"
using namespace std;
// These variables are declared in another source file and shared globally.
// StoreDepartments points to the dynamic array of all store departments.
// TotalDepartments stores how many departments currently exist.
// csvFile stores the file name used to save the store data.
extern Department* StoreDepartments;
extern int TotalDepartments;
extern const char* csvFile;
/*
    Displays the manager menu.

    What this function does:
    - Shows all available manager options on the screen.
    - Lets the manager choose actions such as:
      1. List Departments
      2. Add Department
      3. Add Item to Department
      4. Save Changes to CSV
      5. Exit

    Why this function is useful:
    - Keeps menu display separate from menu processing logic.
    - Makes the code cleaner and easier to maintain.
*/
void ManagerInterface::showMenu()
{
    cout << "\nManager Menu:" << endl;
    cout << "1. List Departments" << endl;
    cout << "2. Add Department" << endl;
    cout << "3. Add Item to Department" << endl;
    cout << "4. Save Changes to CSV" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice [1, 2, 3, 4, 5]: ";
}
/*
    Handles the manager menu loop.

    What happens here:
    - Repeatedly displays the manager menu.
    - Gets a validated menu choice from the user.
    - Uses a switch statement to run the selected manager action.
    - Continues looping until the manager chooses to exit.

    Why a do-while loop is used:
    - Ensures the menu appears at least once.
    - Keeps the interface active until the exit option is selected.
*/
void ManagerInterface::handleMenu()
{
    int choice;

    do
    {
        showMenu();
        choice = getValidatedInt(1, 5);

        switch (choice)
        {
        case 1:
            listDepartments();
            break;
        case 2:
            addDepartment();
            break;
        case 3:
            addItemToDepartment();
            break;
        case 4:
            saveToCSV();
            break;
        case 5:
            cout << "Exiting manager interface..." << endl;
            break;
        }
    } while (choice != 5);
}
/*
    Displays all departments currently in the store.

    What this function does:
    - Checks whether any departments exist.
    - If none exist, prints a message and returns.
    - Otherwise, loops through the department array
      and displays each department name.

    Why this is useful:
    - Lets the manager view the current department list.
*/
void ManagerInterface::listDepartments()
{
    if (TotalDepartments == 0)
    {
        cout << "No departments available." << endl;
        return;
    }

    for (int i = 0; i < TotalDepartments; i++)
    {
        cout << i + 1 << ". " << StoreDepartments[i].getDepartmentName() << endl;
    }
}
/*
    Adds a new department to the store.

    Steps:
    1. Ask the manager to enter a department name.
    2. Create a new dynamic array one element larger
       than the current department array.
    3. Copy all existing departments into the new array.
    4. Add the new department at the last position.
    5. Delete the old department array.
    6. Update StoreDepartments to point to the new array.
    7. Increase TotalDepartments.

    Why this is needed:
    - Arrays in C++ cannot resize automatically.
    - A new larger array must be created manually
      to store an additional department.
*/
void ManagerInterface::addDepartment()
{
    char name[100];
    cout << "Enter department name: ";
    // getValidatedInt already cleared the newline, so getline works directly
    getValidatedNonEmptyString(name, 100);
// Create a larger department array
    Department* newDepts = new Department[TotalDepartments + 1];
    // Copy old departments into the new array
    for (int i = 0; i < TotalDepartments; i++)
    {
        // Add the new department at the end
        newDepts[i] = StoreDepartments[i];
    }
    newDepts[TotalDepartments] = Department(name);
    // Delete old array and replace it with the new one
    delete[] StoreDepartments;
    StoreDepartments = newDepts;
    // Increase department count
    TotalDepartments++;

    cout << "Department added successfully." << endl;
}
/*
    Adds a new item to a selected department.

    Main steps:
    1. Check whether any departments exist.
    2. Display all department names.
    3. Ask the manager to choose a department.
    4. Validate the department number input.
    5. Show the current items in that department.
    6. Ask for the new item's name, price, and quantity.
    7. Create a Product object with the entered information.
    8. Add that product to the chosen department.

    Why this function is important:
    - Lets the manager update inventory by adding new products.
*/
void ManagerInterface::addItemToDepartment()
{
    if (TotalDepartments == 0)
    {
        cout << "No departments available." << endl;
        return;
    }
// Display all department names
    for (int i = 0; i < TotalDepartments; i++)
    {
        cout << i + 1 << ". " << StoreDepartments[i].getDepartmentName() << endl;
    }

    cout << "Enter department number [0 to go back]: ";

    int dep;
    /*
        Validate the department number entered by the user.

        This loop checks for:
        - invalid input type
        - 0 to return
        - values outside the valid department range
    */
    while (true)
    {
        cin >> dep;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter department number [0 to go back]: ";
        }
        else if (dep == 0)
        {
            cin.ignore(1000, '\n');
            return;
        }
        else if (dep < 1 || dep > TotalDepartments)
        {
            cin.ignore(1000, '\n');
            cout << "Enter department number [0 to go back]: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }
// Show current items in the selected department
    StoreDepartments[dep - 1].listItems();

    char itemName[100];
    cout << "Enter item name: ";
    // after cin >> dep + cin.ignore, buffer is clean for getline
    getValidatedNonEmptyString(itemName, 100);

    cout << "Enter item price: ";
    double price = getValidatedPositiveDouble();

    cout << "Enter item quantity: ";
    int qty = getValidatedPositiveInt();
// Create a product object using the entered data
    Product p(itemName, price, qty);
    // Add the new product to the selected department
    StoreDepartments[dep - 1].addItem(p);

    cout << "Item added successfully." << endl;
}
/*
    Saves all department and product data to a CSV file.

    What this function does:
    - Opens the CSV file for writing.
    - Writes the total number of departments.
    - For each department, writes:
      * department name
      * total number of items
    - Then writes each product's:
      * name
      * price
      * quantity
    - Closes the file after saving.

    Why this is useful:
    - Preserves store data so changes are not lost when the program ends.
*/
void ManagerInterface::saveToCSV()
{
    ofstream file(csvFile);
// Write total number of departments first
    file << TotalDepartments << endl;

    for (int i = 0; i < TotalDepartments; i++)
    {
        // Write department information
        file << StoreDepartments[i].getDepartmentName() << ","
             << StoreDepartments[i].getTotalItems() << endl;
// Get the list of products in the department
        Product* list = StoreDepartments[i].getItems();
        // Write each product's information
        for (int j = 0; j < StoreDepartments[i].getTotalItems(); j++)
        {
            file << list[j].getName() << ","
                 << list[j].getPrice() << ","
                 << list[j].getQuanitity() << endl;
        }
    }

    file.close();
    cout << "Changes saved successfully." << endl;
}
