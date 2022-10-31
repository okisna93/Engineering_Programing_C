#include <iostream>

using namespace std;

int main(){
    int x[]={1,3,5,9,2,7};
    int *p;
    p=&x[0];

    for(int i=0;i<sizeof(x)/sizeof(x[0]);i++)
        cout<<x[i]<<" ";
    cout<<endl<<"**********"<<endl;

    cout<<*++p<<endl;
    cout<<++(*p)<<endl;

    for(int i=0;i<sizeof(x)/sizeof(x[0]);i++)
        cout<<x[i]<<" ";

    cout<<endl<<"**********"<<endl;

    cout<<*++p<<endl;


    cout<<endl<<"*****FIRST USE CASE CONST POINTER****"<<endl;
    const int y=7;
    const int *q=&y;
    cout<<*q+2<<endl;
    //cout<<(*q)++<<endl;
    cout<<*q<<endl;

    cout<<endl<<"*****SECOND USE CASE CONST POINTER****"<<endl;
    int a=10;
    int *const u=&a;
    cout<<u<<endl;
    cout<<*u+2<<endl;
    cout<<*u<<endl;
    cout<<++(*u)<<endl;
    cout<<*u<<endl;
    cout<<a<<endl;
    cout<<*u+5<<endl;
    cout<<a<<endl;
    cout<<u<<endl;


    return 0;
}
