#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
public:
    string name;

    void introduce() {
        cout << "My name is " << name << endl;
    }
};

// Derived class
class Student : public Person {
public:
    string course;

    void study() {
        cout << name << " is studying "
             << course << endl;
    }
};

int main() {
    Student s;

    s.name = "Elias";
    s.course = "Biomedical Engineering";

    s.introduce();
    s.study();

    return 0;
}