#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
using namespace std;

class Car
{
    public:
    
    Car();
    Car(string make , string yM);
    void setYearModel(string yM);
    string getYearModel();
    
    
    void setMake(string make);
    string getMake();
    
    //rim size and color
    //txt file for car inventory and gun inventory
    
    
    private:
    string yearModel;
    string name;
    
    
};

# endif