#include <iostream>
#include <cstring>

using namespace std;

// -------------- Design your String class here ---------------
// -----------------------------------------------------------
// String class with private integer variable length of string and pointer to character str
// make the following functions
//  1. default constructor String (length, str) with length = zero and str pointer to nullptr
//  2. non-default constructor that take string length and character pointer
//     Use strlen() function to find the char length
//     Creat new dynamic array str with the new length
//     You will have to loop to assign each character
//  2. make deconstruct ~String that delete char pointer
//  3. Overload << operator to print out string.
//  4. Copy constructor String
//  5. Move constructor String
//  6. Assign operator = for copy constructor
//  7. Overload + operator to add/combine to String cat + dog => catdog


class String{
private:
    int length;
    char *str;
public:
    String(){
        length=0;
        str=nullptr;
    }

    String(const char *p){
        length=strlen(p);
        str=new char[length];
        for(int i=0;i<length;i++){
            str[i]=p[i];
        }
    }
    ~String(){
        delete[] str;
    }
    friend ostream& operator<<(ostream& ostr,const String& a);

    String(const String& obj){
        length=obj.length;
        str=new char[length];
        for(int i=0;i<length;i++){
            str[i]=obj.str[i];
        }
    }

    String(String && obj){
        str=obj.str;
        obj.str=nullptr;
    }

    String& operator=(const String& obj){
        length = obj.length;
        this->str=new char[length];
        for(auto i=0;i<length;++i){
            this->str[i] = obj.str[i] ;
        }
        return *this;
    }

    String operator+(String& obj){
        String overload;
//        strcat(this->str,obj.str);
//        overload.length=strlen(this->str);
//        overload.str=new char(obj.length);
//        strcpy(overload.str,this->str);
        overload.length=length+obj.length;
        overload.str=new char[overload.length];
        for(int i=0;i<length;i++){
            overload.str[i]=this->str[i];
        }
        for(int a=0;a<obj.length;a++){
            overload.str[length+a]=obj.str[a];
        }
        return overload;
    }

};

ostream& operator<<(ostream& ostr,const String& a){
    ostr<<a.str;

    return ostr;
}

int main(){


    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // Create String s = abc
    String s = "abc";
    // cout s
    cout << "s is: " << s <<endl;
    // Create String s = def
    String s2 = "def";
    // cout s2
    cout  << "s2 is: " << s2 <<endl;
    // create String s3 equal s2
    String s3 = s2; // copy constructor
    // cout s3
    cout << "s3 is: " << s3 << " copy constructor "<<endl;
    //	Create String s4 that is assigned to s added to s2
    String s4 = s + s2;  // abcdef // copy constructor
    // cout s4
    cout << "s4 is: " << s4 << " copy constructor of s + s2"<<endl;
    // Create s5 and move s4
    String s5 = move(s4); // move constructor
    // cout s5
    cout << "s5 is: " << s5 <<endl;
    cout << "cout s4 should give you error after move()" << endl;
    cout << s4 << '\n';
    cout << "====[ end ]====" << endl;
    cout << "         " << endl;



    return 0;
}
