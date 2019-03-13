# include "Store.h"

Store ::  Store(int valuePrice, string valueName)
{
    price = valuePrice;
    name = valueName;
}

void Store :: setValuePrice(int valuePrice)
{
    price = valuePrice;
}

int Store :: getValuePrice()
{
    return price;
}

void Store :: setValueName(string valueName)
{
    name = valueName;
}
string Store :: getValueName()
{
    return name;
}