# include "Users.h"

Users :: Users()
{
    name = "";
    money = 0.0;
}

Users :: Users(string userName, float currency)
{
    name = userName;
    money = currency;
    
}

void Users :: setCurrency (float currency)
{
    money = currency;
}

float Users :: getCurrency ()
{
    return money;
}

void Users :: setUserName(string userName)
{
    name = userName;
}

string Users :: getUserName()
{
    return name;
}


