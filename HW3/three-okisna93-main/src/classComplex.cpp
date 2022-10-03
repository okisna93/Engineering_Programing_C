#include <iostream>
#include "classComplex.h"

using namespace std;
// This part of creating typical class is commented because we are defining class in header file in addition to }; at the end
// in addition we need to indent function and indicate from which file it is coming e.g. std::cout.
// so we will use class name in .h file as: Complex::functionName(){}
//class Complex {
//    float real, img;
//public:
Complex::Complex() {
    //default constructor to initialize complex number to 0+0i
    // write your code here
    real=0;
    img=0;

}
Complex::Complex(float r, float i) {
    //parameterized constructor to initialize complex number.
    // write your code here
    real=r;
    img=i;

}
void Complex::set(){ // you can do set_real and another one for set_img
    // leave it empty, not required in the assignment
    // set mean change the current value
}
void Complex::get(){ // you can do get_real and another one for get_img
    // leave it empty, not required in the assignment
    // get mean return the current value and not print
}
void Complex::display(){
    // display function print complex number as real +j (imaginary)
    // write your code here
    char sign;
    if(img<0){
        sign='-';
        cout<<real<<img<<"j"<<endl;
    }else{
        sign='+';
        cout<<real<<sign<<img<<"j"<<endl;
    }
}


void Complex::print() {
    // this function is read only print complex number as real imaginary with space between two value
    // write your code here
    cout<<real<<" "<<img<<endl;

}

Complex Complex::negative(){
    // this function return the negative complex number
    // write your code here
    double r_Neg=real*-1;
    double img_Neg=img*-1;
    Complex neg(r_Neg,img_Neg);

    return neg;

}

Complex mul(Complex c1, Complex c2){
    // this function perform complex multiplication and return the value
    // write your code here
    Complex multip;
    multip.real=c1.real*c2.real-c1.img*c2.img;
    multip.img=c1.real*c2.img+c2.real*c1.img;

    return multip;

}
Complex add(Complex c1, Complex c2){
    // this function perform complex addition and return the value
    // write your code here

    Complex add;
    add.real=c1.real+c2.real;
    add.img=c1.img+c2.img;

    return add;

}
Complex sub(Complex c1, Complex c2){
    // this function perform complex subtraction and return the value
    // write your code here
    Complex sub;
    sub.real=c1.real-c2.real;
    sub.img=c1.img-c2.img;

    return sub;

}


Complex operator+(Complex c1, Complex c2) {
    // Overload (+) operator
    // write your code here
    Complex overload;
    overload.real=c1.real+c2.real;
    overload.img=c1.img+c2.img;
    return overload;

}

ostream& operator<<(ostream& ostr, Complex c){
    // Overload (<<) operator  to display complex number as real +j (imaginary)
    // write your code here
    char sign;
    if(c.img<0){
        sign='-';
    }
    else{
        sign='+';
    }

    ostr <<c.real <<sign<< abs(c.img) << 'j' ;
    return ostr;

}
