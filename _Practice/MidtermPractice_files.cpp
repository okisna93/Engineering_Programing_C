#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(){
    string a;
    string b;
    string c;
    int k;

    fstream f;
    f.open("test2.txt",ios::out|ios::app);
    if(f.is_open()){
        cout<<"File is open"<<endl;
    }else{
        cout<<"File not founded"<<endl;
    }

    f<<endl<<"nasilsin";


    f.close();



    fstream n;
    n.open("test2.txt");
    while(!n.eof()){
        n>>a;
        cout<<a;
        cout<<b;
        cout<<endl<<a<<endl;
        //cout<<c<<endl;
    }
    //cout<<n.rdbuf();
    n.close();



    return 0;

}
