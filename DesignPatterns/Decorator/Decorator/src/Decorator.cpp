#include "Decorator.h"

Decorator::Decorator()
{
    //ctor
}

Decorator::~Decorator()
{
    if(this->p != nullptr){
        delete this->p;
    }
}

void Decorator::setComponent(Component* temp){
    this->p = temp;
}
void Decorator::Operation(){
    this->p->Operation();
    cout << "This is Decorator~" << endl;
}
