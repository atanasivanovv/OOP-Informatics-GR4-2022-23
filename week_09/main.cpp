#include <iostream>

int &&getA()
{
    return 10;
}

void handleA(int &&a)
{
    std::cout << a << std::endl;
}

int main()
{
    int a = getA();

    handleA(20);

    // complains because IT EXPECTS RVALUE
    // while a is an lvalue
    handleA(a);
}