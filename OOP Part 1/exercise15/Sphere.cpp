#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Sphere.h"
double Sphere::volume() {
	return (4 / 3) * M_PI * radius * radius * radius;
};
	void Sphere::show() {
		std::cout << "Sphere: " << std::endl;
		std::cout << "Radius: " << radius << std::endl;
		std::cout << "Diameter: " << diameter() << std::endl;
		std::cout << "Perimeter: " << perimeter() << std::endl;
		std::cout << "Area: " << area() << std::endl;
		std::cout << "Volume: " << volume() << std::endl;
	};
