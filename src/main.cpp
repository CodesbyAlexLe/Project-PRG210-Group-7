#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Interface.h"
#include "ManagerInterface.h"
#include "CustomerInterface.h"
using namespace std;

// Global array of departments shared across all files
Department* StoreDepartments = nullptr;

// Tracks the total number of departments currently in the system
int TotalDepartments = 0;

// Path to the CSV file used to save and load store data
const char* csvFile = "data/store.csv";

// Reads department and product data from the CSV file into memory
void loadCSV()
{
    ifstream file(csvFile);
    if (!file.is_open())
    {
        // No CSV file found, start with empty store
        return;
    }

    string line;

    // First line contains the total number of departments
    getline(file, line);
    TotalDepartments = stoi(line);
    StoreDepartments = new Department[TotalDepartments];

    for (int i = 0; i < TotalDepartments; i++)
    {
        // Each department line has name and item count separated by a comma
        getline(file, line);
        stringstream ss(line);
        string deptName;
        int itemCount;
        getline(ss, deptName, ',');
        ss >> itemCount;

        // Read each item and add it to the department
        for (int j = 0; j < itemCount; j++)
        {
            getline(file, line);
            stringstream cs(line);
            string iname;
            double price;
            int qty;
            getline(cs, iname, ',');
            cs >> price;
            cs.ignore();
            cs >> qty;
            Product p(iname.c_str(), price, qty);
            StoreDepartments[i].addItem(p);
        }

        StoreDepartments[i].setDepartmentName(deptName.c_str());
    }

    file.close();
}

int main()
{
    // Load existing data from CSV before showing the menu
    loadCSV();

    cout << "--- GROCERY STORE MANAGEMENT SYSTEM ---" << endl;

    int choice;
    Interface* user = nullptr;

    do
    {
        cout << "\n1. Customer" << endl;
        cout << "2. Manager" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice [1, 2, 3]: ";
        cin >> choice;

        // Validate the main menu input
        if (cin.fail() || choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        if (choice == 1)
        {
            // Create a customer interface and run its menu using polymorphism
            user = new CustomerInterface();
            user->handleMenu();
            delete user;
            user = nullptr;
        }
        else if (choice == 2)
        {
            // Create a manager interface and run its menu using polymorphism
            user = new ManagerInterface();
            user->handleMenu();
            delete user;
            user = nullptr;
        }

    } while (choice != 3);

    // Free the global departments array before exiting
    delete[] StoreDepartments;
    return 0;
}
