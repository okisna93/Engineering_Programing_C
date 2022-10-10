#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <string>

using namespace std;

const double G=6.674*pow(10,-11);
const double pi= 3.14159265358979323846;

struct Vec3d{
    double x,y,z;
};
ostream& operator<<(ostream& ostr, Vec3d a){
    ostr<<a.x<<","<<a.y<<","<< a.z;
    return ostr;
}
class Body{
private:
    string name;
    string orbit;
    double mass;
    Vec3d pos;
    Vec3d v;
    Vec3d a;

public:

    Body(){
        name="none";
        orbit="none";
        mass=0;

        pos={0,0,0};
        v={0,0,0};
        a={0,0,0};
    }

    Body(string na,string orb, double m, Vec3d po, Vec3d ve, Vec3d ac){
        name=na;
        orbit=orb;
        mass=m;

        pos={po.x,po.y,po.z};
        v={ve.x,ve.y,ve.z};
        a={ac.x,ac.y,ac.z};
    }

    friend ostream& operator<<(ostream& ostr, Body k);

   static auto setAccelerations(vector<Body>& b, int& acc){
        static vector<Body> newBodies;

    // this just give the acceleration value
        for(int i=0;i<b.size();i++){
            Vec3d acVect={b[i].a.x*acc,b[i].a.y*acc,0};
            b[i].a=acVect;
            newBodies.push_back(b[i]);
        }
        return newBodies;
   }

    friend class SolarSystem;

};

ostream& operator<<(ostream& ostr, Body k){
    ostr<<k.name<<" "<<k.orbit<<" "<<k.mass<<" "<<k.pos<<" "<<k.v<<" "<<k.a<<endl;;
    return ostr;
}

class SolarSystem{
public:
    vector<Body> bodies;
    friend ostream& operator<<(ostream& ostr, SolarSystem a);

    //string data_location;

    // open ifstream file+
    SolarSystem(string location){
        ifstream solarfile;
        solarfile.open(location);

        if (solarfile.is_open()){

            cout << "File is open and ready" << '\n';
            cout << " " << '\n';
    //            return; // use this for program testing to check file is open only without reading the data
        }else{
            cout << "File not found!" << '\n';
            cout << " " << '\n';
            cout << " " << '\n';
        }

        string line;
        string name;
        string orbit;
        double mass;
        double diam;
        double peri;
        double aplehon;
        double orbPeriod;
        double rotPeriod;
        double axile;
        double orbinling;
        double sun_mass;
        double radius;
        double velocity;
        double acceleration;
        int i=0;

        while (!solarfile.eof()){
            if(i<10){
                // Skipping the first line because it shows headers and we are not going to use in our calculations
                solarfile>>line;
                //cout<<sun_mass;
                i++;
            }else{
                //Assigning an object name to each variable in the file
                solarfile>>name>>orbit>>mass>>diam>>peri>>aplehon>>orbPeriod>>rotPeriod>>axile>>orbinling;
                //cout<<name<<" "<<orbit<<" "<<mass<<" "<<diam<<" "<<peri<<" "<<aplehon<<" "<<orbPeriod<<" "<<rotPeriod<<" "<<axile<<" "<<orbinling<<endl<<endl;
                i++;
                if (name=="Sun"){
                //Save sun mass to a object that we can use in our calculation
                    sun_mass=mass;
                }
                if(orbit=="Sun"){

                    //cout<<name<<endl;
                    //Calculation of the orbit radius and velocity for each planet
                    radius=(peri+aplehon)/2;
                    velocity=sqrt((G*sun_mass)/radius);

                    // Postion Vector
                    double random1=(rand()%10+1);
                    double random2=(rand()%10+1);
                    double random3=(rand()%10+1);
                    Vec3d posVect={random1,random2,random3};
                    //Vec3d posVect={rand()%10+1,rand()%10+1,rand()%10+1};
                    //cout<<"Postion Vector ="<<posVect<<endl;

                    //Calculation of Velocity Vector
                    random_device rd;  // Will be used to obtain a seed for the random number engine
                    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
                    uniform_real_distribution<double> dis(0, 2.0*pi);
                    double x_velc=radius*cos(dis(gen));
                    double y_velc=radius*sin(dis(gen));
                    Vec3d vVect={velocity*x_velc,velocity*y_velc,0};
                    //cout<<"Velocity Vector = "<<vVect<<endl;

                    //Calculation of Acceleration Vector
                    acceleration=pow(velocity,2)/radius;
                    Vec3d acVect={acceleration*x_velc,acceleration*y_velc,0};
                    //cout<<"Acceleration Vector = "<<acVect<<endl;

                    cout<<"body name: "<<name<<" "<<"orbit: "<<orbit<<endl;
                    cout<<"orbiral velocity is: "<<velocity<<endl;
                    cout<<"centripetal acceleration: "<<acceleration<<endl<<endl;

                    //Creating Body type temp object the store needed information
                    Body temp;
                    temp={name,orbit,mass,posVect,vVect,acVect};
                    //cout<<"BodyVect = "<<temp<<endl<<endl;

                    bodies.push_back(temp);

                    //cout<<name<<" "<<radius<<" "<<velocity<<endl<<endl;
                }

                if(name=="Jupiter"){
                    break;
                }
            }
        }
        solarfile.close();
    }
    void stepForward(int acc){
        Body::setAccelerations(bodies,acc);
    }

};

ostream& operator<<(std::ostream& ostr, SolarSystem s){
    for (int i=0;i<s.bodies.size();i++){
        ostr << s.bodies[i] << "  ";

    }
    return ostr;
}



int main(){
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // SolarSystem s should read the file to print and do calculation
    // when you creat object Solarsystem s('.dat path') it read the file and print only planets orbiting the sun  as shown below
    //    body name:Jupiter orbit: Sun
    //    orbital velocity is: 13058
    //    centripetal acceleration: 0.000219013
    //    body name:Saturn orbit: Sun
    //    orbital velocity is: 9623.1
    //    centripetal acceleration: 6.45977e-05
    //    ==================
    // Write your fullpath here to location where solarsystem.dat exist.
    SolarSystem s("C:/Users/okanc/Documents/Engineering_Programing_C/HW5/five-okisna93-main/src/solarsystem.dat");


    cout << s;
    // After reading the file print calculation done on Solarsystem
    // overload << operator in SolarSystem class to print out variables as follows
    //    Mercury, Sun, 3.3e+23, 8, 10, 4, -2147483648, -2147483648, 0, -1981977299, 1152671425, 0
    //    Venus, Sun, 4.87e+24, 9, 1, 3, -2147483648, -2147483648, 0, 1021382959, -679782887, 0


    cout << "=============" << endl;

    // add acceleration equal 100
    // Use function .stepForward() on object Solarsystem to set the new acceleration
    int acc = 5000;
    s.stepForward(acc);
    // print out the new solarsystem
    cout << s;

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;



    return 0;
}
