#ifndef STORE_H
#define STORE_H

#include <string>
#include <iostream>
using namespace std;

class Store
{
    public:
    //Store();
    Store(int valuePrice, string valueName);
    void setValuePrice(int);
    int getValuePrice();
    void setValueName(string);
    string getValueName();
    
    private:
    int price;
    string name;
};

#endif

