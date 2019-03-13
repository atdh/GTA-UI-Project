#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <iostream>
using namespace std;

Split(string str, char separator, string r[], int size)
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

#endif
