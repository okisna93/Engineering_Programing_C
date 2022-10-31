#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int math(double r, double c){
    return r*c;
}

void testingPointer1(double r,double c, double *a){
    *a=math(r,c);
    //cout<<a<<endl;
    //cout<<*a<<endl;
}

void testingPointer2(double r,double c, double &a){
    a=math(r,c);
    //cout<<a<<endl;
}

int main(){

 /*
    double a;
    cout<<"Enter a Number = ";
    cin>>a;

    if(a>=90)
        cout<<"A";
    else if(a>=80)
        cout<<"B ";
    else if(a>=70)
        cout<<"C ";
    else if(a>=60)
        cout<<"D ";
    else
        cout<<"You could not passed the barrier";
    */

    if(int i=0;i<10){
        cout<<"The number is small";
    }
    else{
        cout<<"Number is good";
    }

    cout<<endl<<"*******************"<<endl;
    int x=12,y=5,z=-4;

    cout<<endl<<"************************"<<endl;
    string name1="Mary";
    string name2="Mark";
    char u='y';
    char k='k';
    cout<<u*1<<" "<<k*1<<endl;


    double r1;
    cout<<"function value = "<<math(2,2)<<endl;

    testingPointer1(2,2,&r1);
    cout<<"****POINTER -&*****"<<endl;
    cout<<"r1 = "<<r1<<endl;

    cout<<"****REFERANCE*****"<<endl;
    testingPointer2(2,2,r1);
    cout<<"r1 = "<<r1;



    return 0;
}
