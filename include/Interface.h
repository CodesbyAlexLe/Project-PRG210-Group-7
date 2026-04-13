#ifndef INTERFACE_H
#define INTERFACE_H

#include "Department.h"
#include "Cart.h"

/*
    interface base class for both manager and customer interfaces
    demonstrates inheritance + polymorphism
        - Inheritance (Manager interface and customer interface inherit from this)
        - Polymorphism 
 */
class Interface {
public:
    virtual void showMenu() = 0; //Displays the menu
    virtual void handleMenu() = 0; // handles users' input and performs actions based on menu choice
    virtual ~Interface(); //Destructor 

protected:
    int getValidatedInt(int min, int max); //Validates integer input within a given range 
    int getValidatedPositiveInt();
    double getValidatedPositiveDouble();
    void getValidatedNonEmptyString(char* str, int size);
 
};
#endif
