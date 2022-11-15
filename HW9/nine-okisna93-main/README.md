[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9307338&assignment_repo_type=AssignmentRepo)
## Ismet Okan Celik - 2 points Please edit your name here.

# Assignment 9


# Problem/Question:
- Problem:
  - Design Matrix class with private variable and member function:
    - Variables number of rows, number of columns, type_double pointer to pointer m for the matrix (** m), you can use m[i_idx][j_idx]
    - You can use int or uint_32_t (unsigned) for number of rows and columns
  - Private member function:
    - This function set up the Matrix and create dynamic array pointer in row and each row point array of columns
      - Matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols), m(new double*[rows]){
        //Write your code here\
        //loop each pointer rows[idx] and for each row create array of size columns\
        }
  - make the following functions
    - Constructor that take #of rows and #of columns and initial value for all elements
    - Copy constructor
    - Assign operator = for copy constructor
      - use swap(new_matrix, original_matrix)
    - Deconstruct  ~Matrix: loop inside each pointer and delete it
    - Move constructor
    - Overload () operator twice:
      - first: return_type is double and member function is const
      - second: return_type is reference double and member function is not const
    - overload [] operator
      - return_type double pointer
    - Overload << operator to print out matrix similar to
    - Read main.cpp comments for more details and how overload operatro are used in main()

## TO-DO:
- clone your repo to your local computer
  - ''' <b>git clone repo_https_url</b> '''
  - repo https url is found under code tab in your github
- Edit your name on top on README.md file.
- Edit the main function (file name: main.cpp):
  - Write your classes in main.cpp
- Push your answers
  - use git in your terminal to add files, and add comments on your commits, and finally submit files
    - ''' <b>git add specific_file1.x specific_file2.x</b> '''
    - ''' <b>git commit -m "add message here for commits"</b> '''
    - ''' <b>git push</b> ''' 
      
