#ifndef SUBFACTORY_H
#define SUBFACTORY_H

#include <CalculateFactory.h>
#include "CalculateSub.h"

class SubFactory : public CalculateFactory
{
    public:
        SubFactory();
        virtual ~SubFactory();
        virtual Calculate* createOperation();
    protected:

    private:
};

#endif // SUBFACTORY_H
