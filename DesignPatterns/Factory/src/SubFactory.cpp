#include "SubFactory.h"

SubFactory::SubFactory()
{
    //ctor
}

SubFactory::~SubFactory()
{
    //dtor
}

Calculate* SubFactory::createOperation(){
    return new CalculateSub();
}
