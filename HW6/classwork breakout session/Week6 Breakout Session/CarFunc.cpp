
#include "CarFunc.h"


using namespace std;


// Counts number of the car whenever a new car is declared
CarFunc::CarFunc(){
    times++;
}

void CarFunc::setModel(int m){
    model=m;
}
int CarFunc::getModel(){
    return model;
}


void CarFunc::setColor(string c){
    color=c;
}
string CarFunc::getColor(){
    return color;
}


void CarFunc::setMaker(string m){
    manufacturer=m;
}
string CarFunc::getMaker(){
    return manufacturer;
}



