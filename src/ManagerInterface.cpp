#include <iostream>
#include "ManagerInterface.h"
#include "Department.h"
#include "Product.h"
using namespace std;

extern Department* StoreDepartments;
extern int TotalDepartments;
extern const char* csvFile;

void savetoCSV();

void ManagerInterface::showMenu()
{
  cout << "\nManager Menu:" << endl;
  cout << "1. List Departments" << endl;
  cout << "2. Add Department" << endl;
  cout << "3. Add Item to Department" << endl;
  cout << "4. Save Changes to CSV" << endl;
  cout << "Enter your choice [1, 2, 3, 4, 5]: " << endl;
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
  saveChangesToCSV();
  break;
case 5:
  cout << "Exiting manager interface..." << endl;
}
} while (choice != 5);
}

void ManagerInterface::listDepartments()
{
  if (TotalDepartments == 0)
{
  cout << "No departments available. " << endl;
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
  getValidatedNonEmptyString(name, 100);

Department* newDepartments = new Department[TotalDepartments + 1];

for (int i = 0; i < TotalDepartments; i++)
{
  newDepartments[i] = StoreDepartments[i];
}

newDepartments[TotalDepartments] = Department(name);
delete[] StoreDepartments;
StoreDepartments = newDepartments;
TotalDepartments++;

cout << "Department added successfully. " << endl;
}

void ManagerInterface::addItemToDepartment()
{
  if (TotalDepartments == 0)
{
  cout << "No departments available. " << endl;
  return;
}

listDepartments();
cout << "Enter a department number [0 to go back]: ";

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
  cin.ignore(1000, '\n')
  return;
}
else if (deptChoice < 1 || deptChoice > TotalDepartments)
{
  cin.ignore(1000, '\n')
  cout << "Invalid department number. Enter department number [0 to go back]: ";
}
else
{
  cin.ignore(1000, '\n');
  break;
}
}
char itemName[100];
double price;
int quantity;

cout << "Enter item name: ";
getValidatedNonEmptyString(itemName, 100);

cout << "Enter item price: ";
price = getValidatedPositiveDouble();

cout << "Enter item quantity: ";
quantity = getValidatedPositiveInt();

Product newProduct(itemName, price, quantity);
StoreDepartments[deptChoice - 1].addItem(newProduct);

cout << "Item added successfully. " << endl;
}

void ManagerInterface::saveChangesToCSV()
{
  saveToCSV();
  cout << "Changes saved successfully. " << endl;
}
