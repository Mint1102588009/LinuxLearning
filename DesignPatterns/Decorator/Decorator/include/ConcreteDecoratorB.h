#ifndef CONCRETEDECORATORB_H
#define CONCRETEDECORATORB_H

#include <Decorator.h>
#include <iostream>
using namespace std;

class ConcreteDecoratorB : public Decorator
{
    public:
        ConcreteDecoratorB();
        virtual ~ConcreteDecoratorB();
        virtual void Operation();
    protected:

    private:
};

#endif // CONCRETEDECORATORB_H
