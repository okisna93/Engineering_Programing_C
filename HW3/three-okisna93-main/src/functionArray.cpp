#include <iostream>


using namespace std;

// Write functions for problem one here

void ReadElements(int *A, int n){
    // write your code here
    cout << "Please enter "<<n<<" array elements =";

    for(int i=0;i<n;i++){
        cin>>*(A+i);
    }

}
void PrintElements(int *A, int n){
    // write your code here
    for (int i=0;i<n;i++){
        cout<<*(A+i)<<endl;
    }

}
void PrintElementsRev(int *A, int n) {
    // write your code here
    for (int i=0;i<n/2;i++){
        swap(*(A+i),*(A+n-1-i));
    }

    for (int i=0;i<n;i++){
        cout<<*(A+i)<<endl;
    }

}
void OddsOnly(int *A, int n, int *&odds, int &m){
    // write your code here

    // count how many odd number you have
    m=0;
    for (int i=0;i<n;i++){
        if(A[i]%2!=0){
            m++;
        }
    }



    // allocate odds new array for odds in memory equal number of odd's number we found
    odds = new int[m];

    // Now fill the odds numbers in the new array
    // fill odds
    // index: 0 1 2 3
    // A    : 1 4 2 5
    // new index:     0 1
    // odds:          1 5
    // actual index:  0 3
    int k=0;
    for(int i=0;i<n;i++){
        if(A[i]%2!=0){
            odds[k]=A[i];
            k++;
        }

    }


    // Use you function PrintElements in main.cpp to print new odds array odds and m number

}

