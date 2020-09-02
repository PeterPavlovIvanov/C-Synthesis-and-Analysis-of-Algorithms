#include <iostream>
#include <map>
#include <string>
#include "Circle.h"
#include "Sphere.h"
using namespace std;

int main() {
    Circle c1,c2;
    c1.display();

    c2.set_radius(5.2f);
    c2.display();

    Sphere s1;
    s1.set_radius(5.2f);
    s1.show();

    return 0;
}
