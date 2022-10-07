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
    friend ostream& operator<<(ostream& ostr, Body k);
    friend class SolarSystem;


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


};
ostream& operator<<(ostream& ostr, Body k){
    ostr<<k.name<<" "<<k.orbit<<" "<<k.mass<<" "<<k.pos<<" "<<k.v<<" "<<k.a<<endl;;
    return ostr;
}

class SolarSystem{
public:
    vector<Body> bodies;
    friend ostream& operator<<(ostream& ostr, SolarSystem a);

    SolarSystem(){
        ifstream solarfile;
        solarfile.open("solarsystem.dat");

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

    /*

        while (getline (solarfile, line)){

            if (i==0){
                i++;
                continue;
            }else{
                cout << line << endl;
                i++;
            }
    */

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
                    radius=(peri*aplehon)/2;
                    velocity=sqrt((G*sun_mass)/radius);

                    // Postion Vector
                    Vec3d posVect={rand()%10+1,rand()%10+1,rand()%10+1};
                    //cout<<"Postion Vector ="<<posVect<<endl;

                    //Calculation of Velocity Vector
                    random_device rd;  // Will be used to obtain a seed for the random number engine
                    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
                    uniform_real_distribution<> dis(0, 2.0*pi);
                    double x_velc=radius*cos(dis(gen));
                    double y_velc=radius*sin(dis(gen));
                    Vec3d vVect={velocity*x_velc,velocity*y_velc,0};
                    //cout<<"Velocity Vector = "<<vVect<<endl;

                    //Calculation of Acceleration Vector
                    acceleration=pow(velocity,2)/radius;
                    Vec3d acVect={acceleration*x_velc,acceleration*y_velc,0};
                    //cout<<"Acceleration Vector = "<<acVect<<endl;

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

        // Displaying bodies vector in the solar system
        //for (Body& i : bodies) {
         //   cout << i << "  ";
       // }
    }
    void stepForward(int acc){
         //this just give the acceleration value
        //for(int i=0;i<bodies.size();i++){
            //cout<<bodies[i].name<<" "<<bodies[i].a.x<<endl;
            //cout<<bodies[i].name<<" "<<bodies[i].a.x*acc<<endl;
           // cout<<bodies[i].name<<" "<<bodies[i].a.y*acc<<endl<<endl;
           //bodies[i].a.x=bodies[i].a.x*acc;
        Body::setAccelerations(bodies,acc);
        //cout<<acc;
    }

};

ostream& operator<<(ostream& ostr, SolarSystem s){

    for (int i=0;i<s.bodies.size();i++){
         ostr << s.bodies[i] << "  ";
    }

}


int main(){

    SolarSystem a;
    cout<<"--------1--------"<<endl;
    cout<<a;

    cout<<"--------2--------"<<endl;
    a.stepForward(100);
    cout<<a;


    return 0;
}
