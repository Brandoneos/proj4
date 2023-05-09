/*
Author: BRANDON KIM
DATE: 3/28/2023
Course: CS 251

Description: This file(canvaslist.h) includes the ShapeNode class and CanvasList class each 
with separate functions. The ShapeNode class is for the nodes inside the CanvasList class,
which is the linked list.

*/

#pragma once

#include "shape.h"
#include <iostream>


using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;
        ShapeNode *listBack;

    public:
        CanvasList();
        CanvasList(const CanvasList &);
        CanvasList operator=(const CanvasList &);
        
        virtual ~CanvasList();
        void clear();
        
        void insertAfter(int, Shape *);
        void push_front(Shape *);
        void push_back(Shape *);
        
        void removeAt(int);
        Shape* pop_front();
        Shape* pop_back();

        ShapeNode* front() const;
        bool isempty() const;
        int size() const;

        int find(int x, int y) const;
        Shape* shapeAt(int) const;
        
        void draw() const;
        void printAddresses() const;
};
//Default constructor for CanvasList
CanvasList::CanvasList() {
    listSize = 0;
    listFront = nullptr;
    listBack = nullptr;
}
//Copy constructor for CanvasList, takes in another CanvasList, and makes a new CanvasList with the same values but new pointers.
CanvasList::CanvasList(const CanvasList & c) {
    if(c.front() == nullptr) {//if the canvasList is empty, the copied one should be the same
        listFront = listBack = nullptr;
        listSize = 0;
        return;
    } else if(c.listSize == 1) {
        //case with only one node in the canvasList
        ShapeNode* newFront = new ShapeNode;
        newFront->value = c.listFront->value->copy();//make new shape
        newFront->next = nullptr;
        listFront = newFront;
        listBack = newFront;//sets the front and back to the only node
        listSize = 1;
        return;
    }

    //Case of 2 or more nodes in CanvasList c
    listSize = c.size(); //listSize set to the same as c
    ShapeNode* currentC = c.front();
    ShapeNode* current = listFront;
    for (int i = 0; i < listSize;i++) {
        //for every node create a temporary shapeNode
        ShapeNode* temp = new ShapeNode();
        if(i == 0) {
            //for the front node
            temp->next = nullptr;
            Shape* newShape = c.front()->value->copy();//make new shape
            temp->value = newShape;
            listFront = temp;
            current = listFront;//update current to avoid errors
        } else {
            Shape* newShape = currentC->value->copy();//make new shape
            temp->value = newShape;
            temp->next = nullptr;
            current->next = temp;
            //makes the previous node's next pointer to temp which is the current node, since current is behind one
            current = current->next;
            listBack = current;
            
        }
        currentC = currentC->next;//looping through the copied canvasList
      
    }
    

    
}
//operator= function, creates a deep copy of the parameter CanvasList with different pointers, same values.
CanvasList CanvasList::operator=(const CanvasList & c) { 
    this->clear();//first clear the original canvasList to avoid errors
    if(c.front() == nullptr) {//case of empty canvasList being passed in
        this->listFront = this->listBack = nullptr;
        this->listSize = 0;
        return *this;
    }
    this->listSize = c.size();

    ShapeNode* currentC = c.front();
    ShapeNode* current = listFront;
    //loop through the canvasList c
    for (int i = 0; i < listSize;i++) {
        ShapeNode* temp = new ShapeNode();
        if(i == 0) {//edge case of the front node
            temp->next = nullptr;
            Shape* newShape = c.front()->value->copy();
            temp->value = newShape;
            this->listFront = temp;
            current = this->listFront;//update current to avoid error
        } else {
            Shape* newShape = currentC->value->copy();
            temp->value = newShape;
            temp->next = nullptr;
            current->next = temp;
            //makes previous node's next pointer point to current node being made which is temp
            current = current->next;
            this->listBack = current;
        }
        currentC = currentC->next;//loop through copied canvasList c
    }

    return *this;
}
//Destructor for CanvasList ✅
CanvasList::~CanvasList() {

}
//Clear function, deletes the ShapeNodes and shapes inside the canvasList
//no parameters and returns nothing
void CanvasList::clear() { 

    if(listFront == nullptr && listBack == nullptr) {
        return;
    }
    ShapeNode* current = listFront;
    ShapeNode* temp = listFront;
    listBack = nullptr;
    listFront = nullptr;
    while(current->next != nullptr) {//loop through linked list
        current = current->next;
        delete temp->value;
        delete temp;//delete both the shape and node
        temp = current;
    }
    delete temp->value;
    delete temp;//delete last node and shape
    // if(current != nullptr) {
    //     delete current;
    // }
    listSize = 0;
}
//insertAfter() function, takes in an index x and shape to add, returns nothing
//Adds the Shape after the given index inside the canvasList
void CanvasList::insertAfter(int x, Shape * s) {
   if(x < 0) {//if the index is out of range
    return;
   } else if(x >= listSize) {//if the index is out of range
    return;
   } 

   int currentIndex = 0;
   ShapeNode* current = listFront;
   while (currentIndex != x) {//go to the shapeNode at the given index
    current = current->next;
    currentIndex++;
   }

   if(x == listSize-1) {
    //Place at the end
    ShapeNode* newNode = new ShapeNode;
    newNode->next = nullptr;
    newNode->value = s;
    current->next = newNode;
    listSize++;
   } else {
    //place in the middle somewhere
    ShapeNode* newNode = new ShapeNode;
    newNode->next = current->next;;
    newNode->value = s;
    current->next = newNode;
    listSize++;
   }
    return;
}
//push_front() function, takes in a shape, which is added to the canvasList at the front.
void CanvasList::push_front(Shape * s) { 
    ShapeNode* temp = new ShapeNode;
    temp->value = s;
    temp->next = listFront;
    if(listFront == nullptr) {//if this is the only shape added in the canvasList, make it the listBack as well
        listBack = temp;
    }
    listFront = temp;//make the listFront this new shapeNode
    listSize++;
    
}
//push_back() function, takes in a shape, which iss added to the canvasList at the back
void CanvasList::push_back(Shape * s) {
    ShapeNode* temp = new ShapeNode;
    temp->value = s;
    temp->next = nullptr;
    if(listFront == nullptr) {//if this is the only shape added in the canvasList, make it the listBack/listFront
        listBack = temp;
        listFront = temp;
    } else {
        listBack->next = temp;//add it to the listBack and update listBack.
        listBack = temp;
    }
    listSize++;
   
}
//removeAt() function, takes in an index x. The shapeNode at this index is removed. returns nothing
void CanvasList::removeAt(int x) {
    //go through the linkedlist to find it,
    if(x < 0) {
        return;
    } else if(x >= listSize) {
        return;
    } else if(x == 0 && listSize == 1) {
        ShapeNode* nodeToDelete = listFront;
        listFront = nullptr;
        listBack = nullptr;
        delete nodeToDelete->value;
        delete nodeToDelete;
        listSize--;
        return;
    }
    ShapeNode* cur = listFront;
    ShapeNode* nodeToDelete;
    if(x == 0) {
        //special case of removing head
        nodeToDelete = listFront;
        listFront = listFront->next;
        nodeToDelete->next = nullptr;
        delete nodeToDelete->value;
        delete nodeToDelete;
        listSize--;
    } else {
        for (int i = 0; i < x - 1; i++) {
            cur = cur->next;//go to ShapeNode before the index;
        }
        nodeToDelete = cur->next;
        cur->next = nodeToDelete->next;
        nodeToDelete->next = nullptr;
        delete nodeToDelete->value;//delete shape and node
        delete nodeToDelete;
        if(x == listSize - 1) {//If listBack was deleted, update listBack
            listBack = cur;
        }
        listSize--;
    }
    

}
//pop_front() function, no parameter but returns a nullptr or the shape* of the canvasList's first node.
Shape* CanvasList::pop_front() {
    if(listBack == nullptr) {//if canvasList is empty
        return nullptr;
    } else if (listSize == 1) {//if canvasList only has 1 shapeNode
        Shape* returnShape = listFront->value;
        ShapeNode* last = listFront;
        listBack = nullptr;
        listFront = nullptr;

        delete last;
        listSize--;
        return returnShape;
    }
    //if canvasList has more than 1 shapeNode.
    Shape* returnShape = listFront->value;
    ShapeNode* toDelete = listFront;
    if(listFront->next != nullptr) {//deletes the front
        listFront = listFront->next;
    } else {
        listFront = nullptr;
    }
    listSize--;
    delete toDelete;//delete node but not shape
    return returnShape;

}
//pop_back() function
Shape* CanvasList::pop_back() {
    //go through entire linkedlist until the end. remove the end and delete node, don't delete shape.
    if(listFront == nullptr) {
        return nullptr;
    } else if(listSize == 1) {

        Shape* returnShape = listBack->value;
        ShapeNode* last = listBack;
        listBack = nullptr;
        listFront = nullptr;
        delete last;
        listSize--;
        return returnShape;
    }
    
    Shape* returnShape = listBack->value;
    ShapeNode* last = listBack;

    
        ShapeNode * cur = listFront;
        while (cur->next != listBack) {
            cur = cur->next; //Gets to second to last node.
        }
        cur->next = nullptr;
        listBack = cur;
        delete last;

    listSize--;
    return returnShape;

}
//front() function, no parameters but returns the front node of the canvasList
ShapeNode* CanvasList::front() const {
    return listFront;
}
//isempty() function, no parameters but returns whether the canvaslist is empty of not
bool CanvasList::isempty() const {
    return (listFront == nullptr && listBack == nullptr); //is an empty linked list's head auto set to nullptr;
}
//size() function, no parameters but returns the size of the canvasList
int CanvasList::size() const {
    return listSize;
}
//find() function, takes in coordinates x and y and finds the ShapeNode with the shape with those coordinates. 
// Then returns the index of the shapeNode or -1 if not found
int CanvasList::find(int x, int y) const {
    ShapeNode * cur = listFront;
    int index = 0;
    while (cur != nullptr) {//loops through linked list
        if(cur->value->getX() == x && cur->value->getY() == y) {
            return index;
        }
        index++;
        cur = cur->next;
    }
    return -1;

    //gives index of shapeNode with shape of the specified coordinates
}
//shapeAt() function, takes in index i, finds the shapeNode at the given index, and returns the Shape* at that index
Shape* CanvasList::shapeAt(int i) const {
    if(i < 0) {//if index is out of range
        return nullptr;
    } else if(i >= listSize) {
        return nullptr;
    } 
    //go through list until index i, use listSize. Then return shape at node.
    ShapeNode * cur = listFront;
    for (int x = 0; x < i; x++) {
        cur = cur->next;
    }
 
    return cur->value;
}

//Draw function. no parameters but prints out the CanvasList in order
void CanvasList::draw() const {
    if (listFront == nullptr) {//if the canvasList is empty
        return;
    }

    ShapeNode* temp = listFront;
    while (temp != NULL) {//loops through the canvasList and prints out each shape
        temp->value->printShape();
        temp = temp->next;
    }
}

//printAddressess() function, no parameters but prints out the addresses of the canvasList's shapenodes and shapes, returns nothing
void CanvasList::printAddresses() const {
    ShapeNode * cur = listFront;
    for (int i = 0; i < listSize; i++) {
        cout << "Node Address: " << (&cur) << "\tShape Address: " << (cur->value) << endl;
        cur = cur->next;
    }
}