#ifndef USERS_H
#define USERS_H

# include "Weapons.h"
#include <string>
#include <iostream>
using namespace std;

//make use of object arrays

class Users
{
    //get set name and balance. utilize in quit function where it will save my account
    public:
    Users(); //default constructor
    Users(string userName, float currency);
    
    void setCurrency(float);
    float getCurrency();
    
    void setUserName(string);
    string getUserName();
    
    private:
    string name;
    float money;
    //string getweapons[indx];//object array
    //item header file
};

#endif