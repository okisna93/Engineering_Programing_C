#include <iostream>
#include <vector>

using namespace std;

// -------------- Design Merge class here ---------------
// -----------------------------------------------------------
// Use template class for Merge class ,i.e., Merge<datatype> objectNName;
// No private/public variable or data member
//  No need for constructor
// Write the following functions:
// - merge function that take vector of vector
//   - write code that solve the problem of merging intervals that overlap
//   - implement exception handling for given (vector of vector) that have less than two intervals, e.g., [(1,2)] this is not accepted as input. because it has only one interval
//   - use error handling: try, throw, and catch
// - print function that print out intervals
// example of merging the following intervals: [(2,5),(1,4),(3,9),(20, 29),(7,16), (15, 27)];
//1   2   3   4   5   6   7   8   9   10  ...  15  16  17  18 ... 20 ... 27   28  29
//    *-----------*
//*-----------*
//        *-----------------------*
//                                                                 *----------------*
//                         *-------------------------*
//                                               *------------------------*
// The merge result wil be interval from 1 to 29
//*---------------------------------------------------------------------------------*

using namespace std;//liberary std



//
//int Merge(vector<vector<int>> a){
//    int emptyList[5];
//    for(int i=0;i<sizeof(a);i++){
//        for(int j=0;j<a[1];j++){
//            emptyList[i]=a[0]+j;
//        }
//    }
//    return emptyList
//}
//
//void Print(int k[]){
//    for(int i=0;i<sizeof(k);i++){
//            cout<<k[i]<<" ";
//    }
//}




int main() {

    vector<vector<int>> array4;
//    vector<vector<int>> ans;
//    //Make object of Class Merge with template T used as int
//    Merge<int> s;
//
    array4 = {{2,5},{1,4},{3,9},{20, 29},{7,16}, {15, 27}};
//    array4 = {{1,3},{2,6},{8,10},{15,18}};
//    array4 = {{2,5},{6,10},{15,20},{30,31}};
//    array4 = {{1,4}};


    //array4 = {{1,4},{2,5}};


    //Finding biggest number in the vector
    int maximum=0;
    for(int i=0;i<array4.size();i++){
        if(maximum<array4[i][1]){
            maximum=array4[i][1];
        }else{
            continue;
        }
    }

    //Finding total number of items if we combine all the vectors
    int numberElements=0;
    for(int j=0;j<array4.size();j++){
        for(int i=array4[j][0];i<=array4[j][1];i++){
            numberElements++;
        }
    }
    cout<<endl<<"Number of Elements : "<<numberElements<<endl;

    int k=0;
    int bigArray[numberElements];
    int *p;
    for(int iter=0;iter<array4.size();iter++){
        int difference=0;
        difference=array4[iter][1]-array4[iter][0]+1;
        p=new int[difference];

        for(int i=0;i<difference;i++){
            p[i]=array4[iter][0]+i;
        }

        cout<<"---------p---------"<<endl;
        for(int j=0;j<difference;j++){
            cout<<p[j]<<" ";
             bigArray[k]=p[j];
            k++;
        }
        cout<<endl;
        delete []p;
    }

    cout<<"-------Big Array------------"<<endl;
    for(int val:bigArray){
        cout<<val<<" ";
    }

    for (int j = 0; j < numberElements-1; j++){
        for (int i = 0; i < numberElements-1; i++){
          if (bigArray[i] > bigArray[i+1]) {
            int temp = bigArray[i];
            bigArray[i] = bigArray[i+1];
            bigArray[i+1] = temp;
         }
       }
    }

    cout<<endl<<"-------Combined Shorted ------------"<<endl;
    //printing combined array
    for(int val:  bigArray){
        cout<<val<<" ";
    }

    int mergedArraySize=0;
    for(int i=0;i<numberElements;i++){
        if(bigArray[i]!=bigArray[i+1]){
            mergedArraySize++;
        }else{
            continue;
        }
    }
    cout<<endl<<"Merged Array Size : "<<mergedArraySize<<endl;
    // Removing repeated elements from array;
    int mergedArray[mergedArraySize];
    int it=0;
    for(int i=0;i<numberElements+1;i++){
        if(bigArray[i]!=bigArray[i+1]){
            mergedArray[it]=bigArray[i];
            it++;
        }else{
            continue;
        }
    }

    for(int val:mergedArray){
        cout<<val<<" ";
    }




    return 0;
}


