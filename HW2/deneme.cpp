#include <iostream>
#include <cmath>

using namespace std;


void primeNumber(int x){
    bool checkPrime=true;
    if (x==0){
        checkPrime=false;
    }
    if (x==1){
        checkPrime=false;
    }

    for (int i=2;i<x;i++){
        if (x%i==0){
            checkPrime=false;
            break;
            }
        }


    if(checkPrime==false){
        cout<<"It is not a prime number";
    }
    else{
        cout<<"It is a prime number";
    }
}



int main(){
    primeNumber(17);
    return 0;
}

