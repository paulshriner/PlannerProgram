//Programming Club Code Jam Submission
//by Paul Shriner

#include <iostream>
#include <cstdlib>
#include <string>
#include "list.h"

using namespace std;

//Constructor
List::List() {
    head = 0;
    current = 0;
    temp = 0;
}


//Destructor
List::~List() {
    current = head;

    //Steps through all nodes and deletes them if they exist
    while (current != 0) {
        temp = current;
        current = current -> next;
        delete temp;
    }
    
    head = 0;
    current = 0;
    temp = 0;
}


//Modification Member Functions
bool List::insert (const string data, const int value) {
    //Make sure a task with the same priority does not exist already
    temp = head;
    while (temp != 0) {
        if (temp -> prio == value) {
            return false;
        }
        temp = temp -> next;
    }
    temp = 0; 

    //Insert into the linked list
    if (head == 0) {
        head = new Node;
        head -> data = data;
        head -> prio = value;
        head -> next = 0;
        current = head;
    } else {
        temp = new Node;
        temp -> data = data;
        temp -> prio = value;
        temp -> next = current -> next;
        current -> next = temp;
        current = temp;
        temp = 0;
    }

    return true;
}

bool List::remove (const int value) {
    //Declare+initialize variables
    bool found = false;

    //No nodes in list
    if (head == 0) {
        found = false;
    //At least one node in list
    } else {
        //Find the node with the priority
        temp = head;
        while (temp != 0) {
            if (temp -> prio == value) {
                found = true;
                break;
            }
            temp = temp -> next;
        }

        if (found == true) {
            current = temp;
            temp = head;
            //If at the head, delete current and make the next node the head
            if (current == head) {
                if (head -> next != 0) {
                    head = head -> next;
                } else {
                    head = 0;
                }
                delete current;
            //Else, go through to find the previous node, then link around the current node. After delete the current node.
            } else {
                while (temp -> next != current) {
                    temp = temp -> next;
                }
                temp -> next = current -> next;
                delete current;
            }
        }
    }

    temp = 0;

    return found;
}

//Constant Member Functions
void List::search (void) {
    //Declare+initialize variables
    int lowestPrio = 0;

    //Find the node with the lowest priority
    temp = head;
    if (head != 0) {
        lowestPrio = head -> prio;
        current = temp;

        temp = temp -> next;
        while (temp != 0) {
            if (temp -> prio < lowestPrio) {
                lowestPrio = temp -> prio;
                current = temp;
            }
            temp = temp -> next;
        }

        //Display the information in the node
        cout << "\nDescription: " << current -> data << " \n";
        cout << "Priority: " << current -> prio << " \n";        
    } else {
        //No nodes in list
        cout << "\nWow... you have nothing to do! (or you haven't added anything) \n";
    }

}

//Overloaded Member Functions
ostream& operator << (ostream& outp, const List& right) {
    //Declare+initialize variables
    int count = 0;
    
    //No nodes in list
    if (right.head == 0) {
        outp << "Wow... you have nothing to do! (or you haven't added anything)";
    //At least one
    } else {
        Node* temp1 = right.head;
        
        cout << "Your Tasks:";
        while (temp1 != 0) {
            //Prints out data 
            cout << "\n\nDescription: " << temp1 -> data;
            cout << "\nPriority: " << temp1 -> prio;

            //Move to the next node
            temp1 = temp1 -> next;
        }

        temp1 = 0;
        delete temp1;
    }

    return outp;
}