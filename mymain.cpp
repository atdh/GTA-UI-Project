#include <iostream>
#include <fstream>
#include <string>
#include "Car.h"
//#include "Store.h"
//#include "Split.h"
#include "Enemies.h"
#include "Users.h" //get access to user name and money
#include "Weapons.h"
using namespace std;

class Game
{
    
public:
Game();
void loadFile();
void login(string go);
Users user[100];
Car car[100];
Weapons weapon[100];
Enemies enemy[500];
Weapons currWeapon[100];
//Weapons weapname[100];
//Weapons attk[100];
//Users money[100];
//Users name[100];
//Car make[100];
//Car model[100];
//Enemies enemyName[500];
//Enemies enemyHeightArray[100];
//Enemies enemyWeightArray[100];
//Enemies enemyRaceArray[100];

        
//void mainMenu();
//void game();
//void continuedGame();
//void quit();




private:
int Split(string str, char separator, string r[], int size);
int indxArray;
};

Game :: Game()
{
    loadFile();
    //login();
    //mainMenu();
    //game();
    //quit();
}

int Game :: Split(string str, char separator, string r[], int size)
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



void Game :: loadFile()
{
    string choice;
    
    ifstream loadBankAcc ("bankaccount.txt");
    ifstream loadCarInventory("vehicle.txt");
    ifstream loadWeapons("weapons.txt");
    ifstream loadEnemies("enemies.txt");
    //ifstream loadStore("store.txt");
    
    string bankAccLine = "";
    string weaponsLine = "";
    string enemiesLine = "";
    string carLine = "";
    string storeLine = "";
    
    int bankAccCounter = 0;
    int sizeBankAccSplitArr = 2; //have to use stoi later
    string bankAccSplitArr[2];
    
    //think about how i will acces bank account
    int carInventoryCounter = 0;//idk why i need this rn. but good for testing bugs
    int sizeCarInventorySplitArr = 2;
    string carInventorySplitArr[2]; //no need to stoi
    
    int weaponsCounter = 0;
    int sizeWeaponsSplitArr = 2;    //need stoi
    string weaponsSplitArr[2];
    
    int enemiesCounter = 0;
    int sizeEnemiesSplitArr = 5;    //need to stoi
    string enemiesSplitArr[5];
    
    //int storeCounter = 0;
    //int sizeStoreSplitArr = 2;
    //string storeSplitArr[2]; //need to stoi first index
    
    if(!loadWeapons.is_open() || !loadEnemies.is_open() || !loadBankAcc.is_open() || !loadCarInventory.is_open() )
    {
        cout << "Game cannot be launched. Files could not be found" << endl;
        return;
    }

    while(getline(loadBankAcc, bankAccLine))
    {
        //utilize split function
        
        Split(bankAccLine, ',', bankAccSplitArr, 2 );
        Users newUser(bankAccSplitArr[0], stoi(bankAccSplitArr[1]));
        user[bankAccCounter] = newUser; 
        

        bankAccCounter ++;
    }
    //cout << "_______"<< endl;
    loadBankAcc.close();
    /*while(getline(loadStore, storeLine))
    {
        Split(storeLine, ',', storeSplitArr, 2);
        
    }*/
    
    
    while(getline(loadCarInventory, carLine))
    {
        Split(carLine, ',', carInventorySplitArr, 2);
        Car newcar(carInventorySplitArr[0],carInventorySplitArr[1]);
        car[carInventoryCounter] = newcar;
        carInventoryCounter++;
    }
    loadCarInventory.close();
    
    
    while(getline(loadWeapons, weaponsLine))
    {
        Split(weaponsLine, ',', weaponsSplitArr, 2 );
        //string weapname[100]; int attk[100];
        Weapons newweapon(weaponsSplitArr[0], stoi(weaponsSplitArr[1]));
        weapon[weaponsCounter] = newweapon;
        weaponsCounter++;
    }
    //cout << "___"<< endl;
    loadWeapons.close();
    
    while(getline( loadEnemies, enemiesLine ))
    {
        Split(enemiesLine, ',', enemiesSplitArr, 5);
        //cout << "____" << endl;
        Enemies newenemy(enemiesSplitArr[0], enemiesSplitArr[3], enemiesSplitArr[4], stoi(enemiesSplitArr[2]), stoi(enemiesSplitArr[1]));
        enemy[enemiesCounter] = newenemy;
        
        enemiesCounter++;

    }
    //cout << enemiesCounter +10 << endl;
    loadEnemies.close();
    cout << "Success! Files have been loaded!" << endl;
    
    cout << "Do you want to start a (n)ew game or (l)oad an existing game?" << endl;
    getline(cin, choice);
    

    if(choice == "n" || choice == "N" || choice == "l" || choice == "L")
    {
        login(choice);
    }
    else
    {
        cout << "Please input a valid option" << endl;
    }
    
}


//creating file of weapons and cars for new user
void Game :: login(string go)
{
    string name;
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
    
    
    
    if(go == "n" || go == "N")
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
   return; 
}



int main()
{
    Game bloodmoney;
   // cout << bloodmoney.enemy[300].getHeight() << endl;    
    //cout << bloodmoney.enemy[300].getGender() << endl;
    //cout << bloodmoney.enemy[300].getWeight() << endl;
    //cout << bloodmoney.enemy[300].getRace() << endl;
    //cout << bloodmoney.enemy[300].getName() << endl;
    //cout << bloodmoney.weapon[5].getWeaponType() << endl;
    //cout << bloodmoney.weapon[5].getWeaponDamage() << endl;
    //cout << bloodmoney.weapon[0].getWeaponType() << endl;
    //cout << bloodmoney.weapon[0].getWeaponDamage() << endl;
    
   // cout << bloodmoney.user[0].getCurrency()<< endl;
    //cout << bloodmoney.user[0].getUserName()<< endl;
    //cout << bloodmoney.user[5].getCurrency()<< endl;
    //cout << bloodmoney.user[5].getUserName() << endl;
    
    //cout << bloodmoney.car[0].getYearModel() << endl;
    //cout << bloodmoney.car[0].getMake()<< endl;
    
    //bloodmoney.login();
}

