#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;


int main(){

    fstream deneme;
    deneme.open("Deneme.txt");
//    deneme<<"Okan"<<endl;
//    deneme<<"Celik"<<endl;
//    deneme<<"Software Engineer"<<endl<<endl;
//
//    deneme<<"Enes"<<endl;
//    deneme<<"Osman"<<endl;
//    deneme<<"Cook"<<endl;
//    string line;
//    string deleteline="Enes";
//    while (getline(deneme,line))
//    {
//        line.replace(line.find(deleteline),deleteline.length(),"");
//    }
    deneme.close();
    rename("deneme.txt","ASDASFAS.txt");






    //remove("Deneme.txt");



    return 0;
}
