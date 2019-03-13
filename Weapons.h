#ifndef WEAPONS_H
#define WEAPONS_H

#include <string>
#include <iostream>
using namespace std;

class Weapons
{
    public:
    //
    Weapons();//empty contructor
   Weapons(string nameOfweapon, double weaponDamage);
    
    void setWeaponType(string);
    string getWeaponType();
    
    void setWeaponDamage(double);
    double getWeaponDamage();
    
    private:
    string weaponName;
    double damageLevel;
    string weap[1000];
};


# endif