
#include <string>
#ifndef CLASSWORK2_CARFUNC_H
#define CLASSWORK2_CARFUNC_H

using namespace std;
class CarFunc {

public:
    int model;
    string color;
    string manufacturer;

    // Static variable defined to store number of car
    static int times;
public:
    CarFunc();
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


#endif //CLASSWORK2_CARFUNC_H
