#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Product.h"
using namespace std;

/*
    Department class
    This class represents the departments in the grocery store
*/

class Department {
private:
  char departmentName[100]; //name of department
  Product* items; //Product in the department
  int totalItems; //Number of items in department

public:
  //Constructors
     Department(); //Default (empty)
     Department(const char* name);  //Innitializes the deparments
  //Destructor
     ~Department(); //Used to free the dynamically allocated items in the array

     void setDepartmentName(const char* name); //Sends and get department name
     const char* getDepartmentName() const;

     int getTotalItems() const; //Gets total number items in this department
     Product* getItems() const; //get pointer to items array

     void addItem(const Product& p); //Adds a new product to the department
     void listItems() const; //Displays all items in department

#endif
