#include "linkedlist.h"
#include <iostream>
using namespace std;

Node *LinkedList::getFirst() const
{
    return first;
}

void LinkedList::setFirst(Node *value)
{
    first = value;
}

int LinkedList::getT() const
{
    return t;
}

void LinkedList::setT(int value)
{
    t = value;
}

Node* LinkedList::pop()
{
    if (this->first != nullptr){
            Node* toReturn = this->first;
            this->first = this->first->getNext();
            toReturn->setNext(nullptr);
            this->t--;
            return toReturn;
        }
    return nullptr;
}

void LinkedList::Add(void *data)
{
    Node* temp = this->first;
        if (this->first != nullptr){
            while (temp->getNext()  != nullptr){
                temp = temp->getNext();
            }
            Node* aux = new Node(data);
            temp->setNext(aux);
            aux->setNext(nullptr);
            this->t++;
        }
        else{
            Node* aux = new Node(data);
            this->first = aux;
            first->setNext(nullptr);
            this->t++;
        }
    }



Node* LinkedList::remove(Node* nodo){//para la lista de carros

        for (Node* aux = this->first;aux!=nullptr;aux = aux->getNext()) {
            //si es el head
            if (nodo == first){
                first = first->getNext();
                nodo->setNext(nullptr);
                this->t--;
                return nodo;
            }
            //si es cualquier otro
            else if(aux->getNext()->getData()==nodo->getData()){
                Node* devolver;
                devolver = aux->getNext();
                aux->setNext(aux->getNext()->getNext());
                devolver->setNext(nullptr);
                this->t--;
                return devolver;
            }

        }
        qDebug()<<"El nodo no esta en la lista";
        return nullptr;
}
Node* LinkedList::removeLast(){//para la lista de carros
    Node* temp=this->first;
    Node* aux=this->first;
    while (aux!=nullptr) {
        if(aux->getNext()==nullptr){
            this->t--;
            delete(temp->getNext());
            temp->setNext(nullptr);
            cout<<"remove:  "<<*(int*)aux->getData()<<endl;
            return aux;
        }else{
            temp=aux;
            aux = aux->getNext();
        }
    }
    qDebug()<<"El nodo no esta en la lista";
    return nullptr;
}

void LinkedList::Print()
{
    Node* tmp=this->first;
    while (tmp!=nullptr){
        cout<<tmp<<endl;
        tmp=tmp->getNext();
    }
}

LinkedList::LinkedList()
{
    this->t=0;
    this->first=0;
}
