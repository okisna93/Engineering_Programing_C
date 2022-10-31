#include <iostream>
#include <string>

using namespace std;

class Zebra{
private:
    string name;
public:
    Zebra(){
        name;
    }
    Zebra(string n){
        name=n;
        cout<<"Hello I'm just born! my name is: "<<name<<endl;
    }
    string getName(){
        return name;
    }
};

int main(){

    Zebra a("James");
    cout<<a.Zebra::getName()<<endl;

    return 0;
}
