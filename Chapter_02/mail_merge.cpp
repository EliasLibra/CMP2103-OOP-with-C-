// Write a program that outputs an acceptance letter for Makerere University. It should prompt a user to enter their first name, last name, study program, academic year.
// The program should have autodates

// Example:

// Date: 27th August 2026

// To: John Okello,

// Dear John,

// CONGRATULATIONS! I am pleased to inform you that the Makerere University 
// Admissions Board has approved your application for admission to the 
// 2027/2028 academic year.

// You have been offered a place for the following course:
// PROGRAM: Bachelor of Science in Computer and Communication Engineering

// As a student of Makerere University, you will be part of a historic 
// institution dedicated to academic excellence and innovation. Please ensure 
// that you report to the Academic Registrar's office with your original 
// academic documents for verification during the orientation week.

// We look forward to welcoming you to the Makerere University.

// Yours sincerely,


// John Doe
// Registra
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

// Function to get the correct suffix for the day (e.g., 1st, 2nd, 3rd, 4th)
std::string getOrdinalSuffix(int day) {
    if (day >= 11 && day <= 13) {
        return "th";
    }
    switch (day % 10) {
        case 1:  return "st";
        case 2:  return "nd";
        case 3:  return "rd";
        default: return "th";
    }
}

// Function to get the automatically formatted current date
std::string getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);

    int day = localTime->tm_mday;
    std::string suffix = getOrdinalSuffix(day);

    // Array of month names
    std::string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    std::string monthName = months[localTime->tm_mon];
    int year = localTime->tm_year + 1900;

    return std::to_string(day) + suffix + " " + monthName + " " + std::to_string(year);
}

int main() {
    std::string firstName, lastName, studyProgram, academicYear;

    // Prompting user for input
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Enter study program: ";
    std::getline(std::cin, studyProgram);

    std::cout << "Enter academic year (e.g., 2027/2028): ";
    std::getline(std::cin, academicYear);

    // Fetch the automatic date
    std::string autoDate = getCurrentDate();

    // Output the acceptance letter
    std::cout << "\n--------------------------------------------------\n";
    std::cout << "Date: " << autoDate << "\n";
    std::cout << "To: " << firstName << " " << lastName << ",\n\n";
    std::cout << "Dear " << firstName << ",\n\n";
    std::cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    std::cout << "Admissions Board has approved your application for admission to the\n";
    std::cout << academicYear << " academic year.\n\n";
    std::cout << "You have been offered a place for the following course:\n";
    std::cout << "PROGRAM: " << studyProgram << "\n\n";
    std::cout << "As a student of Makerere University, you will be part of a historic\n";
    std::cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    std::cout << "that you report to the Academic Registrar's office with your original\n";
    std::cout << "academic documents for verification during the orientation week.\n\n";
    std::cout << "We look forward to welcoming you to Makerere University.\n\n";
    std::cout << "Yours sincerely,\n\n";
    std::cout << "John Doe\n";
    std::cout << "Registrar\n";
    std::cout << "--------------------------------------------------\n";

    return 0;
}
