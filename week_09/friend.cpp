#include <iostream>

class Board;

class Point
{
private:
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(const Board &board)
    {
        // it does not have access the other way around
        // board.name -> inaccessible
    }

    friend class Board;

    friend std::ostream &operator<<(std::ostream &out, Point &p);
    friend std::istream &operator>>(std::istream &in, Point &p);
};

class Board
{
private:
    char name[64];

public:
    // Board(const Point &p) { p.y; }

    void boardGame(const Point &start, const Point &end)
    {
        std::cout << "play" << std::endl; // Board has direct access to everything private in Point
        std::cout << start.x << std::endl;
        std::cout << start.y << std::endl;
    }
};

// GLOBAL friend function

class A
{
    int privateVar;

public:
    A()
    {
        this->privateVar = 5;
    }

    friend void showA(A &);
};

void showA(A &a)
{
    std::cout << a.privateVar << std::endl;
}

void showANotAccessible(A &a)
{
    // member "A::privateVar" is inaccessible
    // std::cout << a.privateVar << std::endl;
}

// friend method

class C;

// B.hpp
class B
{
private:
    char test;

public:
    void showC(C &) const;
};

class C
{
private:
    int privateC;

public:
    C()
    {
        this->privateC = 15;
    }

    // in order to access private variables from C
    friend void B::showC(C &) const;
};

// B.cpp
void B::showC(C &c) const
{
    // this->test = 'c'; -> cannot because of const
    std::cout << c.privateC << std::endl;
}

int main()
{
    A a;
    showA(a);
}