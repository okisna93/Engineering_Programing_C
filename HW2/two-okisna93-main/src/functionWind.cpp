#include <iostream>
#include <fstream>
#include <cmath>
#include "functionWind.h"


using namespace std;



double windChillFactor (const double &v, const double &t)
{
    // Write your code here
    // define wind chill w
    // write your equation and return w double only
    double w;
    w = 35.74 + 0.6215*t-35.75*(pow(v,0.16)) + 0.4275*t*(pow(v,0.16));
    return w;
}