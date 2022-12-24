[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9400245&assignment_repo_type=AssignmentRepo)
## Ismet Okan Celik - 2 points Please edit your name here.
# Assignment 10


# Problem/Question:
- Problem:
  - Design Merge class that merge overlapped intervals
  - Use template class with Merge class ,i.e., Merge<datatype> objectNName; 
  - No private/public variable or data member
  - No need for constructor
  - Write the following functions:
    - merge function that take vector of vector
      - write code that solve the problem of merging intervals that overlap
      - implement exception handling for given (vector of vector) that have less than two intervals, e.g., [(1,2)] this is not accepted as input. because it has only one interval
        - use error handling: try, throw, and catch
    - print function that print out intervals 
    - example of merging the following intervals: [(2,5),(1,4),(3,9),(20, 29),(7,16), (15, 27)]; 
  
  
  
```
    1   2   3   4   5   6   7   8   9   10  ...  15  16  17  18 ... 20 ... 27   28  29
        *-----------*
    *-----------*
            *-----------------------*
                                                                     *----------------*
                             *-----------------------*
                                                   *------------------------*
    The merge result wil be interval from (1, 29)
    *---------------------------------------------------------------------------------*
 ```
  

 - Hint: 
   - You will need to sort the input first then look for overlapping intervals
   - you may use sort function built in vector class.
   
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
      
