#include <iostream>
using namespace std;
#include "Client.h"

int main(){
    Client* c1 = new Client();
    c1->Setname("Mint_7");
    c1->Setage(23);
    c1->Setjob("c++ Programer");
    Client* c2 = dynamic_cast<Client*>(c1->myClone());
    //Client* c2 = c1->myClone();
    c1->show();
    c2->show();
    delete c1;
    delete c2;

    return 0;
}
