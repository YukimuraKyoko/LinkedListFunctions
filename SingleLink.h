#ifndef SINGLELINK_H_INCLUDED
#define SINGLELINK_H_INCLUDED
#include <iostream>
using namespace std;

class SingleLink{
private:

struct Node{
        double value;
        Node *next;
    };

    //head of Node
    Node *firstNode;
    //Size of linked list
    int listSize;

public:
    //constructor
    SingleLink();
    //destructor - BIG3
    ~SingleLink();
    //copy constructor - BIG3
    SingleLink(const SingleLink&);
    //overloaded assignment operator - BIG3
    SingleLink& operator=(const SingleLink&);
    void print() const;
    void pushFront(double x);
    void popFront();
    void pushBack(double x);
    void popBack();
    void insertNode(int index, double value);
    void deleteDuplicates(double value);
    double motLastElement(int M);
    void showSize();
    friend std::ostream& operator<<(std::ostream& os, const SingleLink& printLink);
    void reverseList();
};
#endif // SINGLELINK_H_INCLUDED
