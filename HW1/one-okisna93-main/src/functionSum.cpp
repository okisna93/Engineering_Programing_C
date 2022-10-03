#include "functionSum.h"

using namespace std;

/*
Problem1:
=========

Write C++ code that sum the numbers from 1 to 100

Problem2:
=========

a. Write C++ code that sum reciprocals (1/1 + 1/2 + … + 1/99 + 1/100)
b. Write C++ code that sum reciprocals (1/100 + 1/99 + ... 1/2 + 1/1)

compare a and b

Problem3:
=========
a. Write C++ code that sum multiplication reciprocals (1/1*1 + 1/2*2 + … ) \
b. Write C++ code that sum reciprocals (1/100*100 + 1/99*99 + ... )

*/


int sumUpTo(int x) {
    //write your code here
    int sum=0;
    for (int i=1;i<=x;i++){
        sum=sum+i;
    }
    return sum;
}

float sumReciprocalNormal(int x) {
    //write your code here
    float sum1=0;
	for (float i=1;i<=x;i++){
        float a=(1.0/i);
        sum1=sum1+a;
	}
	return sum1;
}

float sumReciprocalRev(int x) {
    //write your code here
    float sum2=0;
	for (float i=x;i>=1;i--){
        float a=(1.0/i);
        sum2=sum2+a;
	}
	return sum2;
}

float sumMysteryNormal(int x){
    //write your code here

    float sum3=0;
	for (float i=1;i<=x;i++){
        float a=(1.0/(i*i));
        sum3=sum3+a;
	}
	return sum3;
}

float sumMysteryRev(int x) {
    //write your code here
    float sum4=0;
	for (float i=x;i>=1;i--){
        float a=(1.0/(i*i));
        sum4=sum4+a;
	}
	return sum4;
}
