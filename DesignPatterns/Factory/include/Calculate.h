#ifndef CALCULATE_H
#define CALCULATE_H


class Calculate
{
    public:
        Calculate();
        virtual ~Calculate();

        double GetNumberA() { return NumberA; }
        void SetNumberA(double val) { NumberA = val; }
        double GetNumberB() { return NumberB; }
        void SetNumberB(double val) { NumberB = val; }
        virtual double getResult() = 0;
    protected:
        double NumberA;
        double NumberB;

    private:
};

#endif // CALCULATE_H
