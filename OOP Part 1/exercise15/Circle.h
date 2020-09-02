#pragma once
class Circle
{
protected:
    double radius;
public:
    Circle();
    void set_radius(double radius);
    double get_radius();
    double diameter();
    double perimeter();
    double area();
    void display();
};

