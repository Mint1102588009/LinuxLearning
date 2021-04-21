#ifndef CONCRETESTRATEGYB_H
#define CONCRETESTRATEGYB_H

#include <Strategy.h>
#include <iostream>
using namespace std;

class ConcreteStrategyB : public Strategy
{
    public:
        ConcreteStrategyB();
        virtual ~ConcreteStrategyB();
        virtual void AlgorithmInterface();
    protected:

    private:
};

#endif // CONCRETESTRATEGYB_H
