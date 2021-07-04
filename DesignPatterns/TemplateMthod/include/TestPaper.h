#ifndef TESTPAPER_H
#define TESTPAPER_H
#include <string>
using  namespace std;
#include <iostream>


class TestPaper
{
    public:
        TestPaper();
        virtual ~TestPaper();
        void test();

    protected:
        virtual string testQuestion1();
        virtual string testQuestion2();
        virtual string testQuestion3();
    private:
};

#endif // TESTPAPER_H
