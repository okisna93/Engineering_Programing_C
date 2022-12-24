#include<iostream>
#include<string.h>
using namespace std;
//class String
//{
// char *str;
//public:
//     String(const char *s);
//     void change(int index, char c) { str[index] = c; }
//     char *get() { return str; }
//};
//String::String(const char *s)
//{
//     int l = strlen(s);
//     str = new char[l+1];
//     strcpy(str, s);
//}
//int main()
//{
//     String s1("stevensQuiz");
//     String s2 = s1;
//     s1.change(0, 'G');
//     cout << s1.get() << " ";
//     cout << s2.get();
//
//}
//
//#include<iostream>
//using namespace std;
//class Test {
// private:
//     int y;
//     int x;
// public:
//     //Test() : x(10), y(x + 10) {}
//     Test(){
//        x=10;
//        y=x+10;
//     }
//     void print();
//};
//void Test::print()
//{
//    cout<<"x = "<<x<<" y = "<<y;
//}
//int main()
//{
//     Test t;
//     t.print();
//     //getchar();
//     return 0;
//}



//#include <string>
//
//int main(){
//
//    string s1("Stevens");
//    cout<<s1<<endl;
//
//    return 0;
//}



template <typename T>
void fun(const T&x)
{
 static int count = 0;
     cout << "x = " << x << " count = " << count << endl;
     ++count;
     return;
}
int main()
{
     fun<int> (1);
     cout << endl;
     fun<int>(1);
     cout << endl;
     fun<double>(1.1);
     cout << endl;
     return 0;
}
