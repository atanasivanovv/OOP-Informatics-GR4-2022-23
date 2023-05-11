#include "String.h"

String::String()
    {
        this->data = new char[8];
        this->size = 0;
    }

String::String(const char *data)
{
    std::cout << "Created\n";
    this->data = new char[strlen(data) + 1];
    strcpy_s(this->data, strlen(data) + 1, data);
    this->size = strlen(data);
}

String::String(const String &other)
{
    std::cout << "Copied!\n";
    this->data = new char[strlen(other.data) + 1];
    strcpy(this->data, other.data);
    this->size = other.size;
}

String& String::operator=(const String &other)
{
    if (this != &other) {
        std::cout << "Copied!\n";
        this->data = new char[strlen(other.data) + 1];
        strcpy(this->data, other.data);
        this->size = other.size;
    }

    return *this;
}

String::String(String &&other)
{
    std::cout << "Moved!\n";
    this->data = other.data;
    this->size = strlen(other.data);

    other.data = nullptr;
    other.size = 0;
}

String::~String()
{
    std::cout << "DELETED DATA!\n";
    delete[] this->data;
}

void String::printData()
{
    std::cout << this->data << "\n";
}