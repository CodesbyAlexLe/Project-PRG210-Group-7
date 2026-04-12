#include <iostream>
#include "CustomerInterface.h"
#include "Department.h"
using namespace std;
extern Department* StoreDepartments;
extern int TotalDepartments;

void CustomerInterface::showMenu()
{
  cout << "\nCustomer Menu:" << endl;
  cout << "1. Show Cart" << endl;
  cout << "2. Browse Departments" << endl;
  cout << "3. Exit" << endl;
  cout << "Enter your choice [1, 2, 3]: ";
]

void CustomerInterface::handleMenu()
{
  int choice;

  do
{
  showMenu();
  choice = getValidatedInt(1, 2);

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
  cart.listCartItems();
  break;
case 2:
  cart.checkout();
  break;
case 3:
  break;
}
} while (choice != 3);
}

void CustomerInterface::browseDepartments()
{
  if (TotalDepartments == 0)
{
  cout << "No departments available." << endl;
  return;
}

for (int i = 0; i < TotalDepartments; i++)
{
  cout << i + 1 << ". " << StoreDepartment[i].getDepartmentName() << endl;
}

cout << "\n1. List Items of a Department" << endl;
cout << "2. Go Back to Main Menu" << endl;
cout << "Enter your choice [1, 2]: ";

int choice = getValidatedInt(1, 2);

if (choice == 2)
{
  return;
}

cout << "Enter department number [0 to go back]: ";

int deptChoice;

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
  cout << "Invalid department number. Enter department number [0 to go back]: ";
}
else
{
  cin.ignore(1000, '\n');
  break;
}
}

int deptIndex = deptChoice - 1;

StoreDepartments[deptIndex].getTotalItems() == 0)
{
  return;
}

cout << "\n1. Add to Cart an Item" << endl;
cout << "2. Go Back to Browse Departments Menu" << endl;
cout << "Enter your choice [1, 2]: ";

int itemMenuChoice = getValidatedInt(1, 2);

if (itemMenuChoice == 2)
{
  return;
}

cout << "Enter item number to buy [0 ton go back]: ";

int itemChoice;
int totalItems = StoreDepartments[deptIndex].getTotalItems();

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

cout << "Enter quantity to buy: ";
int quantity = getValidatedPositiveInt();

Product sleectedProduct = StoreDepartments[deptIndex].getItems()[itemChoice - 1];
cart.addToCart(selectProduct, quantity);

cout << "Item added to cart successfully. " << endl;
}
