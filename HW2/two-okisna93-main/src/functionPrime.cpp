#include <iostream>
#include <cmath>

using namespace std;
// Write code that check if number is prime or not

void isPrime(int x) {

    // write your code here
    // consider  a special case in your function, i.e., x = 1 is not prime.
    // no return value just print if prime or not
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