#ifndef MANAGERINTERFACE_H
#define MANAGERINTERFACE_H

#include "Interface.h" //Including the base interface class

/*
    Manager interface class
    This class represents the manager side of the program, as it inherits from the interface
    and provides functions for managing departments and products in the grocery store
*/

class ManagerInterface: public Interface 
{

public:
  void showMenu(); //Displays all the manager menu options to the user
  void handleMenu(); //Handles input and calls the correct functions based on choice

private:
  void listDepartments(); // Displays all available departments in the store
  void addDepartment(); //prompts user to add a new department and adds it to the system
  void addItemToDepartment(); //Allows manager to add a new item to a selected department
  void saveChangesToCSV(); //Saves all departments and items to a csv file
    void run()
    void listDepartments() const;
    void addDepartment();
    void addItemToDepartment();
    void saveToCSV() const;
};

#endif
