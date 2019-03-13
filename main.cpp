# include <iostream>
# include <fstream>
# include <string>
# include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
# include "Weapons.h"
using namespace std;

class Game
{
public:
Game();
void loadFile();
void mainMenu();
void game();
void continuedGame();
void quit();

private:
int Split(string str, char separator, string r[], int size);
int indxArray;
//weapons[100];
//enemies[100];
//bankaccount.txt arrays
string name[100];
int money[100];
//weapon.txt arrays
Weapons weapname[100];
//int attk[100];
Weapons attk[100];
//nimbus, 5'10, 220lbs, caucasian, male
string enemyName[100];
int enemyHeightArray[100];
int enemyWeightArray[100];
string enemyRaceArray[100];
string enemyGenderArray[100];
};

Game :: Game()
{
    loadFile();
    mainMenu();
    game();
    quit();
}

//my split function
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
    ifstream loadBankAcc("bankaccount.txt");

    ifstream loadWeapons("weapons.txt");
    ifstream loadEnemies("enemies.txt");

    string bankAccLine = "";
    string weaponsLine = "";
    string enemiesLine = "";

    int bankAccCounter = 0;
    int sizeBankAccSplitArr = 2; //have to use stoi later
    string bankAccSplitArr[2];

    int weaponsCounter = 0;
    int sizeWeaponsSplitArr = 2;
    string weaponsSplitArr[2];

    int enemiesCounter = 0;
    int sizeEnemiesSplitArr = 5;
    string enemiesSplitArr[5];

    if(!loadWeapons.is_open() || !loadEnemies.is_open() || !loadBankAcc.is_open())
    {
        cout << "Game cannot be launched. Files could not be found" << endl;
        return;
    }
    while(getline(loadBankAcc, bankAccLine))
    {
        //utilize split function
        //int Split(string str, char separator, string r[], int size);
        Split(bankAccLine, ',', bankAccSplitArr, 2 );
        money[bankAccCounter] = stoi(bankAccSplitArr[1]);
        name[bankAccCounter] = bankAccSplitArr[0];

        bankAccCounter ++;
    }
    //cout << "_______"<< endl;
    loadBankAcc.close();

    while(getline( loadWeapons ,weaponsLine) )
    {
        Split(weaponsLine, ',', weaponsSplitArr, 2 );
        //string weapname[100]; int attk[100];
        weapname[weaponsCounter].setWeaponType(weaponsSplitArr[0]);
        attk[weaponsCounter].setWeaponDamage(stoi(weaponsSplitArr[1]));
        weaponsCounter++;
    }
    //cout << "___"<< endl;
    loadWeapons.close();

    while(getline( loadEnemies, enemiesLine ))
    {
        Split(enemiesLine, ',', enemiesSplitArr, 5);
        //cout << "____" << endl;
//string enemyName[100];int enemyHeightArray[100];int enemyWeightArray[100];string enemyRaceArray[100];string enemyGenderArray[100];
        enemyName[enemiesCounter] = enemiesSplitArr[0];
        //cout << enemiesCounter << enemyName[enemiesCounter] << endl;
        //cout << enemyName[0]<< endl;
        enemyHeightArray[enemiesCounter] = stoi( enemiesSplitArr[1] );
        //cout << "_"<< endl;
        //cout << enemiesSplitArr[2] << endl;
        enemyWeightArray[enemiesCounter] = stoi( enemiesSplitArr[2] );//this not working. returns stoi error

        enemyRaceArray[enemiesCounter] = enemiesSplitArr[3];
        //cout << "___" << endl;
        enemyGenderArray[enemiesCounter] = enemiesSplitArr[4];
        //cout << "_" << endl;
        //enemiesCounter++;//not working. main.exe stops working
        enemiesCounter++;

    }

    //cout << enemiesCounter +10 << endl;
    loadEnemies.close();

    cout << "Files loaded successfully" << endl;
    return;
}

void Game :: mainMenu()
{
    string input;
    string newInput;
    newInput = input;
    cout << "Please enter your name" << endl;
    getline(cin, input);
    cout << "Welcome to Blood Money " << input << endl;
    for(int i=0; i<input.length(); i++)
    {
        newInput[i] = tolower(input[i]);  //the new username is all lowered calse
        //test case to see if it converts capital to lower case
        //cout << "ATUL" <<endl;
    }
    //cout << "Welcome to Blood Money " << input << endl;
    if(input == "")
    {
        while(input == "")
        {
           cout << "Please input a valid username" << endl;
           getline(cin, input);
           for(int i=0; i<input.length(); i++)
            {
                newInput[i] = tolower(input[i]);
            }
           cout << "Welcome to Blood Money " << input << endl;
        }

    }
    string userChoice;
    cout << "Would you like to (s)tart a new game, (c)ontinue where you left off, or (q)uit?" << endl;
    getline(cin, userChoice);
    if(userChoice == "q" || userChoice == "Q")
    {
        quit();
        //cout << "Thanks for playing. Goodbye" << endl;
    }
    if(userChoice == "s" || userChoice == "S" )
    {
        game();
    }
    if(userChoice == "C" || userChoice == "c")
    {
        continuedGame();
    }
}



int randomNumbers(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}


void Game :: game()
{
cout <<"You have just escaped prison. You have 36 hours to get out of this country. In order to escape, you will need 36 thousand to make new passport, identity, and tickets" << endl;
cout <<"user: Well time to get back to work...." << endl;
cout << "enemy spotted" << endl;


string input;
int num = 0;
int weaponsCounter = 0;
int index = 0;
    // need to write before calling rand() to seed the random number generator
    srand(time(0));

    for(int i=0;i<10;++i)
    {
        // random numbers between 0 and 10
        //enemyName[num];
        num = randomNumbers(0,10);
        //cout << enemyName[1] << endl;
        //cout << enemyName[num] << endl;
        //cout << enemyHeightArray[num]<< endl;
        //cout <<enemyWeightArray[num]<< endl;
        //cout <<enemyRaceArray[num] << endl;
        //cout << enemyGenderArray[num] << endl;
      // cout<<num<<" " << enemyName[num] << endl;
      //cout << enemyName[num] << endl;
    }
    cout << enemyName[num] << endl;
    cout << "lets rob this fool...." << endl;

    cout << "Do you want to attack this enemy? (y)/(n)"  << endl;
    getline(cin, input);

    if(input == "y" || input == "Y" )
    {
        cout << "Lets do this" << endl;

        //make a random weapon generator here. then print out the enemies weapon

        //the more powerful a weapon is the less chance of hitting the target.
        cout << " The enemy might have a weapon. Continue? (Y)/(N)" << endl;
        getline(cin, input);
        if (input == "n" || input == "N")
        {
            cout <<"Rather be safe than sorry. Ima get the next fool" << endl;
        }

        if(input == "y" || input == "Y")
        {
            cout << "go hard or go home" << endl;
            cout << "What weapon do you want to use? (f)ist, (s)tick,(b)at,(k)nife,(g)lock 17, (Be)nelli M4 shotgun, (AK)-47, (AR)-15" << endl;
            getline(cin, input);

            // use getweapon and object array to access weapons tht the user has
            /*if(input == "f" || input == "F" )
            {
                for(int i=0; i<100; i++)
                {
                    weapname[weaponsCounter].getWeaponType(i);
                }
            }
            if(input == "s" || input == "S")
            {
                for(int i=0; i< 100; i++)
                {
                    weapname[weaponsCounter].getWeaponType(i);
                }
            }
            if(input == "b" || input == "B")
            {
                for(int i=0; i< 100; i++)
                {
                weapname[weaponsCounter].getWeaponType(i);
                }
            }
            if(input == "k" || input == "K")
            {
                for(int i=0; i< 100; i++)
                {
                weapname[weaponsCounter].getWeaponType(i);
                }
            }
            if(input == "g" || input == "G" )
            {
                for(int i=0; i< 100; i++)
                {
                weapname[weaponsCounter].getWeaponType(i);
                }
            }
            if(input == "be" || input == "BE")
            {
                for(int i=0; i< 100; i++)
                {
                weapname[weaponsCounter].getWeaponType(i);
                }
            }
            if(input == "AK" || input == "ak")
            {
                for(int i=0; i< 100; i++)
                {
                weapname[weaponsCounter].getWeaponType(i);
                }
            }
            if(input == "AR" || input == "ar")
            {
                for(int i=0; i< 100; i++)
                {
                weapname[weaponsCounter].getWeaponType(i);
                }
            }*/
            cout << "weapon acquired" << endl;
            cout << "heading toward enemy" << endl;
            cout << "enemy fighting back..." << endl;

        }
        //make probability equation for chances of winning against each weapon
        //ar15 and ak47 and shotgun and glock17: more chance of winning.
        //fist least chance of winning
        //stick second least
        //bat third least
        //knife: fourth least
    }


    if(input == "n" || input == "N")
    {
        cout << "I will get them next time" << endl;
    }

}

void Game :: continuedGame()
{
    return;
}

void Game :: quit()
{

    cout << "Thanks for playing" << endl;

}

int main()
{
    Game bloodmoney;
}
