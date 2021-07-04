#include "ConcreteStrategyB.h"

ConcreteStrategyB::ConcreteStrategyB()
{
    //ctor
}

ConcreteStrategyB::~ConcreteStrategyB()
{
    //dtor
}

void ConcreteStrategyB::AlgorithmInterface(){
    cout << "I am strategy B" << endl;
}
