#ifndef STUDENTTEST_H
#define STUDENTTEST_H

#include <TestPaper.h>


class StudentTest : public TestPaper
{
    public:
        StudentTest();
        virtual ~StudentTest();

    protected:
        virtual string testQuestion1();
        virtual string testQuestion2();
        virtual string testQuestion3();

    private:
};

#endif // STUDENTTEST_H
