#include <iostream>
#include <ctime>
using namespace std;
class JulianDate{
public:
    int year,month,day,hour,mins,sec;

public:
    JulianDate(){
        time_t now=time(0);
        tm*date=localtime(&now);

        const int base_year=1900;
        year=date->tm_year+base_year;
        month=date->tm_mon+1;
        day=date->tm_mday;
        hour=date->tm_hour;
        mins=date->tm_min;
        sec=date->tm_sec;
    }

    JulianDate(int y, int m, int d, int h, int mi,int s){

        year=y;
        month=m;
        day=d;
        hour=h;
        mins=mi;
        sec=s;
    }

    int calc_juliandate(){

        int a=(14-month)/12;
        int m=month+12*a-3;
        int y=year+4800-a;
        int nDate=day+((153*m+2)/5)+365*y+(y/4)-(y/100)+(y/400)-32045;

        return nDate;
    }

/*
    double diff_calc_juliandate(JulianDate j1, JulianDate j2){

        double diff=j1-j2;
        return diff;

    }
*/

    double diff_calc_juliandate(JulianDate j1, JulianDate j2){
        double calc1=j1.calc_juliandate();
        double calc2=j2.calc_juliandate();
        double sub=calc1-calc2;
        return sub;
    }
};

int main(){

    //Default todays date
    cout.precision(20);
    JulianDate a;
    cout<<a.year<<endl;

    // Non-Default date
    JulianDate b(2000,2,8,0,0,0);
    cout<<b.year<<endl;

    // calculating julian date from default date
    double j1=a.calc_juliandate();
    cout<<j1<<endl;

    // calculating julian date from given date
    double j2=b.calc_juliandate();
    cout<<j2<<endl;

     // Manuel difference between Juliandates j1 and j2
    double diff=j1-j2;
    cout<<diff<<endl;

    JulianDate z;
    double funcdiff=z.diff_calc_juliandate(a,b);
    cout<<"Diff = "<<funcdiff<<endl;


    JulianDate p(1776,7,4,0,0,0);
    double j5=p.calc_juliandate();
    cout<<j5<<endl;

    JulianDate l(2000,12,31,0,0,0);
    double j6=l.calc_juliandate();
    cout<<j6<<endl;

    JulianDate o(2007,2,8,0,0,0);
    double j7=o.calc_juliandate();
    cout<<j7<<endl;

    JulianDate r(2007,2,9,0,0,0);
    double j8=r.calc_juliandate();
    cout<<j8<<endl;

    JulianDate u(2018,1,1,1,0,0);
    double j9=u.calc_juliandate();
    cout<<j9<<endl;



    return 0;
}
