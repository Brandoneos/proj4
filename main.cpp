/// @filename main.cpp
/// @date March 7, 2023

#include <iostream>
#include "canvaslist.h"
#include "shape.h"

using namespace std;


int main()
{

	//valgrind checks

	CanvasList c1;
	Shape *s = new Shape(4,5);
	c1.push_back(s);
	CanvasList c2(c1);
	c1.clear();
	c2.clear();
	//copy function in SHape
	// Shape *s = new Shape(4,5);
	// Shape *s1 = s->copy();
	// delete s;
	// cout << "s1: x coordinate : " << s1->getX() << endl;

	//copy constructor test again
	// CanvasList myCanvas;
	// Shape *s2 = new Shape(4,5);
  	// Shape *s3 = new Shape(5,6);
	// myCanvas.push_back(s2);
	// myCanvas.push_front(s3);
	// myCanvas.draw();
	// cout << "front: " << myCanvas.front()->value->getX() << endl;
	// cout << "back: " << myCanvas.back()->value->getX() << endl;
	// cout << "front next next: " << myCanvas.front()->next->value->getX() << endl;
	// CanvasList myCanvas2;
	// myCanvas2 = myCanvas;//error
	// cout << "Test" << endl;
	// myCanvas.clear();
	
	// myCanvas.draw();
	// myCanvas2.draw();
	// // cout << "myCanvas2 size: " << myCanvas2.size() << endl;

	// myCanvas2.clear();
	// myCanvas.clear();
	// myCanvas2.clear();
	// myCanvas.draw();
	// myCanvas2.draw();
	// cout << "Test" << endl;



	//pop_back() test
	//guess: 
	//1. check empty canvaslist, popback() 2. add a shapenode, pop_back()
	// 3. continue pop_back() 

	// CanvasList c;
	//  //Doesn't call default constructor
	// CanvasList* myCanvas1 = new CanvasList();
	// Shape *s2 = new Shape(4,5);
  	// Shape *s3 = new Shape(5,6);
	// Shape *s4 = new Shape(6,7);
	// myCanvas1->pop_back();
	// (*myCanvas1).push_front(s2);//myCanvas is uninitialized but myCanvas1 isn't..
	// //push_front is wrong
  	// // myCanvas->push_back(s2);
	// myCanvas1->pop_back();
  	// // myCanvas->push_back(s3);
	// // myCanvas.push_back(s4);
	// // myCanvas->pop_front();
	// // myCanvas->pop_back();
	// // if(myCanvas1->pop_back() == s2) {
	// // 	cout << "This is supposed to print" << endl;
	// // }

	
	// myCanvas1->pop_back();
	// popped->printShape();
	// myCanvas.draw();
	// myCanvas->pop_back();


	

	//Operator= test : myCanvas2 = myCanvas;
	// CanvasList myCanvas;
	// //copy constructor : CanvasList canvas2(myCanvas);
	// Shape *s = new Shape(1,4);
	// myCanvas.push_back(s);
  	// CanvasList myCanvas2;
  	// myCanvas2 = myCanvas;
	// cout << "myCanvas: " << myCanvas.size() << endl; //should say 1
	// cout << "myCanvas2: " << myCanvas2.size() << endl; //should say 1
  	// myCanvas.clear();
	// cout << "myCanvas: " << myCanvas.size() << endl; //should say 0
	// cout << "myCanvas2: " << myCanvas2.size() << endl; //should say 1

	//automatic one alloc and 1 free by valgrind
	//Making sure push_back() works for sure
	// Shape* s1 = new Shape(1,1);//one alloc
	// CanvasList myCanvas;//zero alloc and zero free
	// myCanvas.push_back(s1); //two alloc
	// CanvasList canvas2(myCanvas);// only does 1 alloc, should do 2?
	// myCanvas.clear();
	// delete s1;
	// cout << "canvas2: front's x: " << canvas2.front()->value->getX() << endl;
	// canvas2.clear();
	// //7 allocs, 7 frees.

	// //Valgrind check
	// Shape* s1 = new Shape();
	// delete s1;
	// CanvasList myCanvas;
	// Shape *s = new Shape(1, 3);
	// myCanvas.push_front(s);
	// cout << "List size: " << myCanvas.size() << endl;
	// myCanvas.draw();

	//making sure clear() worked and draw();

	// CanvasList myCanvas;
	
	// Shape *s = new Shape(1,3);
	// myCanvas.push_back(s);
	// cout << "Size myCanvas: " << myCanvas.size() << endl;
	// CanvasList canvas2(myCanvas);
  	// myCanvas.clear();
	// cout << "Size myCanvas after clear: " << myCanvas.size() << endl;
	// cout << "Size canvas2: " << canvas2.size() << endl;
	
	// canvas2.draw();
	// myCanvas.draw();//trying to draw an empty canvas?
	
	// canvas2.clear();
	// // myCanvas.clear();
	

	//Below this is related to output.txt -------------------------

	// CanvasList myCanvas;
	// cout << "List size: " << myCanvas.size() << endl;
	// cout << "Front: " << myCanvas.front() << endl;

	// cout << endl << endl << "Adding Shape to the front" << endl;
	// Shape *s = new Shape(1, 3);
	// myCanvas.push_front(s);
	// cout << "List size: " << myCanvas.size() << endl;
	// myCanvas.draw();

	// cout << endl << endl << "Adding Circle to the front" << endl;
	// s = new Circle(2, 4, 3);
	// myCanvas.push_front(s);
	// cout << "List size: " << myCanvas.size() << endl;
	// myCanvas.draw();

	// cout << endl << endl << "Adding Rectangle to the back" << endl;
	// s = new Rectangle(0, 10);
	// myCanvas.push_back(s);
	// cout << "List size: " << myCanvas.size() << endl;
	// myCanvas.draw();

	// cout << endl << endl << "Adding Right Triangle to the front" << endl;
	// s = new RightTriangle(1, 2, 3, 4);
	// myCanvas.push_front(s);
	// cout << "List size: " << myCanvas.size() << endl;
	// myCanvas.draw();

	// cout << endl << endl << "Deleting last element" << endl;
	// delete myCanvas.pop_back();
	// cout << "List size: " << myCanvas.size() << endl;
	// myCanvas.draw();

	// cout << endl << endl << "Deleting first element" << endl;
	// delete myCanvas.pop_front();
	// cout << "List size: " << myCanvas.size() << endl;
	// myCanvas.draw();

	// cout << endl << endl << "Finding the shape at 2, 4" << endl;
	// myCanvas.draw();
	// int loc = myCanvas.find(2,4);
	// cout << "Found location: " << loc << endl;
	// s = myCanvas.shapeAt(loc);
	// s->printShape();
	// cout << "List size: " << myCanvas.size() << endl;

	// cout << endl << endl << "Inserting Rectangle after index 1" << endl;
	// cout << "Original:" << endl;
	// myCanvas.draw();
	// myCanvas.insertAfter(1, new Rectangle(3,4,5,5));
	// cout << "Updated Original:" << endl;
	// myCanvas.draw();


	// cout << endl << endl << "Removing index 0" << endl;
	// cout << "Original:" << endl;
	// myCanvas.draw();
	// myCanvas.removeAt(0);
	// cout << "Updated Original:" << endl;
	// myCanvas.draw();


	// cout << endl << endl << "Removing index 45" << endl;
	// cout << "Original:" << endl;
	// myCanvas.draw();
	// myCanvas.removeAt(45);
	// cout << "Updated Original:" << endl;
	// myCanvas.draw();


	// cout << endl << endl << "Creating a copy of the canvas list" << endl;
	// cout << "Original:" << endl;
	// myCanvas.draw();
	// CanvasList second = myCanvas;
	// cout << "Copy:" << endl;
	// second.draw();
	// cout << "Original:" << endl;
	// myCanvas.printAddresses();
	// cout << "Copy:" << endl;
	// second.printAddresses();


	// // cout << endl << endl << "Clearing all elements and internal shapes" << endl;
	// myCanvas.clear();
	// // cout << "List size: " << myCanvas.size() << endl;
	// // cout << "Original:" << endl;
	// // myCanvas.draw();
	// // cout << "Copy:" << endl;
	// // second.draw();

	
	// // cout << endl << endl << "Using the assignment operator to overright copy." << endl;
	// s = new Shape(4, 2);
	// myCanvas.push_front(s);//here--------------------------------------------------------------------------------------------
	// // cout << "List size: " << myCanvas.size() << endl;
	// // cout << "Original:" << endl;
	// // myCanvas.draw();
	// // cout << "Copy:" << endl;
	// // second.draw();
	// // cout << "Original:" << endl;
	// // myCanvas.printAddresses();
	// // cout << "Copy:" << endl;
	// // second.printAddresses();
	// second = myCanvas;//and here------------------------------------------------------------------------------------------
	// // cout << "Original:" << endl;
	// // myCanvas.draw();
	// // cout << "Copy:" << endl;
	// // second.draw();
	// // cout << "Original:" << endl;
	// // myCanvas.printAddresses();
	// // cout << "Copy:" << endl;
	// // second.printAddresses();
	// second.clear();//added
	// myCanvas.clear();//added
	// // delete s;//added



	return 0;
}
