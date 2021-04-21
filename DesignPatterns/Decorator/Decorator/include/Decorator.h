#ifndef DECORATOR_H
#define DECORATOR_H

#include <Component.h>
#include <iostream>
using namespace std;


class Decorator : public Component
{
    public:
        Decorator();
        virtual ~Decorator();
        void setComponent(Component* temp);
        virtual void Operation();
    protected:
        Component* p;
    private:

};

#endif // DECORATOR_H
