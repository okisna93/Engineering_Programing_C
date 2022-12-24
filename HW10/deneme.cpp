#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x;
    int y;
    cout<<"Enter x : ";
    cin>>x;
    cout<<"Enter y : ";
    cin>>y;

    try{
        if(y==0){
            throw exception();
        }else{
            cout<<x/y<<endl;
        }

    }
    catch(exception e){
        //cout<<e.what()<<endl;
        cout<<"y=0 it's not possible"<<endl;
    }


    return 0;
}
