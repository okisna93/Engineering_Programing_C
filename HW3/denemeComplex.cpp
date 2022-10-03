#include <iostream>

using namespace std;

class Complex{
    float real;
    float img;


public:
    Complex();
    Complex(float,float);
    void Display();
    void print();
    Complex negative();
    friend Complex mul(Complex c1,Complex c2);
    friend Complex add(Complex c1,Complex c2);
    friend Complex sub(Complex c1,Complex c2);
    friend Complex operator+(Complex c1, Complex c2);
    friend ostream& operator<<(ostream& ostr, Complex c);
};


Complex::Complex(){
    real=0;
    img=0;
}

Complex::Complex(float r,float i){
    real=r;
    img=i;
}

void Complex::Display(){

    char sign;
    if(img<0){
        sign='-';
        cout<<real<<img<<"j"<<endl;
    }
    else{
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



Complex operator+(Complex c1, Complex c2){
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



int main(){

    Complex c1(-3,-4);
    Complex c2(-3,-4);
   // Complex c3;
   // c3=c1+c2;
    c1.Display();
    c2.Display();

    c1.print();

    // Negative function
    Complex result;
    result=c1.negative();
    result.Display();

    Complex result2;
    result2=mul(c1,c2);
    result2.Display();

    Complex result3;
    result3=add(c1,c2);
    result3.Display();

    Complex result4;
    result4=sub(c1,c2);
    result4.Display();

    Complex result5;
    result5=c1+c2;
    result5.Display();

    cout<<c1;




    return 0;
}
