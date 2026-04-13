#define _CRT_SECURE_NO_WARNINGS
// Added for Windows users to avoid secure CRT warnings in Visual Studio.
#include <iostream>
#include <limits>
#include <cstring>
#include "Interface.h"
using namespace std;
/*
    Virtual destructor for the Interface base class.

    Purpose:
    - Allows proper cleanup when a derived class object
      is deleted through a base class pointer.

    Why this matters:
    - Since Interface is meant to be a base class,
      it should have a virtual destructor.
    - This helps ensure derived class destructors run correctly.
*/
Interface::~Interface()
{
}
/*
    Gets and validates an integer input within a specific range.

    Parameters:
    - min: the smallest allowed value
    - max: the largest allowed value

    What this function does:
    - Repeatedly asks for input until the user enters
      a valid integer between min and max.
    - If the input is invalid, it clears the error state,
      removes bad input from the buffer, and asks again.

    Why this is useful:
    - Prevents the program from using invalid menu choices
      or out-of-range values.

    Return value:
    - A valid integer between min and max.
*/
int Interface::getValidatedInt(int min, int max)
{
    int choice;
    while (true)
    {
        cin >> choice;
        // Check for invalid input or value outside allowed range
        if (cin.fail() || choice < min || choice > max)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
        }
        else
        {
            // Clear remaining input and return valid value
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}
/*
    Gets and validates a positive integer.

    What this function does:
    - Repeatedly reads input until the user enters
      an integer greater than 0.
    - Rejects letters, symbols, negative numbers, and zero.

    Why this is useful:
    - Ensures values like quantity, amount, or count
      are always valid and positive.

    Return value:
    - A valid positive integer.
*/
int Interface::getValidatedPositiveInt()
{
    int value;
    while (true)
    {
        cin >> value;
        // Reject invalid input and non-positive values
        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a positive integer: ";
        }
        else
        {
            // Clear remaining input and return valid number
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}
/*
    Gets and validates a positive decimal number.

    What this function does:
    - Repeatedly reads input until the user enters
      a number greater than 0.
    - Rejects invalid input, zero, and negative values.

    Why this is useful:
    - Helps safely read values like prices or costs.

    Return value:
    - A valid positive double value.
*/
double Interface::getValidatedPositiveDouble()
{
    double value;
    while (true)
    {
        cin >> value;
        // Reject invalid input and non-positive values
        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a positive number: ";
        }
        else
        {
            // Clear remaining input and return valid number
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}
/*
    Gets and validates a non-empty string.

    Parameters:
    - str: character array where the input will be stored
    - size: maximum number of characters allowed

    What this function does:
    - Uses getline to read a full line of text.
    - Repeats until the user enters something non-empty.
    - Rejects blank input.

    Why this is useful:
    - Prevents empty names or blank text fields
      from being accepted.
*/
void Interface::getValidatedNonEmptyString(char* str, int size)
{
    while (true)
    {
        cin.getline(str, size);
        // Check if the user entered an empty string
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

}
