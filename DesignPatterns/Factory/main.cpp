#include <iostream>
using namespace std;
#include "Calculate.h"
//#include "CalculateFactory.h"
#include "AddFactory.h"

int main(){
    CalculateFactory* fc = new AddFactory();
    Calculate* cal = fc->createOperation();
    cal->SetNumberA(1);
    cal->SetNumberB(6);
    cout << cal->getResult();
    delete cal;
    delete fc;

    return 0;
}
