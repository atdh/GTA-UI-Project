# include "Enemies.h"


Enemies :: Enemies()
{
    name = "NONE";
    race = "NONE";
    gender = "NONE";
    weight = -1;
    height = -1;
    
}

Enemies :: Enemies (string enemyName, string enemyRace, string enemyGender, int enemyWeight, int enemyHeight)
{
    name = enemyName;
    race = enemyRace;
    gender = enemyGender;
    weight = enemyWeight;
    height = enemyHeight;
}

void Enemies :: setName(string enemyName)
{
    name = enemyName;
}

string Enemies :: getName()
{
    return name;
}

void Enemies :: setRace(string enemyRace)
{
    race = enemyRace;
}

string Enemies :: getRace()
{
    return race;
}
void Enemies :: setGender(string enemyGender)
{
    gender = enemyGender;
}
string Enemies :: getGender()
{
    return gender;
}
void Enemies:: setWeight(int enemyWeight)
{
    weight = enemyWeight;
}
int Enemies :: getWeight()
{
    return weight;
}
void Enemies :: setHeight(int enemyHeight)
{
    height = enemyHeight;
}
int Enemies :: getHeight()
{
    return height;
}