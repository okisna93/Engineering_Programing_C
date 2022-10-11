#pragma once
#include <string>
using namespace std;

class Car{
public:
    int model;
    string color;
    string manufacturer;
    static int times;
public:
    Car();
    void setModel(int m);
    int getModel();


    void setColor(string c);
    string getColor();


    void setMaker(string m);
    string getMaker();


    static int count(){
        return times;
    }

};
