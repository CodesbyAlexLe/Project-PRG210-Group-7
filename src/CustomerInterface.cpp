#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CustomerInterface.h"
#include "Department.h"
using namespace std;
// These external variables are declared in another file.
// StoreDepartments points to the dynamic array of departments in the store.
// TotalDepartments keeps track of how many departments currently exist.
extern Department* StoreDepartments;
extern int TotalDepartments;
/*
    Displays the main customer menu.

    What this function does:
    - Shows the customer the list of available actions.
    - Gives options to:
        1. Show Cart
        2. Browse Departments
        3. Exit

    Why this function is useful:
    - Keeps the menu display separate from the menu logic.
    - Makes the code easier to read and reuse.
*/
void CustomerInterface::showMenu()
{
    cout << "\nCustomer Menu:" << endl;
    cout << "1. Show Cart" << endl;
    cout << "2. Browse Departments" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice [1, 2, 3]: ";
}
/*
    Handles the main customer menu.

    What happens here:
    - Repeatedly shows the main menu until the user chooses to exit.
    - Reads and validates the user's menu choice.
    - Uses a switch statement to call the correct function based on the choice.

    Menu options:
    - Case 1: opens the cart menu
    - Case 2: lets the user browse store departments
    - Case 3: exits the customer interface

    Why a do-while loop is used:
    - Ensures the menu appears at least once.
    - Keeps running until the user selects Exit.
*/
void CustomerInterface::handleMenu()
{
    int choice;

    do
    {
        showMenu();
        // Gets a validated menu option from the user
        choice = getValidatedInt(1, 3);

        switch (choice)
        {
        case 1:
            showCartMenu();
            break;
        case 2:
            browseDepartments();
            break;
        case 3:
            cout << "Exiting customer interface..." << endl;
            break;
        }
    } while (choice != 3);
}
/*
    Displays and handles the cart submenu.

    What this function allows the user to do:
    - View all items currently in the cart
    - Checkout and clear the cart
    - Return to the main menu

    How it works:
    - Loops until the user chooses to return.
    - Uses validated input to avoid invalid menu selections.
    - Calls cart member functions depending on the user's choice.
*/

void CustomerInterface::showCartMenu()
{
    int choice;

    do
    {
        cout << "\nShow Cart Menu" << endl;
        cout << "1. List Items" << endl;
        cout << "2. Checkout" << endl;
        cout << "3. Return to Main Menu" << endl;
        cout << "Enter your choice [1, 2, 3]: ";

        choice = getValidatedInt(1, 3);

        switch (choice)
        {
        case 1:
            // Displays all items currently in the shopping cart
            cart.listCartItems();
            break;
        case 2:
            // Completes the purchase and clears the cart
            cart.checkout();
            break;
        case 3:
            // Returns to the main customer menu
            break;
        }
    } while (choice != 3);
}
/*
    Allows the customer to browse store departments and add items to the cart.

    Main steps in this function:
    1. Check if any departments exist.
    2. Display all available departments.
    3. Ask if the user wants to list items in a department or go back.
    4. Let the user choose a department.
    5. Check whether that department has items.
    6. Ask if the user wants to add an item to the cart.
    7. Let the user choose an item and quantity.
    8. Add the selected product to the cart.

    Why this function is important:
    - Connects store browsing with shopping cart functionality.
    - Gives the customer a way to shop from different departments.
*/
void CustomerInterface::browseDepartments()
{
    // If there are no departments in the store, stop immediately
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
// Ask the user what they want to do next
    cout << "\n1. List Items of a Department" << endl;
    cout << "2. Go Back to Main Menu" << endl;
    cout << "Enter your choice [1, 2]: ";

    int choice = getValidatedInt(1, 2);
// Return to main menu if user chooses 2
    if (choice == 2)
    {
        return;
    }
// Ask the user to choose a department
    cout << "Enter department number [0 to go back]: ";

    int deptChoice;
/*
      This loop validates the department number input.

      It checks for:
      - non-numeric input
      - user choosing 0
      - valid department selection

      cin.clear() resets the error state.
      cin.ignore() removes bad input from the buffer.
  */
    while (true)
    {
        cin >> deptChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter department number [0 to go back]: ";
        }
        else if (deptChoice == 0)
        {
            cin.ignore(1000, '\n');
            return;
        }
        else if (deptChoice < 1 || deptChoice > TotalDepartments)
        {
            cin.ignore(1000, '\n');
            cout << "Invalid department number. Enter department number [0 to go back]: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }
// Convert user choice to array index
    int deptIndex = deptChoice - 1;
/*
      Check whether the selected department has any items.

      If the department is empty, there is nothing to display or buy,
      so the function returns.
  */
    if (StoreDepartments[deptIndex].getTotalItems() == 0)
    {
        cout << "No items in this department." << endl;
        return;
    }

    StoreDepartments[deptIndex].listItems();
// Show options for the selected department
    cout << "\n1. Add to Cart an Item" << endl;
    cout << "2. Go Back to Browse Departments Menu" << endl;
    cout << "Enter your choice [1, 2]: ";

    int itemMenuChoice = getValidatedInt(1, 2);

    if (itemMenuChoice == 2)
    {
        return;
    }
// Ask the user which item they want to purchase
    cout << "Enter item number to buy [0 to go back]: ";

    int itemChoice;
    int totalItems = StoreDepartments[deptIndex].getTotalItems();
/*
      This loop validates the item number entered by the user.

      It checks for:
      - invalid input type
      - choosing 0 to go back
      - item number outside valid range
      - correct item selection
  */
    while (true)
    {
        cin >> itemChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter item number to buy [0 to go back]: ";
        }
        else if (itemChoice == 0)
        {
            cin.ignore(1000, '\n');
            return;
        }
        else if (itemChoice < 1 || itemChoice > totalItems)
        {
            cin.ignore(1000, '\n');
            cout << "Invalid item number. Enter item number to buy [0 to go back]: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }
// Ask user how many units they want to buy
    cout << "Enter quantity to buy: ";
    int quantity = getValidatedPositiveInt();
 /*
      Retrieve the chosen product from the selected department.

      itemChoice - 1 is used because array indexing starts at 0,
      but displayed item numbers start at 1.
  */
    Product selectedProduct = StoreDepartments[deptIndex].getItems()[itemChoice - 1];
    // Add the selected product and quantity to the shopping cart
    cart.addToCart(selectedProduct, quantity);

    cout << "Item added to cart successfully." << endl;
}
