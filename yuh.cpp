#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string x;
    cout << "Enter your name" << endl;
    cin >> x;
    
    string filename=x+"_weapons.txt";
    
    ofstream fs(filename);
    fs << "Hello" << x << endl;
    fs.close();
    return 0;
}

cout << "Success! Files have been loaded!" << endl;
    string choice;
    cout << "Do you want to start a (n)ew game or (l)oad an existing one?" << endl;
    getline(cin, choice);
    if(choice == "n" || choice == "N")
    {
        cout << "Welcome user" << endl;
        login();
        
    }
    if(choice == "l" || choice == "L")
    {
        cout << "Welcome Back user" << endl;
        login();
        
    }*/
