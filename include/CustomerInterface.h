#ifndef CUSTOMERINTERFACE_H
#define CUSTOMERINTERFACE_H

#include "Interface.h"
#include "Cart.h"

class CustomerInterface: public Interface {
private:
    Cart cart

public:
    void run();
    void showCartMenu();
    void broseDepartments();
    void listDepartmentItems(int deptIndex);

};

#endif
