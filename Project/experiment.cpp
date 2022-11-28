#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main(){
    auto a="Merhaba ";
    auto b=5;
    auto h=5.5;
    auto j='a';

    int i=9;
    string y="bdasf";
    string c="b";
    char d='a';
    float g=1.5;


    cout<<typeid(a).name()<<endl;
    cout<<typeid(i).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(h).name()<<endl;
    cout<<typeid(j).name()<<endl;
    cout<<typeid(y).name()<<endl;
    cout<<typeid(c).name()<<endl;
    cout<<typeid(d).name()<<endl;
    cout<<typeid(g).name()<<endl;



    return 0;
}
