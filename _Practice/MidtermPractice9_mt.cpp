#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/*
class Shape{
public:
    int l,w;

    void set_values(int len, int wi){
        l=len;
        w=wi;
    }

    void show_data(){
        cout<<l<<" "<<w;
    }
};

class Rect:public Shape{
public:
    Rect(int lenght, int width):Shape(lenght,width)



};
*/

int main(){
    /*
    Shape a;
    a.set_values(1,2);
    a.print();





    if(Name=="Diamond" && x > 10){
        money = 100 * x;
        bank += 1;
    }else{
        bank -= 1;
    }


    cout<<money<<" "<<bank<<endl;

    area();
    */

    int *p;
    int *q;
    int x=5;

    q=&x;
    p=&x;

    cout<<*p<<" "<<*q<<endl;
    cout<<(*p)++<<" "<<*q<<endl;
    cout<<*p<<" "<<*q<<endl;

    int y=2;
    y=(float) y;

    double div;

    div=(float) x/y;
    cout<<setprecision(1)<<fixed;
    cout<<div<<endl;

    string Name="Diamond";
    int bank=40;
    int money=5;
    int k=100;
    (Name=="Dimond"),(k>10)?(money=100*k,bank++): bank--;
    cout<<bank<<" "<<money;

    return 0;
}
