#pragma once
//change data type in this and the .h and it should just work
//can change # of variables, just make gets/sets for them and it should be ok

class Node
{
private:
	int data;     //the data being stored
	Node* next;   //the pointer to the next node

public:
	Node();								//default constructor
	Node(int newData);					//integer constructor
	Node(int newData, Node* newNext);   //full constructor
	Node(Node& copyNode);				//copy constructor
	int getData() const;				//gets the data
	Node* getNext() const;				//gets the next node in line
	void setData(int newData);			//sets the data
	void setNext(Node* newNext);		//sets the next node

};

