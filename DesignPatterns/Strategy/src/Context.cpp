#include "Context.h"

Context::Context(Strategy* temp)
{
    this->sty = temp;
}

Context::~Context()
{
    if(this->sty != NULL){
        delete this->sty;
    }
}

void Context::ContextInterface(){
    this->sty->AlgorithmInterface();
}
