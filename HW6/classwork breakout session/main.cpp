#include <iostream>
#include "CarFunc.h"
#include "CarFunc.cpp"

using namespace std;

int CarFunc::times=0;
int main(){

    CarFunc a;
    a.setModel(2005);
    a.setColor("Blue");
    a.setMaker("BMW");

    cout<<"Model of the car is "<<a.getModel()<<endl;
    cout<<"Color of the car is "<<a.getColor()<<endl;
    cout<<"Manufacturer of the car is "<<a.getMaker()<<endl;
    cout<<"Counted Number of Total Cars "<<a.count()<<endl;
    cout<<"==============="<<endl;

    CarFunc b;
    b.setModel(2020);
    b.setColor("Red");
    b.setMaker("Tesla");

    cout<<"Model of the car is "<<b.getModel()<<endl;
    cout<<"Color of the car is "<<b.getColor()<<endl;
    cout<<"Manufacturer of the car is "<<b.getMaker()<<endl;
    cout<<"Counted Number of Total Cars "<< b.count()<<endl;
    cout<<"==============="<<endl;


    CarFunc c;
    c.setModel(2000);
    c.setColor("Blue");
    c.setMaker("Toyota");

    cout<<"Model of the car is "<<c.getModel()<<endl;
    cout<<"Color of the car is "<<c.getColor()<<endl;
    cout<<"Manufacturer of the car is "<<c.getMaker()<<endl;
    cout<<"Counted Number of Total Cars "<<c.count()<<endl;
    cout<<"==============="<<endl;

    return 0;
}

