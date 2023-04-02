//Programming Club Code Jam Submission
//by Paul Shriner

/*
    Constructor:
    List()
        Description: Constructor will initialize List objects.
        Preconditions: none
        Postconditions: Head, current, and temp pointers are set to null.

    Copy Constructor:
    List(const List&)
        Description: Makes a copy of a List object.
        Preconditions: The object to be copied, passed by reference.
        Postconditions: None (this is not being used in this program).

    Destructor:
    ~List()
        Description: Performs cleanup when List objects are destroyed.
        Preconditions: none
        Postconditions: Nodes in the linked list are deleted, then the head, current, and temp pointers are set to null.
    
    Modification Member Functions:
    bool insert(const std::string, const int)
        Description: Inserts a node into the linked list.
        Preconditions: The data to be inserted.
        Postconditions: If list is empty, a head node is created. If a head node exists but nothing else, a node is created after head.
        If multiple nodes are in list, the node is placed next to current. The node has the data, and head/current pointers are updated appropriately.
        If the user attempts to insert a task with the same priority as one already inserted, the new task will not be inserted.

    bool remove(const int)
        Description: Removes the node with the specified priority.
        Preconditions: A priority value.
        Postconditions: If a node exists with the given priority, it will be removed.

    Constant Member Functions:
    void search(void)
        Description: Searches for the task with the lowest priority.
        Preconditions: none
        Postconditions: The information for the node with the lowest prio will be displayed. If the list is empty, an appropriate message will be displayed.

    Overloaded Operator Functions:
    friend std::ostream& operator << (std::ostream&, const List&)
        Description: Displays the data of the linked list implemented by a List object.
        Preconditions: The output stream and the list object.
        Postconditions: The tasks are printed to the console.
*/

#ifndef LIST_H
#define LIST_H

struct Node {
    std::string data;
    int prio;
    Node* next;
};

class List {
    public:
        //Constructor
        List();

        //Destructor
        ~List();

        //Modification Member Functions
        bool insert(const std::string, const int);
        bool remove(const int);

        //Constant Member Functions
        void search(void);

        //Overloaded Operator Functions
        friend std::ostream& operator << (std::ostream&, const List&);
        
    private:
        Node* head;
        Node* current;
        Node* temp;

        //Copy Constructor
        List(const List&);
};

#endif