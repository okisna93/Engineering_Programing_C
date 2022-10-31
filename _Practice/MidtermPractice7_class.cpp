#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Complex{
public:
    double real;
    double img;
public:
    friend ostream& operator<<(ostream& ostr,Complex c);
    Complex(){
        real=0;
        img=0;
    }
    Complex(double r,double i){
        real=r;
        img=i;
    }
    Complex add(Complex a, Complex b){
        Complex c;
        c.img=a.img+b.img;
        c.real=a.real+b.real;
        return c;
    }
    Complex operator+(Complex b){
        Complex c;
        c.img=img+b.img;
        c.real=real+b.real;
        return c;
    }
    Complex operator-(Complex b){
        Complex c;
        c.img=img-b.img;
        c.real=real-b.real;
        return c;
    }


    void Display(){
        cout<<real<<" , "<<img<<"i"<<endl;
    }
};

ostream& operator<<(ostream& ostr,Complex c){
    ostr<<c.real<<" "<<c.img<<endl;
    return ostr;
}


//Complex operator+(Complex a,Complex b){
//    Complex c;
//    c.img=a.img+b.img;
//    c.real=a.real+b.real;
//    return c;
//}

//Complex operator-(Complex a,Complex b){
//    Complex c;
//   c.img=a.img-b.img;
//    c.real=a.real-b.real;
//    return c;
//}



int main(){
    Complex a(2,3);
    Complex b(2,3);
    b.Display();


    Complex result;
    result=result.add(a,b);
    result.Display();

    Complex z(5,5);
    Complex y(2,2);
    Complex result2=z+y;
    result2.Display();

    Complex result3;
    result3=z-y;
    result3.Display();

    cout<<"****"<<endl;
    cout<<result3<<endl;

    return 0;
}
