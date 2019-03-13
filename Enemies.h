#ifndef ENEMIES_H
#define ENEMIES_H

#include <string>
#include <iostream>
using namespace std;

class Enemies
{//gang affiliation
    public:
    Enemies();
    
    
    Enemies(string enemyName, string enemyRace, string enemyGender, int enemyWeight, int enemyHeight);//constructor
    
    void setName(string enemyName);
    string getName();
    
    void setRace(string enemyRace); 
    string getRace();
    
    void setGender(string enemyGender);
    string getGender();
    
    void setWeight(int enemyWeight);
    int getWeight();
    
    void setHeight(int enemyHeight);
    int getHeight();
    
    private:
    string name;
    string race;
    string gender;
    int weight;
    int height;
    
    
};


# endif
