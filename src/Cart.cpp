#include <iostream>
#include "Cart.h"
using namespace std;

/*
  Default constructor for the cart class.

  Purpose:
  - Initializes a brand new cart object.
  - Sets both dynamic arrays to null ptr because no memory has been allocated yet.
  - Sets totalItems to 0 because the cart starts empty.
  - Sets totalCost to 0.0 because nothing has been added yet.

  Why it matters:
  - Prevents garbage values in the member variables.
  - Makes the object safe to use right away.

*/
Cart::Cart()
{
  cartItems = nullptr;
  quantities = nullptr;
  totalItems = 0;
  totalCost = 0.0;
}
/*
  Destructor for the Cart Class.

  Purpose:
  - Frees dynamically allocated memory when the cart object is destroyed.

  What is being deleted:
  - cartItems: dynamic array of Product objects
  - quantities: dynamic array of integers

  Why this matters:
  - Prevents memory leaks.
  - Since memory was allocated using new[], must be released using delete[].
*/

Cart::~Cart()
{
  delete[] cartItems;
  delete[] quantities;
}
/*
  Adds a product and its quantity into the cart.

  Steps happening in this function:
  1. Create new dynamic arrays that are 1 element larger than the current arrays.
  2. Copy all existing cart items and quantities into the new arrays.
  3. Store the new product and quantity in the last position.
  4. Delete the old arrays to avoid memory leaks.
  5. Point cartItems and quantities to the new arrays.
  6. Increase totalItems since one more entry was added.
  7. Update totalCost by adding price x quantity.

  Why this is needed:
  - Regular arrays in c++ cannot grow automatically.
  - To "resize" an array, we must manually create a larger one, copy old data, then replace the old array.
*/

void Cart::addToCart(const Product& p, int quantity)
{
    Product* newCartItems = new Product[totalItems + 1];
    int* newQuantities = new int[totalItems + 1];

    for (int i = 0; i < totalItems; i++)
    {

        newCartItems[i] = cartItems[i];
        newQuantities[i] = quantities[i];
    }

    newCartItems[totalItems] = p;
    newQuantities[totalItems] = quantity;

    delete[] cartItems;
    delete[] quantities;

    cartItems = newCartItems;
    quantities = newQuantities;

    totalItems++;

    totalCost += p.getPrice() * quantity;
}

void Cart::listCartItems() const
{
  if (totalItems == 0)
  {
      cout << "No items in the cart." << endl;
      return;
  }

  for (int i = 0; i < totalItems; i++)
  {
      cout << i + 1 << ". " 
           << cartItems[i].getName()
           << " | Qty: " << quantities[i]
           << " | Price: $" << cartItems[i].getPrice() << endl;
  }
  cout << "Total with tax: $" << calculateTotal() << endl;
}
void Cart::checkout()
{
  if(isEmpty())
  {
    cout << "No items in the cart" << endl;
    return;
  }

  cout << "Thank you for your purchase" << endl;
  clearCart();
}

bool Cart::isEmpty() const
{
  return totalItems == 0;
}

void Cart::clearCart()
{
  delete[] cartItems;
  delete[] quantities;

  cartItems = nullptr;
  quantities = nullptr;
  totalItems = 0;
  totalCost = 0.0;
}

double Cart::calculateTotal() const
{
  return totalCost * 1.13;
}
