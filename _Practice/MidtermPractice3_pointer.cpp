#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//f(x) = 2x
// introduction to call by reference and call by pointer

int f(int x); // function prototype

void hello() {
	cout << "hello";
}

//old, ugly c style
//void hello(void) {
	//cout << "hello";
//}

//void f(int x) {
	//for ( ; x > 0; x--)
		//cout << "hello";
//}

inline double hypot(double x, double y) {
	return sqrt(x*x + y*y);
}

void rect2polar1(double x, double y, double& r, double& theta) {
	r = hypot(x,y);
  theta = atan2(y, x);
}

void rect2polar2(double x1, double y1, double* r, double* theta) {
	*r = hypot(x1,y1);
  *theta = atan2(y1, x1);
}
//*r = 5 , r1 = 5
//*theta=0.6, theta1=0.6
//polar2rect

int main() {
    /*
	cout << "Please enter x,y";
	double x, y;
	cin >> x >> y;
	cout << endl;
	double r1, theta1;

	//rect2polar1(x, y, r1, theta1); // calls the reference one
	//cout << r1 << " " << theta1 << endl;
	rect2polar2(x, y, &r1, &theta1); // calls the pointer one
    cout << r1 << " " << theta1 << endl;


    int *p;
    int a=6;
    p=&a;
    cout<<&a<<endl;
    cout<<p<<endl;

    int *j;
    int k=6;
    j=&k;
    cout<<&k<<endl;
    cout<<j<<endl;
    */

    char s[]="abcd";
    for(int i=0;s[i]!='\0';i++){
        cout<<s[i]<<endl;
    }
    string a="abcd";
    cout<<a.size()<<endl;
    cout<<a.substr(0,2)<<endl;
	return 0;
}





