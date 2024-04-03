#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
//this is all set up based around int, would have to do minor amounts of refactoring for other data types
class GamerStack
{
private:
	Node* first;		//pointer to first node in list
	int elementNum;		//number of elements in list
	Node* getFirst();					//gets the first node, only used to debug basically

public:
	GamerStack();						//default constructor
	GamerStack(int firstData);			//giving it the first data
	GamerStack(GamerStack& copyStack);  //copy constructor

	void push(int data);				//add one to top of stack, takes data
	int pop();							//remove from top of stack, spits out data
	std::string isEmpty() const;				//tells whether or not the stack is empty
	int getElementNum() const;				//gets the number of elements

	void remove(int index);
	
	void clearStack();					//clears list
	void printStack() const;					//prints list
	void saveStack() const;					//writes stack to list

	~GamerStack();						//destructor

	//DEBUG
	//Node* getFirst();
};

