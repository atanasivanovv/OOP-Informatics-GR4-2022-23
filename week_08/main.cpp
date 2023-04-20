#include <iostream>
#include <cstring>

void setValidAge(int age)
{
    try
    {
        if (age >= 18)
        {
            std::cout << "Access granted - you are old enough.";
            throw(true);
        }
        else
        {
            throw(age);
        }
    }
    catch (int myNum)
    {
        std::cout << "Access denied - You must be at least 18 years old.\n";
        std::cout << "Age is: " << myNum;
    }
    catch (...)
    {
        std::cout << "Access denied - ANY EXCEPTION - You must be at least 18 years old.\n";
    }
}

class User
{
private:
    static int registered;
    char facNumber[500];

public:
    static int getRegistered()
    {
        return registered;
    }
    User()
    {
        strcpy(facNumber, "test");
        registered++;
    }

    User &operator[](const char *facNum)
    {
    }

    // bool operator==(const User &otherUser)
    // {
    //     return this->facNumber == otherUser.facNumber;
    // }
};
int User::registered = 0;

// class UserUtillity
// {
// private:
//     UserUtillity() {}

// public:
//     static void printUsers(const User *arr);
//     static void removeAllUsers();
// };

void someFunc()
{
    static int immortal = 5;
    immortal++;
    std::cout << immortal;
}

main()
{
    User u1;
    u1["500"];

    User u2;
    u1 = u2;
    // if (u1 = u2)
    // {
    //     std::cout << "Users have same FAC NUM";
    // }
    std::cout << User::getRegistered() << std::endl;
    // UserUtillity::removeAllUsers();
    // someFunc();
    // someFunc();
}