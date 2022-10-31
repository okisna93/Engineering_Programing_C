// Ismet Okan Celik
#include <iostream>
#include <string>

using namespace std;

class Car{
public:
    int model;
    int year;
    string manufacturer;

public:
    // Default Constructor and Destructor
    Car(){
    }
    ~Car(){
    }

    // Constructor that can set parameters as model, year and manufacturer
    Car(int m,int y,string man){
        model=m;
        year=y;
        manufacturer=man;
    }


    // Setters and Getters
    void setModel(int m){
        model=m;
    }
    int getModel(){
        return model;
    }

    void setYear(int y){
        year=y;
    }
    int getYear(){
        return year;
    }
    void setManufacturer(string m){
        manufacturer=m;
    }
    string getManufacturer(){
        return manufacturer;
    }
};


//Truck class that inherit Car class
class Truck: public Car{
public:
    Truck(int m,int y,string man):Car(m,y,man){
        Car truck1(m,y,man);
    }
};

int main(){

    // Creating object of a  car and assigning variables
    Car car1(2005,2022,"Tesla");
    cout<<"Car Manufacturer is "<<car1.getManufacturer()<<endl;
    cout<<"Car Model is "<<car1.getModel()<<endl;
    cout<<"Car Year is "<<car1.getYear()<<endl;


    cout<<"==================================="<<endl;

    // Creating object of a truck and assigning variables
    Truck a(2003,2010,"Mercedes");
    cout<<"Truck Manufacturer is "<<a.Truck::getManufacturer()<<endl;
    cout<<"Truck Model is "<<a.Truck::getModel()<<endl;
    cout<<"Truck Year is "<<a.Truck::getYear()<<endl;


    return 0;
}
