#include "Node.h"

Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::Node(int newData)
{
    data = newData;
    next = nullptr;
}

Node::Node(int newData, Node* newNext)
{
    data = newData;
    next = newNext;
}

Node::Node(Node& copyNode)
{
    data = copyNode.getData();
    next = copyNode.getNext();
}

int Node::getData() const
{
    return data;
}

Node* Node::getNext() const
{
    return next;
}

void Node::setData(int newData)
{
    data = newData;
}

void Node::setNext(Node* newNext)
{
    next = newNext;
}
