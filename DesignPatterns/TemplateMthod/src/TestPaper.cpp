#include "TestPaper.h"

TestPaper::TestPaper()
{
    //ctor
}

TestPaper::~TestPaper()
{
    //dtor
}

void TestPaper::test(){
    cout << "杨过..." << endl;
    cout << testQuestion1() << endl;
    cout << "铲除青花..." << endl;
    cout << testQuestion2() << endl;
    cout << testQuestion3() << endl;
}

string TestPaper::testQuestion1(){
    return "";
}
string TestPaper::testQuestion2(){
    return "";
}
string TestPaper::testQuestion3(){
    return "";
}
