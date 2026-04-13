#ifndef MANAGERINTERFACE_H
#define MANAGERINTERFACE_H

#include "Interface. h"

class ManagerInterface: public Interface {

public:
    void run()
    void listDepartments() const;
    void addDepartment();
    void addItemToDepartment();
    void saveToCSV() const;
};

#endif