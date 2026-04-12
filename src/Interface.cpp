#include <iostream>
#include <limits>
#include <cstring>
#include "Interface.h"
using namespace std;

Interface::~Interface()
{
}

int Interface::getValidatedInt(int min, in max)
{
  int choice;
  while (true)
{
  cin >> choice;
  if (cin.fail() || choice < min || choice > max)
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Invalid input. Try again: ";
}
else
{
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}
}
}

int Interface::getValidatedPositiveInt()
{
  int value;

  while (true)
{
  cin >> value;
  if (cin.fail() || value <= 0)
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Invalid input. Enter a positive interger: ";
}
else
{
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return value;
}
}
}

double Interface::getValidatedPositiveDouble()
{
    doubler value;

  while (true)
{
  cin >> value

  if (cin.fail() || value <= 0)
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Invalid input. Enter a positive number: ";
}
else
{
  cin.ignore(numeric_limits<streamsize>::max(), '\n';
  return value;
}
}
}

void Interface::getValidatedNonEmptyString(char* str, int size)
{
  while (true)
{
  cin.getline(str, size);

  if (strlen(str) == 0)
{
  cout << "Input cannot be empty. Try again: ";
}
else
{
  return;
}
}
}
