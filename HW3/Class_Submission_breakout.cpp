#include <iostream>

// Ismet Okan Celik
// Function checks whether there is any even number in the array
// if there is any even number than function returns true
// if there are only odd numbers in the array then function returns false

using namespace std;

bool evenNumbs(int nums[],int arraysize){
    bool flag=false;
    for(int i=0;i< arraysize;i++){
        if(nums[i]%2==0){
            flag=true;
        }
        else{
            continue;
        }
    }
    return flag;
}


int main(){
    const int array_size=6;
    int numbers[array_size];
    cout<<"Please enter 6 numbers = "<<endl;
    cin>>numbers[0];
    cin>>numbers[1];
    cin>>numbers[2];
    cin>>numbers[3];
    cin>>numbers[4];
    cin>>numbers[5];
    cout<<endl;
    cout<<"Flag = "<<evenNumbs(numbers,array_size)<<endl;
    return 0;
}

