// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <array>
// #include <string>
// using namespace std;
// class MyClass
// {
// private:
//     int value;

// public:
//     MyClass(int);
//     void display(int);
// };
// MyClass::MyClass(int val = 0)
// {
//     value = val;
// }
// void MyClass::display(int val)
// {
//     cout << val << endl;
// }

// class MyClass2
// {
// private:
//     int n1, n2;

// public:
//     MyClass2(int, int);
//     int getSum(int, int);
// };
// MyClass2 ::MyClass2(int num1 = 0, int num2 = 0)
// {
//     n1 = num1;
//     n2 = num2;
// }
// int MyClass2::getSum(int n1, int n2)
// {
//     return n1 + n2;
// }
// /*--------------------------------------------------------------------------------------------------------------- */
// class Person
// {
// private:
//     int age;
//     string name;

// public:
//     Person(string, int);

//     string getName()
//     {
//         return name;
//     }
//     int getAge()
//     {
//         return age;
//     }
// };

// Person::Person(string na, int ag)
// {
//     name = na;
//     age = ag;
// }

// class Lecturer : public Person
// {
// private:
//     int sallary;
//     int age;
//     string name;

// public:
//     Lecturer(string, int, int);
//     void getİnfo(string na, int ag, int sal)
//     {
//         name = na;
//         age = ag;
//         sallary = sal;
//     }
// };

// Lecturer::Lecturer(string na, int ag, int sal) : Person(na, ag)
// {
//     sallary = sal;
// }

// class Student : public Person
// {
// private:
//     int lectureNotes[4];

// public:
//     Student(string, int, int *);
// };

// Student::Student(string na, int ag, int notes[4]) : Person(na, ag)
// {
//     for (size_t i = 0; i < 4; i++)
//     {
//         lectureNotes[i] = notes[i];
//     }
// }

// int main()
// {
//     int num{15};
//     MyClass obj1;
//     MyClass2 obj2;
//     obj1.display(num);
//     cout << obj2.getSum(15, 40) << endl;

//     int notes[4] = {100, 90, 80, 70};
//     Lecturer lec1{"Ryan", 45, 4500};
//     Student student1{"Ruhe", 21, notes};
//     cout << student1.getAge() << endl;
// }

#include <iostream>
using namespace std;

class MyClass
{
private:
    int value;

public:
    MyClass(int);
    void display(int);
};
MyClass::MyClass(int val = 0)
{
    value = val;
}
void MyClass::display(int val)
{
    cout << val << endl;
}

class MyClass2
{
private:
    int n1, n2;

public:
    MyClass2(int, int);
    int getSum(int, int);
};
MyClass2 ::MyClass2(int num1 = 0, int num2 = 0)
{
    n1 = num1;
    n2 = num2;
}
int MyClass2::getSum(int n1, int n2)
{
    return n1 + n2;
}

/*--------------------------------------------------------------------------------------------------------------- */

class Person
{
protected:
    int age;
    string name;

public:
    Person(string, int);
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
};

Person::Person(string na, int ag)
{
    name = na;
    age = ag;
}

class Lecturer : public Person
{
private:
    int sallary;

public:
    Lecturer(string, int, int);
    void getInfo()
    {
        cout << "Name: " << name << ", Age: " << age << ", Salary: " << sallary << endl;
    }
};

Lecturer::Lecturer(string na, int ag, int sal) : Person(na, ag)
{
    sallary = sal;
}

class Student : public Person
{
private:
    int lectureNotes[4];

public:
    Student(string, int, int *);
};

Student::Student(string na, int ag, int notes[4]) : Person(na, ag)
{
    for (size_t i = 0; i < 4; i++)
    {
        lectureNotes[i] = notes[i];
    }
}

int main()
{
    int num{15};
    MyClass obj1;
    MyClass2 obj2;
    obj1.display(num);
    cout << obj2.getSum(15, 40) << endl;

    int notes[4] = {100, 90, 80, 70};
    Lecturer lec1{"Ryan", 45, 4500};
    Student student1{"Ruhe", 21, notes};

    lec1.getInfo();               // Lecturer bilgilerini yazdırma
    cout << student1.getAge() << endl; // Student yaşını yazdırma
}
