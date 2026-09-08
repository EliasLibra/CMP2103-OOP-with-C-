// The income tax rate for individuals in business depends on the income bracket in which the individual falls.
// Resident individuals enjoy a tax free annual income threshold of UGX. 2,820,000 per annum. The
// balance is taxed at 10%, 20% or 30% depending on the income bracket. Individuals who earn
// above UGX 120,000,000 pa pay an additional 10% on the income above 120m.
// +----------------------+------------------------------------------+------------------------------------------+
// | CHARGEABLE INCOME, CY| RESIDENTS                                | NON-RESIDENTS                             |
// | (UGX Annual)         | RATE OF TAX                              | RATE OF TAX                               |
// +----------------------+------------------------------------------+------------------------------------------+
// | 0 to 2,820,000       | Nil                                      | CY x 10%                                  |
// | 2,820,000 to         | (CY - 2,820,000) x 10%                   | CY x 10%                                  |
// | 4,020,000            |                                          |                                           |
// | 4,020,000 to         | (CY - 4,020,000) x 20% + 120,000         | (CY - 4,020,000) x 20% + 402,000          |
// | 4,920,000            |                                          |                                           |
// | 4,920,000 to         | (CY - 4,920,000) x 30% + 300,000         | (CY - 4,920,000) x 30% + 582,000          |
// | 120,000,000          |                                          |                                           |
// | Above 120,000,000    | [(CY - 4,920,000) x 30% + 300,000]       | [(CY - 4,920,000) x 30% + 582,000]        |
// |                      | + [(CY - 120,000,000) x 10%]             | + [(CY - 120,000,000) x 10%]              |
// +----------------------+------------------------------------------+------------------------------------------+

// You are to write a program to compute personal income tax. Your program should prompt
// the user to enter the residence status and taxable income and then compute the tax. Enter 0 for
// resident and 1 for non-resident.

// Output
// (0-Resident, 1-Non-resident)
// Enter the residence status: 0
// Enter the taxable income: 4,000,000
// Tax is 118000.

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
