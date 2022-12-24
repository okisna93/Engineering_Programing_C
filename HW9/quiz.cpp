#include <iostream>

using namespace std;

double overl(uint32_t a, uint32_t b){
    return 0;
}

int main()
{




    int *p1, *p2, *p3;
    p1 = new int;
    *p1 = 10;
    cout<<*p1<<endl;
    cout<<p1<<endl;
    p2 = new int;
    *p2 = 20;
    cout<<*p2<<endl;
    cout<<p2<<endl;
    p3 = p2;
    cout<<*p3<<endl;
    cout<<p3<<endl;
    *p3 = *p3**p2**p1;

    cout<<*p3<<endl;
    cout<<p3<<endl;
    cout<<*p2<<endl;

    bool a=(1 == (-1 + 2)) == (41 && true);
    cout<<a<<endl;


    cout<<overl(2,2)<<endl;


    return 0;
}
