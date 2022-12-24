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


template<class T>
class Merge{
public:
    vector<vector<T>> merge(vector<vector<T>> array4){

        try{
            if(array4.size()<2){
                throw exception();
            }else{
                //Finding total number of items if we combine all the vectors
                int numberElements=0;
                for(int j=0;j<array4.size();j++){
                    for(int i=array4[j][0];i<=array4[j][1];i++){
                        numberElements++;
                    }
                }
                //cout<<endl<<"Number of Elements : "<<numberElements<<endl;

                //Creating one big array to save all the intervals element by element
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

                    //cout<<"---------p---------"<<endl;
                    for(int j=0;j<difference;j++){
                        //cout<<p[j]<<" ";
                        bigArray[k]=p[j];
                        k++;
                    }
                    //cout<<endl;
                    delete []p;
                }

                //Sorting the big array elements
                for (int j = 0; j < numberElements-1; j++){
                    for (int i = 0; i < numberElements-1; i++){
                        if (bigArray[i] > bigArray[i+1]) {
                            int temp = bigArray[i];
                            bigArray[i] = bigArray[i+1];
                            bigArray[i+1] = temp;
                        }
                    }
                }

                // Removing repeated elements from array;
                vector<T> mergedArray;
                for(int i=0;i<numberElements;i++){
                    if(bigArray[i]!=bigArray[i+1]){
                        mergedArray.push_back(bigArray[i]);
                    }else{
                        continue;
                    }
                }
                vector<vector<T>> returnedVec;
                returnedVec.push_back(mergedArray);

                return returnedVec;
            }
        }
        catch(exception e){

            cout<<"Input vector has less than two intervals, e.g., [(1,2)] this is not accepted as input"<<endl;
            cout<<"Elements of input vector = ";
            return array4;

        }

    }

    //Print Function
    void print(vector<vector<T>> array4){
        for(int i=0;i<array4.size();i++){
            for(int j=0;j<array4[i].size();j++){
                cout<<array4[i][j]<<" ";
            }
        }
    }


};

int main() {

    vector<vector<int>> array1, array2, array3, array4;
    vector<vector<int>> ans;
    //Make object of Class Merge with template T used as int
    Merge<int> s;

    array1 = {{2,5},{1,4},{3,9},{20, 29},{7,16}, {15, 27}};
    array2 = {{1,3},{2,6},{8,10},{15,18}};
    array3 = {{2,5},{6,10},{15,20},{30,31}};
    array4 = {{1,4}};

    // Merge first array and print
    cout << "array 1 after merge: \n";
    ans = s.merge(array1);
    s.print(ans);

    // Merge second array and print
    cout << "\narray 2 after merge: \n";
    ans = s.merge(array2);
    s.print(ans);

    // Merge third array and print
    cout << "\narray 3 after merge: \n";
    ans = s.merge(array3);
    s.print(ans);

    // Merge forth array and print
    cout << "\narray 4 after merge: \n";
    ans = s.merge(array4);
    s.print(ans);


    return 0;
}


