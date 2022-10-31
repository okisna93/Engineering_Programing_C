#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int COLS=3;
void ShowArray(int [],int);
void show2DArray(int [][COLS],int);

int main(){
    const int Size=3;
    int values[Size];
    int count;
    for(count=0;count<6;count++)
        values[count]=count;

    int i=0;
    for(i;i<Size;i++)
        cout<<values[i];

    cout<<endl<<"***********************"<<endl;
    int numbers[]={10,20,30,40,50};
    for(int val:numbers)
        cout<<val<<" ";

    cout<<endl<<"***********************"<<endl;
    const int num_size=6;
    int num[num_size];
    for(int &vals:num){
        cout<<"Enter a Integer Value : ";
        cin>>vals;
    }
    for(int val:num)
        cout<<val<<" ";
    cout<<endl<<"***********************"<<endl;
    num[1]+=5;
    for(int val:num)
        cout<<val<<" ";

    cout<<endl<<"********Copy Array**********"<<endl;
    int copy_array[num_size];
    for(int i=0;i<num_size;i++){
        copy_array[i]=num[i];
    }
    for(int val:copy_array)
        cout<<val<<" ";

    cout<<endl<<"********Printing Char Array**********"<<endl;
    char Name[]="Henry";
    cout<<Name<<endl;

    cout<<endl<<"********Finding Highest Number**********"<<endl;
    int highest=copy_array[0];
    for(int i=0;i<num_size;i++){
        if(copy_array[i]>highest){
            highest=copy_array[i];
        }
    }
    cout<<"Highest Value is : "<<highest<<endl;

    cout<<endl<<"********Finding Smallest Number**********"<<endl;
    int smallest=copy_array[0];
    for(int i=0;i<num_size;i++){
        if(copy_array[i]<smallest){
            smallest=copy_array[i];
        }
    }
    cout<<"Smallest Value is : "<<smallest<<endl;

    cout<<endl<<"********Passing Array to Function**********"<<endl;
    ShowArray(copy_array,num_size);

    cout<<endl<<"********2D Array**********"<<endl;
    const int rows=3,cols=3;
    int exams[rows][cols];
    int k=1;
    for (int i=0;i<rows;i++){
        for(int a=0;a<cols;a++){
            exams[i][a]=k++;
        }
    }
    cout<<exams[0][0]<<" "<<exams[0][1]<<" "<<exams[0][2]<<endl;
    cout<<exams[1][0]<<" "<<exams[1][1]<<" "<<exams[1][2]<<endl;
    cout<<exams[2][0]<<" "<<exams[2][1]<<" "<<exams[2][2]<<endl;

    cout<<endl<<"********2D Array Passing Function**********"<<endl;
    show2DArray(exams,rows);

    return 0;
}

void ShowArray(int nums[],int size){
    for(int i=0;i<size;i++){
        cout<<nums[i]<<" ";
    }
}

void show2DArray(int nums[][COLS],int rows){
    for(int i=0;i<rows;i++){
        cout<<endl;
        for(int a=0;a<COLS;a++){
            cout<<nums[i][a]<<" ";
        }
    }
}
