#include "ConcreteStrategyA.h"

ConcreteStrategyA::ConcreteStrategyA()
{
    //ctor
}

ConcreteStrategyA::~ConcreteStrategyA()
{
    //dtor
}

void ConcreteStrategyA::AlgorithmInterface(){
    cout << "I am strategy A" << endl;
}
