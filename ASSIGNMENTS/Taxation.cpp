#include <iostream>
#include <iomanip>

int main() {
    int status;
    double cy;

    std::cout << "(0-Resident, 1-Non-resident)\n";
    std::cout << "Enter the residence status: ";
    if (!(std::cin >> status)) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    std::cout << "Enter the taxable income: ";
    if (!(std::cin >> cy)) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    double tax = 0.0;

    if (status == 0) {  // Resident tax logic
        if (cy <= 2820000) {
            tax = 0.0;
        } else if (cy <= 4020000) {
            tax = (cy - 2820000) * 0.10;
        } else if (cy <= 4920000) {
            tax = (cy - 4020000) * 0.20 + 120000;
        } else if (cy <= 120000000) {
            tax = (cy - 4920000) * 0.30 + 300000;
        } else {
            tax = ((cy - 4920000) * 0.30 + 300000) + ((cy - 120000000) * 0.10);
        }
    } 
    else if (status == 1) {  // Non-Resident tax logic
        if (cy <= 4020000) {
            tax = cy * 0.10;
        } else if (cy <= 4920000) {
            tax = (cy - 4020000) * 0.20 + 402000;
        } else if (cy <= 120000000) {
            tax = (cy - 4920000) * 0.30 + 582000;
        } else {
            tax = ((cy - 4920000) * 0.30 + 582000) + ((cy - 120000000) * 0.10);
        }
    } 
    else {
        std::cout << "Invalid residence status code. Use 0 or 1.\n";
        return 1;
    }

    // Set fixed-point notation and remove decimal points for cleaner whole-number presentation
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Tax is " << tax << "\n";

    return 0;
}
