#include <iostream>
#include <string>



using namespace std;

// -------------- Design your Zebra class here ---------------
// -----------------------------------------------------------
// name the Class Zebra()
// name the function that count function getCount()
/// name the function that print name getName()
// private: create variable name as string and count as int make it static and set it externally before main()
//
// Create constructor that take directly the name
// Once object is created inside constructor print the following
//     Hello I'm just born! my name is:  "object name" and new line

// Create function that called getName that return name without printing

// Make a destructor, it should reduce count and print the following
//     Ugh! I'm dying and the current count

// Create a function that called getCount that return the current count

//}; end of class

class Zebra{
private:
    string name;
    static int count;

public:
    //Zebra()
    //{
     //   name;
    //}
    Zebra(string n){
        name=n;
        cout<<"Hello I'm just born! my name is: "<<name<<endl;
        count++;
    }
    string getName(){
        return name;
    }
    ~Zebra(){
        count--;
        cout<<"Ugh! I'm dying and the current count : "<<count<<endl;
    }
    static int getCount(){
        return count;
    }
};


// -------------- Design your ZebraKid class here ---------------
// -----------------------------------------------------------
// Create a another class ZebraKid that inherit Zebra functions (getName)
// ZebraKid only have constructor
// initial constructor based on Zebra constructor
// don't write any other function, you should be able to inherit Zebra function
//}; end of class
class ZebraKid:public Zebra
{
public:
//    ZebraKid():Zebra(){
 //       Zebra::getName();
  //  }
    ZebraKid(string n):Zebra(n){
        Zebra::getName();
    }
};

// Set Zebra count equal zero
int Zebra::count=0;

// -------------- Design void function f() ---------------
// -----------------------------------------------------------
// Make function f() that do the following when used:
//   - Print out the current count
//   - add two Zebra object when called
//      Zebra with name Joker
//      Zebra with name Alice
//   - Print the new count
// when the function is called it will construct object and when it scopes finish
//... it will destruct and print messages of object is dying in same time

void f(){
    cout<<Zebra::getCount()<<endl;
    Zebra a("Joker");
    Zebra b("Alice");
    cout<<Zebra::getCount()<<endl;
}



int main() {


   // Zebra a("James");
    //cout<<a.getName()<<endl;
    //cout<<a.Zebra::getName()<<endl;
    //cout<<a.Zebra::getCount()<<endl;

   // Zebra b("James");
    //cout<<b.getName("James")<<endl;
    //cout<<b.getCount()<<endl;

    //ZebraKid c("Kiddo Zebra");
    //cout<<c.getName("Kiddo Zebra")<<endl;

    //f();

    //cout<<Zebra::getCount();









    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;
    // You should be able to run main() with your classes
    // No need to edit this part unless for debugging
    // print the initial count number
    cout << Zebra::getCount() << '\n'; // zero!
    // Creat object a with name Morgana
    Zebra a("Morgana");
    // Print the current count number of Zerba object
    cout << Zebra::getCount() << '\n';
    // Use the function f() above
    f();
    cout << "####" << endl;
    // Use the function f() above again
    f();
    cout << "####" << endl;
    // print out the current number of zebra
    cout << Zebra::getCount() << '\n';
    // Get the name of the zebra object a
    cout << a.Zebra::getName() << '\n';
    cout << "####" << endl;

    // create  ZebraKid object
    ZebraKid e("James");
    // Use the getName() form Zebra class
    cout << e.getName() << '\n';
    cout << Zebra::getCount() << '\n';




    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    cout << " #### This is after the program is completely done #####" << endl;
    cout << " ### The last remaining object should get destructed ###" << endl;


    return 0;

}
