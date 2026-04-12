#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Product.h"
using namespace std;

//Department class stores multiple products
class Department {
private:
  char departmentName[100]; //name of department
  Product* items;
  int totalItems; //Number of items in department

public:
  //Constructors
     Department();
     Department(const char* name); 
};

#endif
