#ifndef CALCULATEADD_H
#define CALCULATEADD_H

#include <Calculate.h>
#include <iostream>
using namespace std;

class CalculateAdd : public Calculate
{
    public:
        CalculateAdd();
        virtual ~CalculateAdd();
        virtual double getResult();
    protected:

    private:
};

#endif // CALCULATEADD_H
