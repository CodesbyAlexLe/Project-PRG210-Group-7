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
  
// Copy existing items and quantities into the new larger arrays
  
    for (int i = 0; i < totalItems; i++)
    {

        newCartItems[i] = cartItems[i];
        newQuantities[i] = quantities[i];
    }
// Add the new product and its quantity at the end
    newCartItems[totalItems] = p;
    newQuantities[totalItems] = quantity;
// Delete old arrays because they are no longer needed
    delete[] cartItems;
    delete[] quantities;
// Update pointers so the cart now uses the new arrays
    cartItems = newCartItems;
    quantities = newQuantities;
// Increase the number of items stored in the cart
    totalItems++;
// Add this product's cost to the running subtotal
    totalCost += p.getPrice() * quantity;
}
/*
  Displays all items currently in the cart.

  What this function does:
  - First checks if the cart is empty.
  - If empty, prints a message and stops.
  - Otherwise, loops through each stored product and displays:
  * item number
  * product name
  * quantity
  * unit price
  - Finally prints the total cost including tax.

  Why const is used:
  - This function only displays information.
  - It does not modify the cart object.
*/
void Cart::listCartItems() const
{
  if (totalItems == 0)
  {
      cout << "No items in the cart." << endl;
      return;
  }
// Loop through every item in the cart and display its details
  for (int i = 0; i < totalItems; i++)
  {
      cout << i + 1 << ". " 
           << cartItems[i].getName()
           << " | Qty: " << quantities[i]
           << " | Price: $" << cartItems[i].getPrice() << endl;
  }
  // Show final total after tax
  cout << "Total with tax: $" << calculateTotal() << endl;
}
/* 
  Completes the checkout process.

  What happens here:
  - Checks if the cart is empty
  - If empty, informs the user and stops
  - If not empty, prints a thank-you message
  - Then clears the cart after checkout is complete

  Why clearCart() is called:
  - Once purchased is finished the cart should be reset so it can be used again for a new order
*/
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
/*
  Checks wheter the cart is empty.

  Return value:
  - true -> cart has no items
  - false -> cart contains at least one item

  Why this is useful:
  - Lets other functions quickly check cart status without repeating the same condition
*/

bool Cart::isEmpty() const
{
  return totalItems == 0;
}
/*
  Removes all items from the cart and resets its state.

  Steps:
  1. Delete the dynamic arrays to free memory
  2. Set pointers to nullptr so they do not point to deleted memory
  3. Reset totalItems to 0
  4. Reset totalCost to 0.0

  Why setting point to nullptr matter:
  - Prevents dangling pointers
  - Makes the object safer to reuse later
*/

void Cart::clearCart()
{
  delete[] cartItems;
  delete[] quantities;

  cartItems = nullptr;
  quantities = nullptr;
  totalItems = 0;
  totalCost = 0.0;
}
/*
  Calculates the final total including tax.

  How it works:
  - totalCost stores the subtotal before tax
  - This function multiplies subntotal by 1.13 to add 13% tax

  Return value:
  - Final price including tax.
*/

double Cart::calculateTotal() const
{
  return totalCost * 1.13;
}
