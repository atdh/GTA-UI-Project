#include <iostream>
#include <fstream>
#include "Weapons.h"
//#include "vehicle.h"
using namespace std;



int Split(string str, char separator, string r[], int size)
{
    int count = 0;
if (str.length()== 0)
{
        count = 0;
}
else
{
    string current;
    str += separator;

for (int i=0; i< str.length(); i++)
{
if (str[i] != separator)
{
    current = current + str[i];
}
else
    {
        r[count] = current;
        count ++;
        current = "";
            }
        }

    }
    return count;

}










int main()
{
    Weapons currWeapon[100];
    //Car currCar[100];
    //ifstream loadMyWeapon(name+"_weapons.txt");
    string loadMyWeaponLine = "";
    int myWeaponCounter = 0;
    int sizeMyWeaponCounterArr = 2;
    string myWeaponCounterArr[2];
    
    /*ifstream loadMyCar(name+"_vehicles.txt");
    string loadMyCarLine = "";
    int myCarCounter = 0;
    int sizeMyCarCounterSplitArr = 2;
    string myCarCounterSplitArr[2];*/
    
    string choice;
    string name;
    cout << "Do you want to start a (n)ew game or (l)oad an existing game?" << endl;
    getline(cin, choice);
    
    if(choice == "n" || choice == "N")
    {
        cout << "Welcome user! Please input your name" << endl;
        getline(cin, name);
        
        string filename= name+"_weapons.txt";
        
        ofstream weaponFile(filename);
        weaponFile << "fist,0.05" << endl;
        /////////////////////////////
        string nextfile = name +"_vehicles.txt";
        
        ofstream carfile(nextfile);
       // carfile << "yoyo" << endl;
       ifstream loadMyWeapon(name+"_weapons.txt");
       
       while(getline(loadMyWeapon, loadMyWeaponLine))
    {
        Split(loadMyWeaponLine, ',', myWeaponCounterArr, 2);
        Weapons newcurrweapon(myWeaponCounterArr[0], stod(myWeaponCounterArr[1]));
        currWeapon[myWeaponCounter] = newcurrweapon;
        myWeaponCounter++;
    }
       
       
    }
    //else if(choice == "l" || choice)
    
    
    //cout <<currWeapon[0].getWeaponType() << endl;
    
   //create array current weapons and current cars 
    return 0;
}