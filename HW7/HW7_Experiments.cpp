#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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
        /*
        fstream drawfile;
        drawfile.open(location);
        if (drawfile.is_open()){

            cout << "File is open and ready" << '\n';
            cout << " " << '\n';
    //            return; // use this for program testing to check file is open only without reading the data
        }else{
            cout << "File not found!" << '\n';
            cout << " " << '\n';
        }
        cout<<"File is Closed"<<endl;
        drawfile.close();
        */
    }
    ~Shape(){
    }
};

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

        /*
        fstream drawfile;
        drawfile.open(location);
        if (drawfile.is_open()){

            cout << "File is open and ready" << '\n';
            cout << " " << '\n';
    //            return; // use this for program testing to check file is open only without reading the data
        }else{
            cout << "File not found!" << '\n';
            cout << " " << '\n';
        }
        drawfile<<x<<" "<<y<<" "<<radius<<" 0  360  arc \n";
        drawfile<<"stroke \n";

        drawfile.close();
        */
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
        /*
        fstream drawfile;
        drawfile.open(location);
        if (drawfile.is_open()){

            cout << "File is open and ready" << '\n';
            cout << " " << '\n';
    //            return; // use this for program testing to check file is open only without reading the data
        }else{
            cout << "File not found!" << '\n';
            cout << " " << '\n';
        }
        drawfile<<x<<" "<<y<<" moveto \n";
        drawfile<<x+width<<" "<<y<<" lineto \n";
        drawfile<<x+width<<" "<<y+height<<" lineto \n";
        drawfile<<x<<" "<<y+height<<" lineto \n";
        drawfile<<"closepath \n";
        drawfile<<"stroke \n";

        drawfile.close();
        */
    }
    double area(){
        double a;
        a=width*height;
        return a;
    }
    ~Rect(){
    }
};

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
        /*
        fstream drawfile;
        drawfile.open(location);
        if (drawfile.is_open()){

            cout << "File is open and ready" << '\n';
            cout << " " << '\n';
    //            return; // use this for program testing to check file is open only without reading the data
        }else{
            cout << "File not found!" << '\n';
            cout << " " << '\n';
        }
        drawfile<<x<<" "<<y<<" moveto \n";
        drawfile<<x+width<<" "<<y<<" lineto \n";
        drawfile<<x+width<<" "<<y+height<<" lineto \n";
        drawfile<<x<<" "<<y+height<<" lineto \n";
        drawfile<<"closepath \n";
        drawfile<<"fill \n";

        drawfile.close();
        */
    }
    double area(){
        return width*height;
    }
    ~FilledRect(){
    }
};

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
    Drawing d("test3.ps");
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
