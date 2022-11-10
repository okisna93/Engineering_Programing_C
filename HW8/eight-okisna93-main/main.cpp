#include <iostream>
#include <cstring>

using namespace std;

// -------------- Design your String class here ---------------
// -----------------------------------------------------------
// String class with private integer variable length of string and pointer to character str
// make the following functions
//  1. default constructor String (length, str) with length = zero and str pointer to nullptr
//  2. non-default constructor that take string length and character pointer
//     Use strlen() function to find the char length
//     Creat new dynamic array str with the new length
//     You will have to loop to assign each character
//  2. make deconstruct ~String that delete char pointer
//  3. Overload << operator to print out string.
//  4. Copy constructor String
//  5. Move constructor String
//  6. Assign operator = for copy constructor
//  7. Overload + operator to add/combine to String cat + dog => catdog


int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // Create String s = abc
    String s = "abc";
    // cout s
    cout << "s is: " << s << '\n';
    // Create String s = def
    String s2 = "def";
    // cout s2
    cout  << "s2 is: " << s2 << '\n';
    // create String s3 equal s2
    String s3 = s2; // copy constructor
    // cout s3
    cout << "s3 is: " << s3 << " copy constructor "<<'\n';
    //	Create String s4 that is assigned to s added to s2
    String s4 = s + s2;  // abcdef // copy constructor
    // cout s4
    cout << "s4 is: " << s4 << " copy constructor of s + s2"<< '\n';
    // Create s5 and move s4
    String s5 = move(s4); // move constructor
    // cout s5
    cout << "s5 is: " << s5 << '\n';
    cout << "cout s4 should give you error after move()" << endl;
    cout << s4 << '\n';
    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    return 0;
}