#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double t,v;
    double w;
    bool canRun=true;
    while(canRun){
        cout<<"Please enter a wind speed value = ";
        cin>>v;
        if(v>3){
            cout<<"Wind speed is valid."<<endl;
            canRun=true;
        }else{
            cout<<"Wind Speed is not valid."<<endl;
            continue;
        }
        cout<<"Please enter a temperature value = ";
        cin>>t;
        if(t<=50){
            cout<<"Temperature value is valid."<<endl;
            canRun=true;
        }
        else{
            cout<<"Temperature value is not valid."<<endl;
            continue;
        }

        if(canRun==true){
            w = 35.74 + 0.6215*t*(pow(v,0.16)) + 0.4275*t*(pow(v,0.16));
            cout<<"Wind chill value ="<<w;
            break;
        }

    }

}
