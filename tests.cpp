/*
Author: BRANDON KIM
DATE: 3/28/2023
Course: CS 251

Description: This file(tests.cpp) is used for testing the shape.h 
and canvaslist.h files and their functions.

*/


/// @filename tests.cpp
/// @date March 7, 2023

/// Provided testing file to implement
/// framework based tests in. The example
/// below uses the Catch testing framework
/// version that uses a single .hpp file.

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

// #include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"
#include <gtest/gtest.h>

#include <ostream>
#include <iostream>
using namespace std;
//Test to see if googletest works
TEST(FirstTest, ZeroZero) {
  
  EXPECT_EQ(0, 0);
}
//Makes sure default constructor works along with getters
TEST(ShapeClassTest,DefaultConstructor) {
  Shape* s1 = new Shape();
  EXPECT_EQ((*s1).getX(),0);
  EXPECT_EQ((*s1).getY(),0);
  
}
//Makes sure parameterized constructor works
TEST(ShapeClassTest,ParameterizedConstructor) {
  Shape* s2 = new Shape(1,3);
  EXPECT_EQ((*s2).getX(),1);
  EXPECT_EQ((*s2).getY(),3);
  
}
//Makes sure printShape() function works
TEST(ShapeClassTest,PrintShapeTest) {
  Shape* s3 = new Shape(2,6);
  testing::internal::CaptureStdout();
  (*s3).printShape();
  string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output,"It's a Shape at x: 2, y: 6\n");
}
//Makes sure setters and getters work
TEST(ShapeClassTest,SettersGetters) {
  Shape* s4 = new Shape();
  (*s4).setX(4);
  (*s4).setY(5);
  EXPECT_EQ((*s4).getX(),4);
  EXPECT_EQ((*s4).getY(),5);
}
//Tests for copy() function
TEST(ShapeClassTest,CopyFunctionTest) {
  Shape* s4 = new Shape();
  (*s4).setX(4);
  (*s4).setY(5);
  Shape* s4Copy = (*s4).copy();
  delete s4;
  EXPECT_EQ((*s4Copy).getX(),4);
  EXPECT_EQ((*s4Copy).getY(),5);
}
//Tests for canvaslist.h
//Tests for push_front() and size() and default constructor
TEST(CanvasListTest, PUSHFRONT_DRAW_TEST) {
  CanvasList myCanvas;
  EXPECT_EQ(myCanvas.size(),0);
	Shape *s = new Shape(1, 3);
	myCanvas.push_front(s);

  EXPECT_EQ(myCanvas.size(),1);
  myCanvas.push_front(s);
  myCanvas.push_front(s);
  myCanvas.push_front(s);
  EXPECT_EQ(myCanvas.size(),4);
}
//Tests for push_back() and clear()
TEST(CanvasListTest, PUSH_BACK_TEST) {
  CanvasList myCanvas;
	Shape *s = new Shape();
	myCanvas.push_back(s);

  EXPECT_EQ(myCanvas.size(),1);
  Shape *s1 = new Shape();
  Shape *s2 = new Shape();
  Shape *s3 = new Shape();
  myCanvas.push_back(s1);
  myCanvas.push_back(s2);
  myCanvas.push_back(s3);
  EXPECT_EQ(myCanvas.size(),4);
  myCanvas.clear();
  EXPECT_EQ(myCanvas.size(),0);
}
//Tests for copy constructor
TEST(CanvasListTest, COPY_CONSTRUCTOR_TEST) {
  CanvasList myCanvas;
	Shape *s = new Shape(1,4);
  CanvasList myCanvas1(myCanvas);
  EXPECT_EQ(myCanvas1.size(),0);
  EXPECT_EQ(myCanvas1.front(),nullptr);//testing empty canvaslist
	myCanvas.push_back(s);

  EXPECT_EQ(myCanvas.size(),1);

  CanvasList canvas2(myCanvas);
  EXPECT_EQ(canvas2.size(),1);
  EXPECT_EQ(canvas2.front()->value->getX(),1);
  canvas2.removeAt(0);
  EXPECT_EQ(canvas2.front(),nullptr);
  myCanvas.clear();
  canvas2.clear();
  EXPECT_EQ(myCanvas.size(),0);
  EXPECT_EQ(canvas2.size(),0);
}
//Tests for operator=() function
TEST(CanvasListTest, AOPERATOR_TEST) {
  CanvasList myCanvas;
	Shape *s = new Shape();
	myCanvas.push_back(s);
  CanvasList myCanvas2;
  myCanvas2 = myCanvas;
  EXPECT_EQ(myCanvas2.size(),1);
  myCanvas.clear();
  EXPECT_EQ(myCanvas2.size(),1);
}
//Tests for insertAfter() function
TEST(CanvasListTest, insertAfterTest) {
  CanvasList myCanvas;
	Shape *s = new Shape(1,2);
  myCanvas.push_back(s);
  Shape *s1 = new Shape(2,3);
  myCanvas.insertAfter(0,s1);
  EXPECT_EQ(myCanvas.size(),2);
  myCanvas.clear();
  Shape *s2 = new Shape(3,4);
  myCanvas.push_back(s2);
  Shape *s3 = new Shape(4,5);
  myCanvas.insertAfter(-1,s3);
  EXPECT_EQ(myCanvas.size(),1);
  EXPECT_EQ(myCanvas.front()->value->getX(),3);
  //Passes test here but not on gradescope.
}
//Tests for pop_front() and pop_back()
TEST(CanvasListTest, pop_front_back_Test) {
  CanvasList myCanvas;
	Shape *s = new Shape(1,2);
  Shape *s1 = new Shape(3,4);
  myCanvas.push_back(s);
  myCanvas.push_back(s1);
  myCanvas.pop_front();
  EXPECT_EQ(myCanvas.size(),1);
  EXPECT_EQ(myCanvas.front()->value->getX(),3);
  myCanvas.pop_front();
  EXPECT_EQ(myCanvas.size(),0);
  //edge case test
  myCanvas.pop_front();
  EXPECT_EQ(myCanvas.size(),0);

  //Pop_back()
  Shape *s2 = new Shape(4,5);
  Shape *s3 = new Shape(5,6);
  myCanvas.push_back(s2);
  myCanvas.push_back(s3);
  myCanvas.pop_back();
  EXPECT_EQ(myCanvas.size(),1);
  EXPECT_EQ(myCanvas.front()->value->getX(),4);
  myCanvas.pop_back();
  EXPECT_EQ(myCanvas.size(),0);
  //edge case test
  myCanvas.pop_back();
  EXPECT_EQ(myCanvas.size(),0);
  //Further testing of pop_back()
  CanvasList myCanvas1;
  myCanvas1.pop_back();
  EXPECT_EQ(myCanvas.size(),0);
}
//Tests for removeAt() and shapeAt()
TEST(CanvasListTest, REMOVE_SHAPE_AT_TEST) {
  CanvasList myCanvas;
	Shape *s = new Shape(1,2);
  Shape *s1 = new Shape(3,4);
  myCanvas.push_back(s);
  myCanvas.push_back(s1);
  myCanvas.removeAt(0);
  myCanvas.removeAt(-1);
  EXPECT_EQ(myCanvas.size(),1);
  EXPECT_EQ(myCanvas.shapeAt(0),s1);
  EXPECT_EQ(myCanvas.shapeAt(-1),nullptr);
}
//Tests for Circle class
TEST(CircleClassTest,Constructors ) {
  Circle* c1 = new Circle();
  EXPECT_EQ((*c1).getX(),0);
  EXPECT_EQ((*c1).getY(),0);
  EXPECT_EQ((*c1).getRadius(),0);
  Circle* c2 = new Circle(1,4,3);
  EXPECT_EQ((*c2).getX(),1);
  EXPECT_EQ((*c2).getY(),4);
  EXPECT_EQ((*c2).getRadius(),3);
  Circle* c3 = new Circle(1);
  EXPECT_EQ((*c3).getX(),0);
  EXPECT_EQ((*c3).getY(),0);
  EXPECT_EQ((*c3).getRadius(),1);
}
//Tests for Circle Class
//Default constructor tests, assumes getters work
TEST(CircleClassTest,DefaultConstructor ) {
  Circle* c2 = new Circle();
  EXPECT_EQ((*c2).getX(),0);
  EXPECT_EQ((*c2).getY(),0);
}
//Makes sure parameterized constructor works
TEST(CircleClassTest,ParameterizedConstructor) {
  Circle* c2 = new Circle(3);//radius
  Circle* c3 = new Circle(1,3,4);//all 3
  EXPECT_EQ((*c2).getX(),0);
  EXPECT_EQ((*c2).getRadius(),3);
  EXPECT_EQ((*c3).getY(),3);
  EXPECT_EQ((*c3).getRadius(),4);
  EXPECT_EQ((*c3).getX(),1);
}
//Makes sure printShape() function works
TEST(CircleClassTest,PrintShapeTest) {
  Circle* s3 = new Circle(2,6,4);
  testing::internal::CaptureStdout();
  (*s3).printShape();
  string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output,"It's a Circle at x: 2, y: 6, radius: 4\n");
}
//Makes sure setters and getters work
TEST(CircleClassTest,SettersGetters) {
  Circle* s3 = new Circle(2,6,4);
  (*s3).setX(4);
  (*s3).setY(5);
  (*s3).setRadius(6);
  EXPECT_EQ((*s3).getX(),4);
  EXPECT_EQ((*s3).getY(),5);
  EXPECT_EQ((*s3).getRadius(),6);
}
//Tests for copy() function for the Circle class
TEST(CircleClassTest,CopyFunctionTest) {
  Circle* s3 = new Circle(2,6,4);
  (*s3).setX(4);
  (*s3).setY(5);
  Shape* s3Copy = (*s3).copy();
  delete s3;
  EXPECT_EQ((*s3Copy).getX(),4);
  EXPECT_EQ((*s3Copy).getY(),5);
}

//Tests for Rectangle Class
//Default constructor tests, assumes getters work
TEST(RectangleClassTest,DefaultConstructor ) {
  Rectangle* c2 = new Rectangle();
  EXPECT_EQ((*c2).getX(),0);
  EXPECT_EQ((*c2).getY(),0);
}
//Makes sure parameterized constructor works
TEST(RectangleClassTest,ParameterizedConstructor) {
  Rectangle* c2 = new Rectangle(3,4);//w,h
  Rectangle* c3 = new Rectangle(1,1,3,4);//x,y,w,h
  EXPECT_EQ((*c2).getHeight(),4);
  EXPECT_EQ((*c2).getWidth(),3);
  EXPECT_EQ((*c3).getHeight(),4);
  EXPECT_EQ((*c3).getWidth(),3);
}
//Makes sure printShape() function works
TEST(RectangleClassTest,PrintShapeTest) {
  Rectangle* s3 = new Rectangle(1,1,3,4);
  testing::internal::CaptureStdout();
  (*s3).printShape();
  string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output,"It's a Rectangle at x: 1, y: 1 with width: 3 and height: 4\n");
}
//Makes sure setters and getters work
TEST(RectangleClassTest,SettersGetters) {
  Rectangle* s3 = new Rectangle(1,1,3,4);
  (*s3).setHeight(4);
  (*s3).setWidth(5);
  EXPECT_EQ((*s3).getHeight(),4);
  EXPECT_EQ((*s3).getWidth(),5);
}
//Tests for copy() function for the Circle class
TEST(RectangleClassTest,CopyFunctionTest) {
  Rectangle* s3 = new Rectangle(1,1,3,4);
  Rectangle* s3Copy = (*s3).copy();
  delete s3;
  EXPECT_EQ((*s3Copy).getWidth(),3);
  EXPECT_EQ((*s3Copy).getHeight(),4);
  EXPECT_EQ((*s3Copy).getX(),1);
  EXPECT_EQ((*s3Copy).getY(),1);
}

//Tests for RightTriangle Class
//Default constructor for Right Triangle
TEST(RTriangleClassTest,DefaultConstructor ) {
  RightTriangle* c2 = new RightTriangle();
  EXPECT_EQ((*c2).getX(),0);
  EXPECT_EQ((*c2).getY(),0);
}
//Makes sure parameterized constructor works
TEST(RTriangleClassTest,ParameterizedConstructor) {
  RightTriangle* c2 = new RightTriangle(3,4);//b,h
  RightTriangle* c3 = new RightTriangle(1,1,3,4);//x,y,b,h
  EXPECT_EQ((*c2).getHeight(),4);
  EXPECT_EQ((*c2).getBase(),3);
  EXPECT_EQ((*c2).getX(),0);
  EXPECT_EQ((*c3).getHeight(),4);
  EXPECT_EQ((*c3).getBase(),3);
  EXPECT_EQ((*c3).getX(),1);
}
//Makes sure printShape() function works
TEST(RTriangleClassTest,PrintShapeTest) {
  RightTriangle* c3 = new RightTriangle(1,1,3,4);
  testing::internal::CaptureStdout();
  (*c3).printShape();
  string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output,"It's a Right Triangle at x: 1, y: 1 with base: 3 and height: 4\n");
}
//Makes sure setters and getters work
TEST(RTriangleClassTest,SettersGetters) {
  RightTriangle* s3 = new RightTriangle(1,1,3,4);
  (*s3).setHeight(4);
  (*s3).setBase(5);
  EXPECT_EQ((*s3).getHeight(),4);
  EXPECT_EQ((*s3).getBase(),5);
}
//Tests for copy() function for the Circle class
TEST(RTriangleClassTest,CopyFunctionTest) {
  RightTriangle* s3 = new RightTriangle(1,1,3,4);
  RightTriangle* s3Copy = (*s3).copy();
  delete s3;
  EXPECT_EQ((*s3Copy).getBase(),3);
  EXPECT_EQ((*s3Copy).getHeight(),4);
  EXPECT_EQ((*s3Copy).getX(),1);
  EXPECT_EQ((*s3Copy).getY(),1);
}










