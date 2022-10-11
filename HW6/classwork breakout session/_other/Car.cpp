#include "Car.h"

Car::Car(){
    times++;
}

void Car::setModel(int m){
    model=m;
}
int Car::getModel(){
    return model;
}


void Car::setColor(string c){
    color=c;
}
string Car::getColor(){
    return color;
}

void Car::setMaker(string m){
    manufacturer=m;
}
string Car::getMaker(){
    return manufacturer;
}



