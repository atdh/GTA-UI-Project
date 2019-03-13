#include "Weapons.h"

Weapons :: Weapons()
{
    damageLevel = 0.0;
}

Weapons :: Weapons(string nameOfweapon, double weaponDamage)
{
    weaponName = nameOfweapon;
    damageLevel = weaponDamage;

}

void Weapons :: setWeaponDamage(double weaponDamage)
{
    damageLevel = weaponDamage;
}

double Weapons :: getWeaponDamage()
{
    return damageLevel;
}
void Weapons :: setWeaponType(string nameOfweapon)
{
    nameOfweapon = weaponName;
}
string Weapons :: getWeaponType()
{
    return weaponName;
}


