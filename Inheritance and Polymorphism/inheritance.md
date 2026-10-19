INHERITANCE:

Definition
Inheritance is an OOP concept in which one class (the derived class or child class) acquires the properties and functions of another class (the base class or parent class).
It allows programmers to reuse existing code instead of writing the same code again.

Example of inheritance
Consider a program where a Person has a name and can introduce themselves. A Student is a type of person, so the Student class can inherit from the Person class.

Explanation of the code
class Person defines the base class with a name variable and an introduce() function.
class Student : public Person means that Student publicly inherits from Person.
The Student class can access the inherited public member name and function introduce().
The Student class also defines its own variable, course, and function, study().
In main(), the object s uses both inherited and its own members.

Types of inheritance in C++
1. Single inheritance
One derived class inherits from one base class.
Example: Student inherits from Person.
2. Multiple inheritance
One derived class inherits from two or more base classes.
Example: TeachingAssistant inherits from Student and Employee.
3. Multilevel inheritance
A class inherits from another derived class.
Example: Person → Student → GraduateStudent.
4. Hierarchical inheritance
Multiple derived classes inherit from one base class.
Example: Student and Teacher both inherit from Person.
5. Hybrid inheritance
A combination of two or more types of inheritance.

Advantages of inheritance
Code reusability: Existing class members can be reused.
Reduced duplication: Avoids writing similar code repeatedly.
Easy maintenance: Shared functionality can be maintained in the base class.
Extensibility: New classes can be created from existing classes.