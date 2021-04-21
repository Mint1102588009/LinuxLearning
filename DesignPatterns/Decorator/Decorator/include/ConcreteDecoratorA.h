#ifndef CONCRETEDECORATORA_H
#define CONCRETEDECORATORA_H

#include <Decorator.h>
#include <iostream>
using namespace std;


class ConcreteDecoratorA : public Decorator
{
    public:
        ConcreteDecoratorA();
        virtual ~ConcreteDecoratorA();
        virtual void Operation();
    protected:

    private:
};

#endif // CONCRETEDECORATORA_H
