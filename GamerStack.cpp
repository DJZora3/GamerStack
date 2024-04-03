#include "GamerStack.h"


GamerStack::GamerStack()
{
	first = nullptr;
	elementNum = 0;
}

GamerStack::GamerStack(int firstData)
{
	Node* firstNode = new Node(firstData);
	first = firstNode;
	elementNum = 1;
}

GamerStack::GamerStack(GamerStack& copyStack)
{
	first = copyStack.getFirst();
	elementNum = copyStack.getElementNum();
}

Node* GamerStack::getFirst()
{
	return first;
}


void GamerStack::push(int data)
{
	if (first != nullptr) {
		Node* newFirst = new Node(data);
		newFirst->setNext(first);
		first = newFirst;
	}
	else {
		first = new Node(data);
	}
	
	++elementNum;

}

int GamerStack::pop()
{
	Node* newFirst = first->getNext();
	int dataToReturn = first->getData();

	elementNum -= 1;

	delete first;
	first = newFirst;

	return dataToReturn;
}

std::string GamerStack::isEmpty() const
{
	if (first == nullptr) {
		return "The stack is empty!";
	}
	else {
		return "The stack has some stuff...";
	}
}

int GamerStack::getElementNum() const
{
	return elementNum;
}

void GamerStack::remove(int index)
{
	if (first != nullptr && index < elementNum) {
		Node* iterator = first;
		Node* prior = nullptr;

		for (int i = 0; i < index; ++i) {
			iterator = iterator->getNext();
			if (i == index - 2) {
				prior = iterator;
			}
		}

		prior->setNext(iterator->getNext());

		//std::cout << prior->getData() << " " << iterator->getData();   the debug line that saved my life


		delete iterator;
		elementNum = elementNum - 1;
	}
	else if (first == nullptr) {
		std::cout << "first is nullptr, nothing to remove lol" << std::endl;
	}
	else if (index > elementNum) {
		std::cout << "bigger number then there are elements in list, doofus" << std::endl;
	}
	else {
		std::cout << "ERROR that isnt the other 2 related to remove" << std::endl;
	}
}

void GamerStack::clearStack()
{
	if (first != nullptr) {
		int numOfElements = elementNum;
		for (int i = 0; i < numOfElements; ++i) {
			pop();
		}
		elementNum = 0;
		first = nullptr;
	}
	else {
		std::cout << "first is nullptr, cant clear what aint there" << std::endl;
	}
}

void GamerStack::printStack() const
{
	if (first != nullptr) {
		std::cout << "Gamer Stack printout:" << std::endl;

		Node* temp = first;		//temp is the variable to be printed

		for (int i = 0; i < elementNum; ++i) {
			std::cout << temp->getData() << std::endl;
			temp = temp->getNext();
		}
	}
	else {
		std::cout << "stack is empty buddy, stack some items" << std::endl;
	}
}

void GamerStack::saveStack() const
{
	if (first != nullptr) {
		std::ofstream save;

		save.open("save.txt");

		if (save.is_open()) {
			Node* temp = first;	//temp is the variable to be printed

			for (int i = 0; i < elementNum; ++i) {
				save << temp->getData() << " ";
				temp = temp->getNext();
			}
		}

		save.close();
		std::cout << "Stack saved!" << std::endl;
	}
	else {
		std::cout << "stack is empty buddy, stack some items" << std::endl;
	}
}

GamerStack::~GamerStack()
{
	if (first != nullptr) {
		int numOfElements = elementNum;
		for (int i = 0; i < numOfElements; ++i) {
			pop();
		}
	}
	first = nullptr;
}
