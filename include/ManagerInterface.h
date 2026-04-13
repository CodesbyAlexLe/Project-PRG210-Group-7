#ifndef MANAGERINTERFACE_H
#define MANAGERINTERFACE_H

#include "Interface. h"

class ManagerInterface: public Interface 
{

public:
  void showMenu();
  void handleMenu();

private:
  void listDepartments();
  void addDepartment();
  void addItemToDepartment();
  void saveChangesToCSV();

};

#endif
