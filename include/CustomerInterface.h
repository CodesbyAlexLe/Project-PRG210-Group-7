#ifndef CUSTOMERINTERFACE_H
#define CUSTOMERINTERFACE_H
// Include gaurd prevents this header from being included multiple times
#include "Interface.h"
#include "Cart.h"

// CustomerInterface manages the customer side of the store system
// It allows the user to view menus, browse departments, and use a cart
class CustomerInterface: public Interface 
{
private:
// Stores the customers shopping cart
  Cart cart;

public:
// Display the main customer menu
  void showMenu();
// Handles the main customer menu logic
  void handleMenu();

private:
// Displays and handles the cart submenu
  void showCartMenu();
// Lets the customer browse departments and add items to the cart
  void browseDepartments();

};

#endif
