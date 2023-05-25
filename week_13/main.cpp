#include <iostream>

class Base
{
public:
    virtual void print()
    {
        std::cout << "print base class\n";
    }

    void show()
    {
        std::cout << "show base class\n";
    }
};

class PureBase
{
public:
    virtual void print() = 0;
    virtual void show() = 0;
};

class Derived : public PureBase
{
public:
    void print() override
    {
        std::cout << "print derived class\n";
    }

    void show()
    {
        std::cout << "show derived class\n";
    }
};

int main()
{
    PureBase *bptr;
    Derived d;
    bptr = &d;

    // run time
    bptr->print();

    // compile time
    bptr->show();

    PureBase *pure;
}