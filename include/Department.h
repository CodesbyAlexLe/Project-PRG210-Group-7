#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Product.h"

class Department {
private:
    char name[100];
    Product* items;
    int totalItems;

public:
    Department();
    Department(const char* deptName);
    ~Department();

    void addItem(const Product& product);
    void listItem() const;
    const char* getName() const;
    int getTotalItems() const;
    Products& getItem(int index);

};

#endif