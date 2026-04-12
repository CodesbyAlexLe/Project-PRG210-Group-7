#ifndef CUSTOMERINTERFACE_H
#define CUSTOMERINTERFACE_H
#include "Interface.h"
#include "Cart.h"

class CustomerInterface: public Interface 
{
private:
  Cart cart;

public:
  void showMenu();
  void handleMenu();

private:
  void showCartMenu();
  void browseDepartments();

};

#endif
