[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8941941&assignment_repo_type=AssignmentRepo)
## Ismet Okan Celik - 2 points Please edit your name here.

# Assignment 7


# Problem/Question:
- Problem:
  - Design an abstract class called Shape that you will use with Circle, Rect, and FilledRect class:
    - Private variables double x and y
    - Constructor shape (x, y) 
    - function area take no parameters return double const  equal zero
    - function draw take ostream file return void and equal zero
    - make deconstruct ~Shape
    - Hint: you need to use virtual
  - Design class Circle that inherit class shape functions
    - private variable x, y, radius 
    - Make the following functions:
      - Circle constructor that take x, y, radius, Note that x and y are assigned to Shape(x,y)
        - for example constructor_name(double x, double y) : Shape(x,y)
      - draw that take ostream file to write postscript instruction the function return void
      - area take no parameters and return double
      - ~Circle deconstruction
  - Design class Rect that inherit class shape with same functions as class Circle
    - private variables are x, y, weight, height
  - Design class FilledRect that inherit class shape with same functions as class Circle
    - private variables are x, y, weight, height
  - Hint for Circle, Rect, and FilledRect: you will need to use override keyword
    - e.g.: data_return_type function_name(inputs) <b>override</b> {}
  - Design class Drawing that take all shapes created and save it in vectors. Then use draw function for each Shape to write test.ps file with postscripts instructions
    - it has private variables of type: ofstream and vector<Shape> "Polymorphism"
    - Drawing constructor that take location to open "test.ps" file.
    - void add function that push_back new shapes to vector. It takes "Polymorphism" shape.
    - void draw function take no parameter that loop through all shapes and write postscript instruction for each shape.
    - void showArea take no parameters and loop inside vector to run area function for each shape class
    - void setrgb function take three double for red, green, and blue. It writes postscript to change the color for all shapes.
  
## Postscript language:
- [Check Wiki. for some background about Postscript](https://en.wikipedia.org/wiki/PostScript)
- [You can use online website to view .ps file](https://products.aspose.app/page/viewer/ps)
- Postscript line you need to use to draw shapes are given in the code.
- Your test.ps file should generate the following results

<img src="/resultsOfDraw.png" width="600" > </div>



## TO-DO:
  - clone your repo to your local computer
    - ''' <b>git clone repo_https_url</b> '''
    - repo https url is found under code tab in your github
  - Edit your name on top on README.md file.
  - Edit the main function (file name: main.cpp):
    - Write your classes in main.cpp
    - Your code should run fine with main() function and output test.ps file
  - Push your answers
    - use git in your terminal to add files, and add comments on your commits, and finally submit files
      - ''' <b>git add specific_file1.x specific_file2.x</b> '''
      - ''' <b>git commit -m "add message here for commits"</b> '''
      - ''' <b>git push</b> ''' 
      
