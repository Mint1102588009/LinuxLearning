#include <iostream>
using namespace std;
#include "Context.h"
#include "Strategy.h"
#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"

int main(){
    Context con1(new ConcreteStrategyA);
    con1.ContextInterface();
    Context con2(new ConcreteStrategyB);
    con2.ContextInterface();

    return 0;
}
