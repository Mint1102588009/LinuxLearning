#ifndef CONCRETESTRATEGYA_H
#define CONCRETESTRATEGYA_H

#include <Strategy.h>
#include <iostream>
using namespace std;


class ConcreteStrategyA : public Strategy
{
    public:
        ConcreteStrategyA();
        virtual ~ConcreteStrategyA();
        virtual void AlgorithmInterface();

    protected:

    private:
};

#endif // CONCRETESTRATEGYA_H
