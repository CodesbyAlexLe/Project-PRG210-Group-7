#ifndef INTERFACE_H
#define INTERFACE_H

#include "Department.h"
#include "Cart.h"

/*
    interface base class for both manager and customer interfaces
    demonstrates inheritance + polymorphism
 */
class Interface {
public:
    virtual void showMenu() = 0;
    virtual void handleMenu() = 0;
    virtual ~Interface();

protected:
    int getValidatedInt(int min, int max);
    int getValidatedPositiveInt();
    double getValidatedPositiveDouble();
    void getValidatedNonEmptyString(char* str, int size);
 
};
#endif
