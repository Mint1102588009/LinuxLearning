#ifndef ADDFACTORY_H
#define ADDFACTORY_H

#include <CalculateFactory.h>
#include "CalculateAdd.h"
#include <iostream>
using namespace std;

class AddFactory : public CalculateFactory
{
    public:
        AddFactory();
        virtual ~AddFactory();
        virtual Calculate* createOperation();
    protected:

    private:
};

#endif // ADDFACTORY_H
