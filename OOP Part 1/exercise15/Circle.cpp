#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Circle.h"

    Circle::Circle() {
        radius = 0.0f;
    };
    void Circle::set_radius(double radius) {
        this->radius = radius;
    };
    double Circle::get_radius() {
        return radius;
    };
    double Circle::diameter() {
        return radius * 2;
    };
    double Circle::perimeter() {
        return 2 * M_PI * radius;
    };
    double Circle::area() {
        return 3.141593 * radius * radius;
    };
    void Circle::display() {
        std::cout << "Circle: " << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Diameter: " << diameter() << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
        std::cout << "Area: " << area() << std::endl << std::endl;
    };
