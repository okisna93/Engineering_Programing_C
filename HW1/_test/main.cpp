// This is the Hello world project for c++ class
// Source file has function for taking full name as input
// This is will be used as main template for all other assignments

#include <iostream>
#include "fullName.h"
// If you have an issue with CMake to link function directly (uncomment line below)
//#include "src/fullName.cpp"
#include <string>

using namespace std;

int main() {

    std::cout << "Hello, World!" << std::endl;
    std::string n = fullName();
    std::cout << "My name is " << n;

    std::cout << "\nEnter an new name" << std::endl;
    string newname = "None";
    getline(cin, newname);
    std::cout << "My new name is: " << newname << std::endl;


    return 0;
}