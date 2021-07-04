#include "Client.h"

Client::Client()
{
    //ctor
}

Client::~Client()
{
    //dtor
}

Prototype* Client::myClone(){
    Prototype* tmp = new Client();
    Client* tp = dynamic_cast<Client*>(tmp);
    //tp->Setname(this->Getname());
    *tp = *this;
    return tmp;
}

void Client::show(){
    cout << "name:" << this->name << endl;
    cout << "age:" << this->age << endl;
    cout << "job:" << this->job << endl;
}
