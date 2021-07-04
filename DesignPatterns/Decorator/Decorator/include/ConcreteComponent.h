#ifndef CONCRETECOMPONENT_H
#define CONCRETECOMPONENT_H

#include <Component.h>
#include <iostream>
using namespace std;


class ConcreteComponent : public Component
{
    public:
        ConcreteComponent();
        virtual ~ConcreteComponent();
        virtual void Operation();
    protected:

    private:
};

#endif // CONCRETECOMPONENT_H
