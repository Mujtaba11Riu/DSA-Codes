#include <iostream>
#include "DoubleyLinkList.h"
using namespace std;

/* ===================== Node Implementation ===================== */

Node::Node()
{
    data = -1;
    next = NULL;
    previous = NULL;
}

Node::Node(int data)
{
    this->data = data;
    next = NULL;
    previous = NULL;
}

int Node::getData()
{
    return data;
}

void Node::setData(int)
{
    this->data = data;
}

Node* Node::getNext()
{
    return next;
}

void Node::setNext(Node* next)
{
    this->next = next;
}

Node* Node::getPrevious()
{
    return previous;
}

void Node::setPrevious(Node* previous)
{
    this->previous = previous;
}

//================= DoubleLinkedList Implementation =============== 

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
}

bool DoubleLinkedList::isEmpty()
{
    return head == NULL;
}

void DoubleLinkedList::insertAtHead(int data)
{
    Node* temp = new Node(data);

    if (isEmpty())
    {
        head = tail = temp;
    }
    else
    {
        temp->setNext(head);
        head->setPrevious(temp);
        head = temp;
    }
}

void DoubleLinkedList::insertAtTail(int data)
{
    Node* temp = new Node(data);

    if (isEmpty())
    {
        head = tail = temp;
    }
    else
    {
        tail->setNext(temp);
        temp->setPrevious(tail);
        tail = temp;
    }
}

void DoubleLinkedList::insertAtTarget(int targetData, int data)

{
    Node* target = search(targetData);

    if (target == NULL)
    {
        cout << "Target not found!" << endl;
        return;
    }

    if (target == head)
    {
        insertAtHead(data);
        return;
    }

    Node* temp = new Node(data);
    Node* prev = target->getPrevious();

    prev->setNext(temp);
    temp->setPrevious(prev);
    temp->setNext(target);
    target->setPrevious(temp);

}

void DoubleLinkedList::remove(int data)
{
    Node* target = search(data);

    if (target == NULL)
    {
        cout << "Data not found!" << endl;
        return;
    }

    if (target == head)
    {
        head = head->getNext();
        if (head != NULL)
            head->setPrevious(NULL);
    }
    else if (target == tail)
    {
        tail = tail->getPrevious();
        tail->setNext(NULL);
    }


    else

    {
        Node* prev = target->getPrevious();
        Node* next = target->getNext();

        prev->setNext(next);
        next->setPrevious(prev);
    }

    delete target;
}

Node* DoubleLinkedList::search(int data)


{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->getData() == data)
            return temp;

        temp = temp->getNext();
    }
    return NULL;
}

void DoubleLinkedList::printAll()

{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

void DoubleLinkedList::printReverse()

{
    Node* temp = tail;

    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getPrevious();
    }
    cout << endl;
}
