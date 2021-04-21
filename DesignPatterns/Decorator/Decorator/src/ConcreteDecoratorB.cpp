#include "ConcreteDecoratorB.h"

ConcreteDecoratorB::ConcreteDecoratorB()
{
    //ctor
}

ConcreteDecoratorB::~ConcreteDecoratorB()
{
    cout << "~B called." << endl;//dtor
}

void ConcreteDecoratorB::Operation(){
    this->p->Operation();
    cout << "B’s operation." << endl;
}
