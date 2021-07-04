#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "Prototype.h"
#include <iostream>
using namespace std;

class Client: public Prototype
{
    public:
        Client();
        virtual ~Client();
        virtual Prototype* myClone();
        void show();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        int Getage() { return age; }
        void Setage(int val) { age = val; }
        string Getjob() { return job; }
        void Setjob(string val) { job = val; }

    protected:

    private:
        string name;
        int age;
        string job;
};

#endif // CLIENT_H
