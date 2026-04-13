#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
public:
    virtual void run() = 0;
    virtual ~Interface() {}


protected: 
    int getValidInt(int min, int max) const;
    double getValidDouble(double min) const;
    void getValidString(char* buffer, int size) const; 
};

#endif
