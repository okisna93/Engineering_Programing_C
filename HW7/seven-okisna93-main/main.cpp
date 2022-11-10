#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// -------------- Design your Shape class here ---------------
// -----------------------------------------------------------
// Shape abstract class with private double variable x and y that indicate shape position
// make the following functions
//  1. Constructor shape (x, y)
//  2. function area take no parameters return double const  equal zero
//  3. function draw take ostream file return void  equal zero
//  4. make deconstruct ~Shape


class Shape{
private:
    double x;
    double y;
public:
    Shape(double a, double b){
        x=a;
        y=b;
    }
    virtual double area(){
        const double a=0;
        return a;
    }
    virtual void draw(ostream &o){
    }
    ~Shape(){
    }
};

// -------------- Design your Circle class here ---------------
// -----------------------------------------------------------
// Class Circle inherit Class Shape
// private variable x, y, radius
// Make the following functions:
// Circle constructor that take x, y, radius, Note that x and y are assigned to Shape(x,y)
//  for example constructor_name(double x, double y) : Shape(x,y)
// draw that take ostream file to write postscript instruction the function return void
//   postscript:
//    x y radius  0  360  arc \n
//    stroke \n
// for example for x = 200 pixels, y = 3 pixels, and radius 100 pixels. then your function should write this in test.ps
// stroke
// 200 300 100 0 360 arc
// area take no parameters and return double
// ~Circle deconstruction


class Circle:public Shape{
private:
    double x;
    double y;
    double radius;
public:
    Circle(double a, double b, double r): Shape(a,b){
        x=a;
        y=b;
        radius=r;
    }
    void draw(ostream& o){
        o<<x<<" "<<y<<" "<<radius<<" 0  360  arc \n";
        o<<"stroke \n";
    }
    double area(){
        double a;
        double pi=3.14;
        a=pi*radius*radius;
        return a;
    }
    ~Circle(){
    }
};


// -------------- Design your Rect class here ---------------
// -----------------------------------------------------------
// Class Rect inherit Class Shape
// private variable x, y, width, and height
// Make the following functions:
// Rect constructor that take x, y,  width,  height
// draw that take ostream file to write postscript instruction the function return void
// draw that take ostream file to write postscript instruction the function return void
//   postscript:
//    x y moveto \n
//    x+w y lineto \n
//    x+w y+h lineto \n
//    x y+h lineto \n
//    closepath \n
//    stroke \n
// area take no parameters and return double
// ~Rect deconstruction


class Rect:public Shape{
private:
    double x;
    double y;
    double width;
    double height;
public:
    Rect(double a, double b, double w, double h):Shape(a,b){
        x=a;
        y=b;
        width=w;
        height=h;
    }
    void draw(ostream& o){
        o<<x<<" "<<y<<" moveto \n";
        o<<x+width<<" "<<y<<" lineto \n";
        o<<x+width<<" "<<y+height<<" lineto \n";
        o<<x<<" "<<y+height<<" lineto \n";
        o<<"closepath \n";
        o<<"stroke \n";
    }
    double area(){
        double a;
        a=width*height;
        return a;
    }
    ~Rect(){
    }
};

// -------------- Design your FilledRect class here ---------------
// -----------------------------------------------------------
// Class FilledRect inherit Class Shape
// private variable x, y, width, and height
// Make the following functions:
// FilledRect constructor that take x, y,  width,  height
// draw that take ostream file to write postscript instruction the function return void
//   postscript:
//    x y moveto \n
//    x+w y lineto \n
//    x+w y+h lineto \n
//    x y+h lineto \n
//    closepath \n
//    fill \n
// area take no parameters and return double
// ~FilledRect deconstruction


class FilledRect:public Shape{
private:
    double x;
    double y;
    double width;
    double height;

public:
    FilledRect(double a, double b, double w, double h):Shape(a,b){
        x=a;
        y=b;
        width=w;
        height=h;
    }
    void draw(ostream& o){
        o<<x<<" "<<y<<" moveto \n";
        o<<x+width<<" "<<y<<" lineto \n";
        o<<x+width<<" "<<y+height<<" lineto \n";
        o<<x<<" "<<y+height<<" lineto \n";
        o<<"closepath \n";
        o<<"fill \n";
    }
    double area(){
        return width*height;
    }
    ~FilledRect(){
    }
};


// -------------- Design your Drawing class here ---------------
// -----------------------------------------------------------
// private variables ofstream and vector<shape*>
// Make the following functions:
// Drawing constructor as following (is given):
//  Drawing(string filename) : f(filename.c_str()), shapes() {} // where f is ofstream
// void add that take shape and push_back to vector
// void draw take no parameters and loop inside vector to rum draw function for each shape class
// void showArea take no parameters and loop inside vector to run area function for each shape class
// void setrgb take three double for red, green, and blue and write postscript line to change color
//   postscript:
//    r_value g_value b_value setrgbcolor \n

class Drawing{
private:
    ofstream f;
    vector<Shape*> shapes;
public:
    Drawing(string filename):f(filename.c_str()),shapes(){
    }
    void add(Shape* a){
        shapes.push_back(a);
    }

    void draw(){
        if (f.is_open()){

            cout << "File is open and ready" << '\n';
            cout << " " << '\n';
            //            return; // use this for program testing to check file is open only without reading the data
        }else{
            cout << "File not found!" << '\n';
            cout << " " << '\n';
        }

        for(int i=0;i<shapes.size();i++){
            shapes[i]->draw(f);
        }

        f.close();
    }

    void showArea(){
        for(int i=0;i<shapes.size();i++){
            cout<<shapes[i]->area()<<endl;
        }
    }
    void setrgb(double r, double g, double b){
        f<<r<<" "<<g<<" "<<b<<" "<<" setrgbcolor \n";
    }

    ~Drawing() {
		for (auto a : shapes)
			delete a;
	}
};


int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // set path to create .ps file to write postscript instructions
    Drawing d("C:\\Users\\okanc\\Documents\\Engineering_Programing_C\\HW7\\seven-okisna93-main\\testSon.ps");
    // set color
    d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
    // add FilledRect
    d.add(new FilledRect(100.0, 550.0, 200.0, 50)); // x y moveto x y lineto ... fill
    // add Rect
    d.add(new Rect(200.0, 650.0, 200.0, 50));       // x y moveto x y lineto ... stroke
    // add Circle
    d.add(new Circle(300,300, 100)); // centered in 300 , 300 pixel with radius
    // draw all shapes added to d
    d.draw();
    // print out all shapes area
    d.showArea();

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;


    return 0;
}