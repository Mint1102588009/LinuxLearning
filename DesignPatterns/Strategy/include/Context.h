#ifndef CONTEXT_H
#define CONTEXT_H
#include "Strategy.h"
#include <iostream>
using namespace std;

class Context
{
    public:
        Context(Strategy* temp);
        virtual ~Context();
        void ContextInterface();

    protected:

    private:
        Strategy* sty;
};

#endif // CONTEXT_H
