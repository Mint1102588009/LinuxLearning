#ifndef CALCULATEFACTORY_H
#define CALCULATEFACTORY_H

#include "Calculate.h"

class CalculateFactory
{
    public:
        CalculateFactory();
        virtual ~CalculateFactory();
        virtual Calculate* createOperation() = 0;
    protected:

    private:
};

#endif // CALCULATEFACTORY_H
