#ifndef COMPONENT_H
#define COMPONENT_H


class Component
{
    public:
        Component();
        virtual ~Component();
        virtual void Operation() = 0;
    protected:

    private:
};

#endif // COMPONENT_H
