#include "AddFactory.h"

AddFactory::AddFactory()
{
    //ctor
}

AddFactory::~AddFactory()
{
    cout << "~AddFactory()called!" << endl;//dtor
}

Calculate* AddFactory::createOperation(){
    return new CalculateAdd();
}
