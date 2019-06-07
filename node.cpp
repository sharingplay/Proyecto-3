
#include "node.h"

Node *Node::getNext() const
{
    return this->next;
}

void Node::setNext(Node *value)
{
    this->next = value;
}

void *Node::getData() const
{
    return this->data;
}

void Node::setData(void *value)
{
    this->data = value;
}

Node::Node(void* data)
{
    //cout<<"nodeee"<<*(int*)data<<endl;
    this->data=data;
    this->next=nullptr;
}
