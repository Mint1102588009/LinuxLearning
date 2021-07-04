#include "ConcreteDecoratorA.h"

ConcreteDecoratorA::ConcreteDecoratorA()
{
    //ctor
}

ConcreteDecoratorA::~ConcreteDecoratorA()
{
    cout << "A called" << endl;//dtor
}

void ConcreteDecoratorA::Operation(){
    this->p->Operation();
    cout << "A's operation" << endl;
}
