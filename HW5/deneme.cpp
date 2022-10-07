#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <string>


using namespace std;

class me {
  public:
     void X() { x = 1;}
     void Y() { y = 2;}

    static void Z() {
        int x = 5 ; y = 10;
    }

public:
  int x, y;
};

int main() {
  me M;

  M.X();
  M.Y();
  M.Z();

  return 0;
}


