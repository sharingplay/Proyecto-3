#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include "node.h"
#include <QDebug>


class LinkedList
{
private:
    Node* first;
    int t;
    int value;
    char val;
public:
    void Add(void* data);
    Node* remove(Node* nodo);
    void Print();
    LinkedList();
    Node *getFirst() const;
    void setFirst(Node *value);
    int getT() const;
    void setT(int value);
    Node* pop();
    Node* removeLast();
};

#endif // LINKEDLIST_H
