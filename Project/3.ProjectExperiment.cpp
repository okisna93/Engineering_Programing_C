#include <ctime>
#include <iostream>
#include <cstring>
#include <string>
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
void Deadline(int days){
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
    // initialize
    struct tm date = { 0, 0, 12 } ;  // nominal time midday (arbitrary).
    int year = now->tm_year + 1900 ;
    int month = now->tm_mon + 1 ;  // February
    int day = now->tm_mday ;   // 26th

    // Set up the date structure
    date.tm_year = year - 1900 ;
    date.tm_mon = month - 1 ;  // note: zero indexed
    date.tm_mday = day ;       // note: not zero indexed

    // Date, less 100 days
    DatePlusDays( &date, +days ) ;

    // Show time/date using default formatting
    cout << asctime(&date)  << endl ;
    cout << strlen(asctime(&date))  << endl ;
    char *deadline;
    deadline=new char[15];
    string d;
    int k=0;
    for(int i=0;i<strlen(asctime(&date));i++){
        if(i>=11 && i<=19){
        }
        else{
           deadline[k]=asctime(&date)[i];
           d.push_back(deadline[k]);
        }
    }
    delete []deadline;
    cout<<d;
}

int main()
{
    Deadline(30);
}
