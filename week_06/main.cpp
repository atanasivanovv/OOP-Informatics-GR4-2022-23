#include <iostream>
#include <cstring>
#include "Person.h"

class SimplePerson {
    private:
    int age = 10;

    public:
    void setAge(int age) {
        this->age = age;
    }
};

int main() {
    Person person1;
    Person person2 = Person(person1);
    
    person1.printPerson();
    person2.printPerson();

    person1.setName("Ala");

    person1.printPerson();
    person2.printPerson();
    // person1.getReferenceToSelf().getReferenceToSelf().printPerson();
    
    person1 = person2;
    person1.printPerson();
}