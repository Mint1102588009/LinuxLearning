#ifndef STRATEGY_H
#define STRATEGY_H


class Strategy
{
    public:
        Strategy();
        virtual ~Strategy();
        virtual void AlgorithmInterface() = 0;

    protected:

    private:
};

#endif // STRATEGY_H
