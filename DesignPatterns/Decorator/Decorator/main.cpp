#include <iostream>
using namespace std;
#include "ConcreteComponent.h"
//#include "Decorator.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

int main(){
    ConcreteComponent* c = new ConcreteComponent();
    ConcreteDecoratorA* d1 = new ConcreteDecoratorA();
    ConcreteDecoratorB* d2 = new ConcreteDecoratorB();

    d1->setComponent(c);
    d2->setComponent(d1);
    d2->Operation();

    return 0;
}
