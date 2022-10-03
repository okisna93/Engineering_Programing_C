#include <iostream>

using namespace std;

void readNumbers(int *A,int n){

    cout<<"Please enter elements = ";

    for(int i=0;i<n;i++){
        cin>>*(A+i);
    }
}

void printsNumb(int *A,int n){
    for (int i=0;i<n;i++){
        cout<<*(A+i)<<" ";
    }
}

void PrintElementsRev(int *A, int n) {
    // write your code here

    for (int i=0;i<n/2;i++){
        swap(*(A+i),*(A+n-1-i));
    }

}

void oddsOnly (int * A, int n, int *& odds, int & m)
{
	// calc. m
	m = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] % 2 != 0)
			m++;
	}
	// here m contains the number of even elements

	// allocate evens array
	odds = new int [m];

	// fill evens
	// index: 0 1 2 3
	// A    : 1 2 7 4
	// index: 0 1
	// evens: 2 4
	// actual:2 4
    int k=0;
    for(int i=0;i<n;i++){
        if(A[i]%2!=0){
            odds[k]=A[i];
            k++;
        }

    }
}


int main(){
    int n;
	cout << "Please enter number of elements:";
	cin >> n;
    int * A = new int [n];

    //const int Size=4;
   // int num[Size];

    readNumbers(A,n);
    cout<<"Printing Array Elements = ";
    printsNumb(A,n);
    cout<<endl<<"#########"<<endl;

    cout<<"Printing Reversed Array Elements = ";
    PrintElementsRev(A,n);
    printsNumb(A,n);


    cout<<endl<<"#########"<<endl;

    cout<<"Printing Odds = ";
    int * e = nullptr;
	int m = 0;
    oddsOnly(A,n,e,m);

    printsNumb(e,m);

    delete [] A;
	delete [] e;


    return 0;
}
