#ifndef PROTOTYPE_H
#define PROTOTYPE_H


class Prototype
{
    public:
        Prototype();
        virtual ~Prototype();
        virtual Prototype* myClone() = 0;
    protected:

    private:
};

#endif // PROTOTYPE_H
