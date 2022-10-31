#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printArray(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int nums[]={4,7,11};
    int *valptr=nums;

    int *p;
    p=nums;
    cout<<"pointer "<<*(p+1)<<endl;


    cout<<valptr<<endl;
    cout<<*(++valptr)<<endl;
    cout<<*(--valptr)<<endl;

    cout<<"****Memory Allocation*******"<<endl;
    double *dptr=new double;
    cout<<dptr<<endl;
    cout<<*dptr<<endl;

    cout<<"Start"<<endl;
    for(int i=0;i<=4;i++){
        if(i%2!=0){
            cout<<"in the loop"<<endl;
            break;
        }
        cout<<"eman"<<endl;
    }
    cout<<"**************"<<endl;
    cout<<sizeof(nums)/sizeof(nums[0])<<endl;
    printArray(nums,sizeof(nums)/sizeof(nums[0]));


    return 0;
}
