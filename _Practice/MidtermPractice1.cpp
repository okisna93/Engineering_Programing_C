#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    char letter;
    letter='A';
    cout<<letter<<endl;
    cout<<letter*2+1<<endl;


    char letter1;
    letter1='S';
    cout<<letter1<<endl;


    bool boolValue=false;
    cout<<boolValue<<endl;

    double amount=50;
    cout<<"Size of double = "<<sizeof(amount)<<" Bytes"<<endl;
    cout<<"Size of char = "<<sizeof(letter1)<<" Bytes"<<endl;
    int intValue=5;
    cout<<"Size of int = "<<sizeof(intValue)<<" Bytes"<<endl;
    float floatValue=3.6;
    cout<<"Size of float = "<<sizeof(floatValue)<<" Bytes"<<endl;

    cout<<"13%5 = "<<13%5<<endl<<endl;
   // cout<<"13%5.0 = "<<13%5.0<<endl;  // invalid operands of types 'int' and 'double' , both operants must be int


   /*
   int Hight, Width, Area;
   cout<<"Please Enter Hight Value for Rectangle = ";
   cin>>Hight;
   cout<<"Please Enter Width Value for Rectangle = ";
   cin>>Width;
   Area=Hight*Width;
   cout<<"Calculated Area = "<<Area<<endl;

   int Hight2, Width2, Area2;
   cout<<"Please Enter Hight and Width Value for Rectangle = ";
   cin>>Hight2>>Width2;
   Area2=Hight2*Width2;
   cout<<"Calculated Area = "<<Area2<<endl;


   int x,y,z;
   x=y=z=5;
   cout<<x<<y<<z<<endl;
   cout<<setw(6)<<x<<setw(6)<<y<<endl;
   cout<<x<<setw(12)<<y<<endl;

   double a=1321.426234;
   double b=152623.4236547;

   cout<<setprecision(2)<<fixed;
   cout<<a<<endl;
   cout<<b<<endl;


   string name;
   cout<<"Please enter your name : ";
   getline(cin,name);
   cout<<"Your name is : "<<name<<endl;

   int p=0;
   while(p<=10){
    cout<<p<<" ";
    p++;
   }
    cout<<endl<<"*************************"<<endl;
   for(int i=0;i<=100;i+=10){
    cout<<i<<" ";
   }
   cout<<endl<<"*************************"<<endl;
   int sum=0;
    for(int i=100;i>=0;i-=5){
    sum+=i;
    cout<<sum<<" ";
   }
   cout<<endl<<"*********FACTORIEL*********"<<endl;
   int factoriel=1;
   for(int i=1;i<=5;i++){
    factoriel*=i;
    cout<<factoriel<<" ";
   }
   cout<<endl<<factoriel<<endl;



    const double payrate=50;
    double min_hours=5;
    double hours;
    cout<<"How many hours did you work? :";
    cin>>hours;

    hours=hours<min_hours ? min_hours:hours;
    double charges;
    charges=payrate*hours;
    cout<<"The charge is "<<charges;
    cout<<"******************************"<<endl;
    */
    int g=4;

    int o=5;
    int result;

    cout<<"Value O= "<<o<<" "<<"Value G= "<<g<<endl;
    result=g++ + --o;
    cout<<"Result ="<<result<<endl;
    cout<<"Value O= "<<o<<" "<<"Value G= "<<g<<endl;
    result= o+g++ ;
    cout<<"Value O= "<<o<<" "<<"Value G= "<<g<<endl;
    cout<<"Result 2 ="<<result<<endl;
    result=++ o+g ;
    cout<<"Value O= "<<o<<" "<<"Value G= "<<g<<endl;
    cout<<"Result 2 ="<<result<<endl;



    return 0;
}
