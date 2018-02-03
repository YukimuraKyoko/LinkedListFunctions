#include <iostream>
#include "SingleLink.h"
using namespace std;


int main(){
    //Title
    cout << "--Single Listed Lists (of doubles)--" << endl;
    //Initialization
    string command = "";
    double input;
    int mth;
    SingleLink link;
    double mthValue;

    while(command != "endProgram"){
    cout << "Please select a command: " << endl << "pushFront | pushBack | popFront | popBack | insert | deleteDupes | size | positionFromLast | reversePrint | endProgram" << endl << endl;
        cin>>command;
        if(command == "pushFront"){
            cout << "Please enter a value(in decimal) : " << endl;
            cin >> input;
            link.pushFront(input);
            link.print();
         }
        else if(command == "pushBack"){
            cout << "Please enter a value(in decimal) : " << endl;
            cin >> input;
            link.pushBack(input);
            link.print();
        }
        else if(command == "popFront"){
            link.popFront();
            link.print();
        }
        else if(command == "popBack"){
            link.popBack();
            link.print();
        }
        else if(command == "insert"){
            cout << "Please enter a value(in decimal) : " << endl;
            cin >> input;
            cout << "Please which place you want to insert it in the linked list(in whole number) : " << endl;
            cin >> mth;
            link.insertNode(mth,input);
            link.print();
        }
        else if(command == "deleteDupes"){
            cout << "Please enter a value(in decimal) : " << endl;
            cin >> input;
            link.deleteDuplicates(input);
            link.print();
        }
        else if(command == "size"){
            link.showSize();
        }
        else if(command == "positionFromLast"){
            //Spacer
            cout << endl;
            cout << "Please enter a mth value(in whole number) : " << endl;
            cin >> mth;
            mthValue = link.motLastElement(mth);
            cout << "The value of the " << mth << " position from the last is: " << mthValue << endl << endl;
        }
        else if(command == "reversePrint"){
            link.reverseList();
        }
    }

    return 0;
}
