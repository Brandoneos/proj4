
/*
Author: BRANDON KIM
DATE: 3/28/2023
Course: CS 251

Description: This file(shape.h) includes the Shape class 
and subclasses with different functions to go along with each class.

*/

#pragma once

#include <iostream>
using namespace std;

class Shape
{
    protected:
        int x;
        int y;
        string shapeName;
    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual void printShape() const;
};


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int);
        
        virtual void printShape() const;
};


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int x, int y, int w, int h);
        
        virtual ~Rectangle();
        virtual Rectangle* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual void printShape() const;
};

class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual void printShape() const;
};
//Milestone 1: 
//Default constructor for Shape
Shape::Shape() {
    this->x = 0;
    this->y = 0;
    shapeName = "Shape";
}
//Parameterized constructor for Shape
Shape::Shape(int x, int y){
    this->x = x;
    this->y = y;
    shapeName = "Shape";
}
//Destructor for Shape
Shape::~Shape() {
    //Empty
}
//Copy function for Shape, no parameters but returns Shape* which is the copy
Shape* Shape::copy() {
    Shape* shape1 = new Shape(x,y);//create new shape
    return shape1;
}
//getX() function for Shape, no parameters but returns an integer value which is the x coordinate of the shape
int Shape::getX() const {
    return x;
}
//getY() function for Shape, no parameters but returns an integer value which is the y coordinate of the shape
int Shape::getY() const {
    return y;
}
//setX() function for Shape, takes in an integer x as the parameter and sets the private x coordinate to this value;
void Shape::setX(int x) {
    this->x = x;
}
//setY() function for Shape, takes in an integer y as the parameter and sets the private y coordinate to this value;
void Shape::setY(int y) {
    this->y = y;
}
//printShape() function for Shape, no parameters but prints out the description of the shape with coordinates.
void Shape::printShape() const {
    cout << "It's a " << shapeName << " at x: " << x << ", y: " << y << endl;
    //It's a Shape at x: 1, y: 3
}

//Milestone 3:
//Rectangle
//Default constructor for rectangle
Rectangle::Rectangle() {
    this->x = 0;
    this->y = 0;
    shapeName = "Rectangle";
    width = 0;
    height = 0;
}
//Parameterized constructor for rectangle, takes in a width and height which is set
// to the respective private variables when constructed
Rectangle::Rectangle(int w, int h) {
    this->x = 0;
    this->y = 0;
    shapeName = "Rectangle";
    width = w;
    height = h;
}
//Parameterized constructor for rectangle, takes in a width, height, x, and y coordinates which is set
// to the respective private variables when constructed
Rectangle::Rectangle(int x, int y, int w, int h){
    this->x = x;
    this->y = y;
    shapeName = "Rectangle";
    width = w;
    height = h;
}
//Destructor for Rectangle
Rectangle::~Rectangle() {

}
//copy() function for Rectangle, no parameters but returns a Rectangle* which is a new object with the same values
Rectangle* Rectangle::copy() {
    Rectangle* r1 = new Rectangle(x,y,width,height);
    return r1;
}
//getWidth() function for Rectangle, no parameters but returns an integer value which is the Rectangle's width
int Rectangle::getWidth() const {
    return width;
}
//getHeight() function for Rectangle, no parameters but returns an integer value which is the Rectangle's height
int Rectangle::getHeight() const {
    return height;
}
//setWidth() function for Rectangle, takes in int w as a parameter, which sets the private width variable to this w value
void Rectangle::setWidth(int w) {
    width = w;
}
//setHeight() function for Rectangle, takes in int h as a parameter, which sets the private height variable to this w value
void Rectangle::setHeight(int h) {
    height = h;
}
//printShape() function for Rectangle, no parameters but prints out the description of the Rectangle with coordinates, width, and height
void Rectangle::printShape() const {
    cout << "It's a " << shapeName << " at x: " << x << ", y: " << y << " with width: " << width << " and height: " << height << endl;
}

//Milestone 4:
//Circle
//Default constructor for circle

Circle::Circle() {
    this->x = 0;
    this->y = 0;
    shapeName = "Circle";
    this->radius = 0;
}
//Parameterized constructor for Circle, takes in an integer value r which the private var radius is set to.
Circle::Circle(int r) {
    this->x = 0;
    this->y = 0;
    shapeName = "Circle";
    this->radius = r;
}
//Parameterized constructor for Circle, takes in coordinates x,y and radius r, which the respective private vars are set to.
Circle::Circle(int x, int y, int r) {
    this->x = x;
    this->y = y;
    shapeName = "Circle";
    this->radius = r;
}
//Destructor for Circle
Circle::~Circle() {

}
// copy() function for Circle, no parameters but returns a Circle*, which is a new object with the same values.
Circle* Circle::copy() {
    Circle* c1 = new Circle(x,y,radius);
    return c1;
}
//getRadius() function for Circle, no parameters but returns the value of the private var radius
int Circle::getRadius() const {
    return radius;
}
//setRadius() function for Circle, takes in int r value and sets the radius to r.
void Circle::setRadius(int r) {
    radius = r;
}
//printShape() function for Circle, no parameters but prints out the description of the Circle.
void Circle::printShape() const {
    cout << "It's a " << shapeName << " at x: " << x << ", y: " << y << ", radius: " << radius << endl;
}
//Milestone 5:
//Right Triangle Class
//Default constructor for RightTriangle
RightTriangle::RightTriangle() {
    this->x = 0;
    this->y = 0;
    shapeName = "Right Triangle";
    this->base = 0;
    this->height = 0;
}
//Parameterized constructor for RightTriangle, takes in the base and height and sets the values accordingly.
RightTriangle::RightTriangle(int b, int h) {
    this->x = 0;
    this->y = 0;
    shapeName = "Right Triangle";
    this->base = b;
    this->height = h;
}
//Parameterized constructor for RightTriangle, takes in the base and height and coordinates and sets the values accordingly.
RightTriangle::RightTriangle(int x, int y, int b, int h) {
    this->x = x;
    this->y = y;
    shapeName = "Right Triangle";
    this->base = b;
    this->height = h;
}
//Destructor for RightTriangle
RightTriangle::~RightTriangle() {

}
//copy() function for RightTriangle, no parameters but returns a RightTriangle* which is a new object with the same values
RightTriangle* RightTriangle::copy() {
    RightTriangle* r1 = new RightTriangle(x,y,base,height);
    return r1;
}
//getBase() function for RightTriangle, no parameters but returns the integer value for the private var base
int RightTriangle::getBase() const {
    return base;
}
//getHeight() function for RightTriangle, no parameters but returns the integer value for the private var height
int RightTriangle::getHeight() const {
    return height;
}
//setBase() function for RightTriangle, takes in int b value and sets the base to this value
void RightTriangle::setBase(int b) {
    base = b;
}
//setHeight() function for RightTriangle, takes in int h value and sets the height to this value
void RightTriangle::setHeight(int h) {
    height = h;
}
//printShape() function for RightTriangle, no parameters but prints out the description 
// of the Right Triangle with coordinates, width, and height.
void RightTriangle::printShape() const {
    cout << "It's a " << shapeName << " at x: " << x << ", y: " << y << " with base: " << base << " and height: " << height << endl;
}






