#include "Car.h"


Car :: Car()
{
    yearModel = "NONE";
    name = "NONE";
}


//making constructor
Car:: Car(string make, string yM)
{
    yearModel = yM;
    name = make;
}

void Car :: setYearModel(string yM)
{
    yearModel = yM;
}


string Car :: getYearModel()
{
    return yearModel;
}


void Car :: setMake(string make)
{
    name = make;
}

string Car :: getMake()
{
    return name;
}
