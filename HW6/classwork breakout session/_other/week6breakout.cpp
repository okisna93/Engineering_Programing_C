#include <iostream>
#include "Car.h"

using namespace std;

/*
class Car{
public:
    int model;
    string color;
    string manufacturer;
    static int times;
public:
    Car(){
        times++;
    }

    void setModel(int m){
        model=m;
    }
    int getModel(){
        return model;
    }


    void setColor(string c){
        color=c;
    }
    string getColor(){
        return color;
    }


    void setMaker(string m){
        manufacturer=m;
    }
    string getMaker(){
        return manufacturer;
    }


    static int count(){
        return times;
    }

};
*/

int Car::times=0;
int main(){

    Car a;
    a.setModel(2005);
    a.setColor("Blue");
    a.setMaker("BMW");

    cout<<a.getModel()<<endl;
    cout<<a.getColor()<<endl;
    cout<<a.getMaker()<<endl;
    cout<<a.count()<<endl;
    cout<<"==============="<<endl;

    Car b;
    b.setModel(2005);
    b.setColor("Blue");
    b.setMaker("BMW");

    cout<<b.getModel()<<endl;
    cout<<b.getColor()<<endl;
    cout<<b.getMaker()<<endl;
    cout<<b.count()<<endl;
    cout<<"==============="<<endl;


    Car c;
    c.setModel(2005);
    c.setColor("Blue");
    c.setMaker("BMW");

    cout<<c.getModel()<<endl;
    cout<<c.getColor()<<endl;
    cout<<c.getMaker()<<endl;
    cout<<c.count()<<endl;
    cout<<"==============="<<endl;

    return 0;
}
