#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "ManagerInterface.h"
using namespace std;
extern Department* StoreDepartments;
extern int TotalDepartments;
extern const char* csvFile;

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

void ManagerInterface::addDepartment()
{
    char name[100];
    cout << "Enter department name: ";
    // getValidatedInt already cleared the newline, so getline works directly
    getValidatedNonEmptyString(name, 100);

    Department* newDepts = new Department[TotalDepartments + 1];
    for (int i = 0; i < TotalDepartments; i++)
    {
        newDepts[i] = StoreDepartments[i];
    }
    newDepts[TotalDepartments] = Department(name);
    delete[] StoreDepartments;
    StoreDepartments = newDepts;
    TotalDepartments++;

    cout << "Department added successfully." << endl;
}

void ManagerInterface::addItemToDepartment()
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

    cout << "Enter department number [0 to go back]: ";

    int dep;
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

    StoreDepartments[dep - 1].listItems();

    char itemName[100];
    cout << "Enter item name: ";
    // after cin >> dep + cin.ignore, buffer is clean for getline
    getValidatedNonEmptyString(itemName, 100);

    cout << "Enter item price: ";
    double price = getValidatedPositiveDouble();

    cout << "Enter item quantity: ";
    int qty = getValidatedPositiveInt();

    Product p(itemName, price, qty);
    StoreDepartments[dep - 1].addItem(p);

    cout << "Item added successfully." << endl;
}

void ManagerInterface::saveToCSV()
{
    ofstream file(csvFile);

    file << TotalDepartments << endl;

    for (int i = 0; i < TotalDepartments; i++)
    {
        file << StoreDepartments[i].getDepartmentName() << ","
             << StoreDepartments[i].getTotalItems() << endl;

        Product* list = StoreDepartments[i].getItems();
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
