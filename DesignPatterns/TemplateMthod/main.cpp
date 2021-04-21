#include <iostream>

using namespace std;

#include "TestPaper.h"
#include "StudentTest.h"

int main(){
    TestPaper * tp = new StudentTest();
    tp->test();

    return 0;
}
