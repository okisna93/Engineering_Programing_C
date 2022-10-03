#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    const double pi = 3.14159265358979323846;

    ifstream thefile;
    thefile.open("robotpath.dat");

    if (thefile.is_open()){

        cout << "File is open and ready" << '\n';
        cout << " " << '\n';

    }else{
        cout << "File not found!" << '\n';
        cout << " " << '\n';
    }
    double r,theta;

    while (!thefile.eof()){
        thefile>>r>>theta;
        cout<<"distance= "<<r<<" angle= "<<theta<<endl;

        double convRadian;
        convRadian=(theta*pi)/180;
        cout<<"AngleRadian= "<<convRadian<<endl;

        double x,y;
        x=r*cos(convRadian);
        y=r*sin(convRadian);
        cout<<setprecision(8);
        cout<<" x="<<x<<" y="<<y<<endl<<endl;

    }
    thefile.close();

}
