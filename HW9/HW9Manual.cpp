#include <iostream>

using namespace std;
// -------------- Design Matrix class here ---------------
// -----------------------------------------------------------
// private variable and member function:
//  Variables number of rows, number of columns, type_double pointer to pointer m for the matrix (** m), you can use m[i_idx][j_idx]
//  You can use int or uint_32_t (unsigned) for number of rows and columns
//  Private member function, utility function:
//  This function set up the Matrix and create dynamic array pointer in row and each row point array of columns
//  Matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols), m(new double*[rows]){
//  Write here your code
//  loop each pointer rows[idx] and for each row create array of size columns
//  }
// make the following functions
//  1. Constructor that take #of rows and #of columns and initial value for all elements
//     Matrix G(2, 2, 0) ===>
//                                 index_0  index_1
//                       index_0     0       0
//                       index_1     0       0
//  2. Copy constructor
//  3. Assign operator = for copy constructor
//     - use swap(new_matrix, original_matrix)
//  4. Deconstruct  ~Matrix: loop inside each pointer and delete it
//  5. Move constructor
//  6. Overload () operator twice:
//     - first: return_type is double and member function is const
//     - second: return_type is reference double and member function is not const
//  7. overload [] operator
//     - return_type double pointer
//  8. Overload << operator to print out matrix similar to:
//                            0   0
//                            0   0

class Matrix{
private:
    //Variables;
    uint32_t rows;
    uint32_t cols;
    double **m;
    //Member Function, set up matrix
    Matrix(uint32_t rows, uint32_t cols):rows(rows),cols(cols),m(new double*[rows]){
        for(int i=0;i<rows;i++){
            m[i]=new double[cols];
        }
    }

public:
    //Constructor takes rows and cols and intialize it
    Matrix(uint32_t x, uint32_t y, double initial_val):Matrix(x,y){
        for(int i=0;i<rows;i++){
            for(int a=0;a<cols;a++){
                m[i][a]=initial_val;
            }
        }
    }

    //Copy Constructor
    Matrix(const Matrix& obj){
        for(int i=0;i<rows;i++){
            for(int a=0;a<cols;a++){
                m[i][a]=obj.m[i][a];
            }
        }
    }

    void swap(Matrix& new_m,Matrix& old_m){
        using std::swap;
        swap(new_m.rows,old_m.rows);
        swap(new_m.cols,old_m.cols);
    }

    //Asign operator= for copy constructor
    Matrix& operator=(Matrix& obj){
        swap(*this,obj);
        return *this;
    }

    //Deconstruct Matrix
    ~Matrix(){
        for(int i=0;i<rows;i++){
            for(int a=0;a<cols;a++){
                delete m[a];
            }
            delete []m;
        }

    }
    Matrix(const Matrix&& obj){
        for(int i=0;i<rows;i++){
            for(int a=0;a<cols;a++){
                m[i][a]=obj.m[i][a];
            }
        }
        for(int i=0;i<rows;i++){
            delete obj.m[i];
            obj.m[i]=nullptr;
        }
        delete []obj.m;
        m=nullptr;
    }

    double operator()(uint32_t r,uint32_t j)const{
        return m[r][j];

    }
    double& operator()(uint32_t r,uint32_t j){
        return m[r][j];

    }

    double* operator[](uint32_t r){
        return m[r];
    }
    friend ostream& operator<<(ostream& ostr,Matrix& obj);

    Matrix operator+(const Matrix& obj){
        Matrix overload(rows,cols,0);
        for(int i=0;i<rows;i++){
            for(int a=0;a<cols;a++){
                overload.m[i][a]=m[i][a]+obj.m[i][a];
            }
        }
        return overload;
    }

};

ostream& operator<<(ostream& ostr,Matrix& obj){
    for(int i=0;i<obj.rows;i++){
        for(int a=0;a<obj.cols;a++){
            ostr<<obj[i][a]<<" ";
        }
        ostr<<endl;
    }
    return ostr;
}


int main(){
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // Create matrix a with 4 rows and 3 columns filled with values in zero
    Matrix a(4, 3, 0.0);
    // print out the complete matrix
    cout << a << endl;
    // print out one element in the matrix
    // overload of () return const value
    cout << a(2,3) << endl;
    // change one element in a(2,2) equal 1.5
    // overload of () assign reference to 1.5
    a(2,2) = 1.5;
    // print out one element in the matrix
    cout << "\n" << a << endl;
    // change one element in a(2,1) using operator [] ==> a[2][1] equal 2.5
    // Overload of []
    a[2][1] = 2.5;
    a[2][2] = a[2][1];
    cout << "\n" << a << endl;

    // Create b matrix and add it to a and save result inn matrix c
    Matrix b(4, 3, 1.0);
    Matrix c = a + b;
    cout << "\n" << c << '\n';


    cout << "\n";
    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    return 0;
}
