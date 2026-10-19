POLYMORPHISM:

Definition
Polymorphism means many forms. In C++, it allows the same function name, interface, or operation to behave differently depending on the arguments or the object involved.
For example, different shapes can have an area() function, but each shape calculates its area differently.

There are two main types of polymorphism in C++:
Compile-time polymorphism.
Run-time polymorphism.

A. Compile-time polymorphism
Compile-time polymorphism occurs when the compiler determines which function or operation to use during compilation.
It can be achieved through function overloading and operator overloading.

Explanation of compile  time polymorphism.cpp
add(int, int) adds two integers.
add(double, double) adds two decimal numbers.
add(int, int, int) adds three integers.
The compiler selects the appropriate function based on the arguments.
Notice that all three functions have the same name, add, but different parameter lists.
B. Run-time polymorphism
Run-time polymorphism occurs when the function to execute is determined while the program is running. It is commonly achieved through function overriding and virtual functions.

B. Run-time polymorphism
Run-time polymorphism occurs when the function to execute is determined while the program is running. It is commonly achieved through function overriding and virtual functions.
Example: Function overriding using virtual functions
Suppose a biomedical engineering program needs to display the operation of different medical devices. Each device can have its own implementation of operate().

Explanation of Run time polymorphism.cpp
Medical device is the base clas
The ECG and Ultrasound classes inherit from MedicalDevice.
Both derived classes override the operate() function with their own implementations.
The keyword virtual allows the appropriate overridden function to be selected at run time.
The pointer device can point to either an ECG object or an Ultrasound object.
When device->operate() is called, C++ executes the function belonging to the actual object being pointed to.
The override keyword helps the compiler verify that a derived-class function correctly overrides a virtual function.
The virtual destructor is included as good practice when a base class is intended to be used polymorphically.

Advantages of polymorphism
Flexibility: The same interface can support different implementations.
Code reusability: Shared interfaces can be used for different objects.
Easy extension: New derived classes can be added with their own implementations.
Simpler maintenance: Common code can operate on different object types without needing separate handling for each one.