#include <iostream>

class String
{
    char *data;
    size_t size;

public:
    String()
    {
        this->data = new char[8];
        this->size = 0;
    }

    String(const char *data)
    {
        std::cout << "Created\n";
        this->data = new char[strlen(data) + 1];
        strcpy_s(this->data, strlen(data) + 1, data);
        this->size = strlen(data);
    }

    String(const String &other)
    {
        std::cout << "Copied!\n";
        this->data = new char[strlen(other.data) + 1];
        strcpy(this->data, other.data);
        this->size = other.size;
    }

    String(String &&other)
    {
        std::cout << "Moved!\n";
        this->data = other.data;
        this->size = strlen(other.data);

        other.data = nullptr;
        other.size = 0;
    }

    ~String()
    {
        std::cout << "DELETED DATA!\n";
        delete[] this->data;
    }

    void printData()
    {
        std::cout << this->data << "\n";
    }
};

class Person
{
    String name;

public:
    Person(const String &otherName) : name(otherName) {}
    Person(String &&otherName) : name(std::move(otherName)){};
    // Person(String &&otherName) : name((String&&) otherName){};
};