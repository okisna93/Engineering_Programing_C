#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct PersonInfo{
    string name,adress,city;

};

struct student{
    int studentID;
    PersonInfo pData;
    short yearInSchool;
    double gpa;
};

void printingStruct(const student &p){
    cout<<p.pData.name<<endl;
    cout<<p.pData.city<<endl;
}
int main(){
    student s;
    s.pData.name="Okan";
    s.pData.city="Istanbul";
    s.studentID=4;

    printingStruct(s);

    student *a;
    a=&s;
    cout<<a->studentID<<endl;
    cout<<(*a).pData.city<<endl;
    cout<<(*a).studentID<<endl;
}
