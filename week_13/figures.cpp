#include <iostream>
#include <cstring>

class Figure
{
public:
    char *name;

    // helpful if there are more fields to set in base class
    Figure(const char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    const char *getName()
    {
        return this->name;
    }

public:
    virtual double perimeter() = 0;
    virtual double area() = 0;
};

class Rectangle : public Figure
{
private:
    double width, height;

public:
    Rectangle(double width, double height) : Figure("Rectangle")
    {
        this->width = width;
        this->height = height;
    }

    double perimeter() override
    {
        return 2 * height + 2 * width;
    }

    double area() override
    {
        return height * width;
    }
};

class Circle : public Figure
{
private:
    double radius;

public:
    Circle(double radius) : Figure("Circle")
    {
        this->radius = radius;
    }

    double perimeter() override
    {
        return 2 * 3.14 * radius;
    }

    double area() override
    {
        return 3.14 * radius * radius;
    }
};

// масив от фигури (абстрактно)
void printArea(Figure **figures, int size)
{
    std::cout << size;
    for (int i = 0; i < size; i++)
    {
        double area = figures[i]->area();
        std::cout << area << std::endl;
    }
}

int main()
{
    Figure **figures = new Figure *[3];
    figures[0] = new Rectangle(10, 20);
    figures[1] = new Circle(12);
    figures[2] = new Circle(155);

    // dynamic
    // Vector<Figure*> figures;
    // Figure* figure = new <type>;
    // figures.push_back(figure);

    printArea(figures, 3);
}