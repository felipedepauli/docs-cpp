#pragma once
#include <iostream>
class Shape {
    public:
        Shape();
        ~Shape();
        virtual int getArea() = 0;
        void setWidth(int w);
        void setHeight(int h);
    protected:
        int width;
        int height;
};

class Rectangle : public Shape {
    public:
        Rectangle();
        ~Rectangle();
        int getArea();
};

class Triangle : public Shape {
    public:
        Triangle();
        ~Triangle();
        int getArea();
};
