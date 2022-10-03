#include <iostream>
#include <string>
#include "fullName.h"

using namespace std;

// Change X to None
string name = "None";

string fullName(){
    cout << "Please write your full name" << endl;
    getline(cin, name);

    return name;
}









