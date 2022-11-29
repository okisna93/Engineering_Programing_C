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


void DatePlusDays( struct tm* date, int days )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime( &date_seconds ) ;
}
string Deadline(int days){
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);

    // initializing the local date
    struct tm date = { 0, 0, 12 } ;
    int year = now->tm_year + 1900 ;
    int month = now->tm_mon + 1 ;
    int day = now->tm_mday ;

    // Set up the date structure
    date.tm_year = year - 1900 ;
    date.tm_mon = month - 1 ;  // note: zero indexed
    date.tm_mday = day ;       // note: not zero indexed

    // Adding days to current date
    DatePlusDays( &date, +days ) ;

    //string d=asctime(&date);

    // Show time/date using default formatting
    char *deadline;
    deadline=new char[14];//Memory allocation for deadline date
    string d; // Loop through asctime(&date) to changing display format, get rid of from hours and only showing day,month,year
    int k=0;
    //for(int i=0;i<strlen(asctime(&date));i++){
    for(int i=0;i<strlen(asctime(&date));i++){
        if(i>=0 && i<=9){
            deadline[k]=asctime(&date)[i];
            d.push_back(deadline[k]);
        }
        if(i>=19 && i<=23){
            deadline[k]=asctime(&date)[i];
            d.push_back(deadline[k]);
        }
        else{
           continue;
        }
    }
    delete []deadline; //releasing the memory
    return d ;//returning to string date format is: Fri Dec 16 2022
}

int main(){

    string a="Merhaba";
    cout<<a<<endl;
    cout<<a.size()<<endl;
    cout<<Deadline(30)<<"asdasdasf"<<endl;


    return 0;
}
