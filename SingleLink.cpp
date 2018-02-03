#include "SingleLink.h"
#include <iostream>
using namespace std;


// CONSTRUCTOR
SingleLink::SingleLink(){
    firstNode = NULL;
    //Size of linked list
    listSize = 0;
}

// DESTRUCTOR
SingleLink::~SingleLink(){
    //Temp points to head
    Node *temp = firstNode;

    while(temp != NULL){
        //toDelete points to temp/head
        Node *toDelete = temp;
        //temp moves over to next temp
        temp = temp->next;
        //delete the space where temp was
        delete toDelete;
    }
}
// PushFront
void SingleLink::pushFront(double x){
    //Initialization
    Node *temp = new Node;

    if(temp == NULL){
        firstNode->value = x;
        firstNode->next = NULL;
        listSize++;
    }
    else{
        temp->value = x;
        //Connect temp to head
        temp->next = firstNode;
        //FirstNode becomes temp
        firstNode = temp;
        listSize++;
    }
}

// Print
void SingleLink::print() const{
    //Spacer for above
    cout << endl;
    //Initialization
   Node *temp = firstNode;
    if(temp == NULL){
        cout << "linked list is empty" << endl;
        return;
    }
    else{
        cout << "Linked List: " << endl;
        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl << "Linked list size: " << listSize << endl;
        cout << endl;
    }
}


// PopFront
void SingleLink::popFront(){
    //toPop points to head
    Node *toPop = firstNode;

    if(toPop != NULL){
        //newHead will point to head->next
        Node *newFirstNode = toPop->next;
        //delete head
        delete toPop;
        //Head becomes newHead
        firstNode = newFirstNode;
        listSize--;
    }
    else{
        cout << "Linked list is empty, nothing to pop" << endl;
    }
}

// PushBack
void SingleLink::pushBack(double x){
    //Initialization
    Node *toInsert = new Node;
    toInsert->next = NULL;
    toInsert->value = x;

    if(firstNode != NULL){
        Node *temp = firstNode;
        //Search for lastNode
        while(temp->next != NULL){
            temp = temp->next;
        }
        //Insert new node after last node
        temp->next = toInsert;
    }
    else{
        firstNode = toInsert;
    }
    listSize++;
}

// PopBack
void SingleLink::popBack(){
    //Initialization
    Node *temp = firstNode;
    Node *toDelete;
    if(temp != NULL){
        //Locating lastNode
        while(temp->next->next != NULL){
            //When temp->next is NULL, toDelete = lastNode
            temp = temp->next;
        }
        //When temp is NULL, toDelete is always before temp
        toDelete = temp->next;
        delete toDelete;
        temp->next = NULL;
        listSize--;
    }
    else{
        cout << "Empty list, nothing to pop" << endl;
    }
}


SingleLink::SingleLink(const SingleLink& rhs){
    *this = rhs;
}

//Overloaded Assignment Operator
SingleLink& SingleLink::operator=(const SingleLink& rhs){
    //copy linked list
    Node *temp = firstNode;
    while(temp != NULL){
        Node *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    temp = rhs.firstNode;
    Node *lastNode = NULL;
    while(temp != NULL){
        Node *newNode = new Node();
        newNode->value = temp->value;
        if(lastNode != NULL){
            lastNode->next = newNode;
        }
        else{
            firstNode = newNode;
        }
        lastNode = newNode;
        temp = temp->next;
    }
    listSize = rhs.listSize;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SingleLink& printLink){
    printLink.print();
return os;
}


void SingleLink::deleteDuplicates(double value){
    //Initialization
    Node* toSearch = new Node;
    toSearch->next = NULL;
    toSearch->value = value;
    Node *temp = firstNode;
    Node *toDelete;
    if(firstNode == NULL){
        cout << "Linked list is empty" << endl;
        return;
    }
    else{
        while(temp != NULL){
            if(toSearch->value == temp->value){
                //Marking temp to be deleted
                toDelete = temp;
                //Temp moves to next
                temp = temp->next;
                //Delete previous space where temp was
                delete toDelete;
                listSize--;
            }
            temp = temp->next;
        }
    }

}

double SingleLink::motLastElement(int M){
    Node *temp = firstNode;
    double toReturn;
    //Example: If M was 2, we want 2nd to last. So if listSize = 6, then we want 4th element
    int counter = listSize - M;
    if(M <= listSize){
        //i = 1 -> i = firstNode
        for(int i = 1; i <= counter; i++){
            if(i == counter){
                toReturn = temp->value;
                return toReturn;
            }
            temp = temp->next;
        }
    }
    else{
        cout << "Please input a number that is not bigger than the list Size" << endl;
        cout << "Current ListSize: " << listSize << endl;
        cin >> M;
        motLastElement(M);
    }
}


void SingleLink::reverseList(){
    int reverseCount = listSize;
    Node *temp = firstNode;
    if(firstNode == NULL){
        cout << "Unable to reverse list if nothing is in the linked list" << endl;
        return;
    }
    else{
        //i starts as length of list
        for(int i = reverseCount; i >= 1; i--){
            //Iterate though list to the "i"th element
            while(i != 0){
                temp = temp->next;
            }
            //Print the "i"th element
            cout << temp->value << " ";
            //Temp goes back to beginning, and "i"th decreases by 1
            temp = firstNode;
        }
    }
}

void SingleLink::showSize(){
    cout << "Current size of Listed List: " << listSize << endl;
}

void SingleLink::insertNode(int place, double value){
    Node *temp = firstNode;
    Node *toInsert = new Node;
    toInsert->value = value;
    if(temp == NULL){
        firstNode->value = value;
        firstNode->next = NULL;
    }
    else{
        for(int i=1; i <= place; i++){
            //Locates previous space before inserting
            if((i-1) == place){
                //toInsert becomes the indicated placeHolder
                temp->next = toInsert;
                //Following toInsert is two more next spaces in temp
                toInsert->next = temp->next->next;
                return;
            }
            temp = temp->next;
        }
    }

}
