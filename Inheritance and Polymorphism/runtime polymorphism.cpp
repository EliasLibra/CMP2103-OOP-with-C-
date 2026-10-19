#include <iostream>
using namespace std;

// Base class
class MedicalDevice {
public:
    virtual void operate() {
        cout << "Medical device is operating"
             << endl;
    }

    virtual ~MedicalDevice() = default;
};

// Derived class 1
class ECG : public MedicalDevice {
public:
    void operate() override {
        cout << "ECG is recording heart activity"
             << endl;
    }
};

// Derived class 2
class Ultrasound : public MedicalDevice {
public:
    void operate() override {
        cout << "Ultrasound is producing images"
             << endl;
    }
};

int main() {
    ECG ecg;
    Ultrasound ultrasound;

    MedicalDevice* device;

    device = &ecg;
    device->operate();

    device = &ultrasound;
    device->operate();

    return 0;
}