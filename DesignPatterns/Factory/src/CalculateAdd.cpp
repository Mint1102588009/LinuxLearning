#include "CalculateAdd.h"

CalculateAdd::CalculateAdd()
{
    //ctor
}

CalculateAdd::~CalculateAdd()
{
    cout << "~Add()called!" << endl;//dtor
}

double CalculateAdd::getResult(){
    return this->NumberA + this->NumberB;
}
