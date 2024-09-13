#include <iostream>
using namespace std;

// singly linkedList is a data structure containing a node
// node consist of two parts: a data value and a pointer-> containg the address of the next node.

class Node {
public:
    int d;         // Data stored in the node
    Node* next;    // Pointer to the next node in the list

    Node(int data) {
        this->d = data;   // Initialize node with given data
        this->next = nullptr;  // Initially, the next pointer is null
    }

    // Destructor
    ~Node(){

        int deleted = this->d ;
        if(this->next != nullptr){
            delete next ;
            this->next  = nullptr ;
        }

        cout << "Memory is free for node for data " << deleted <<endl ;
    }
};

void insertFromHead(Node* &head, int D) {

    Node* newNode = new Node(D);  // Create a new node with given data
    newNode->next = head;         // Link the new node to the current head
    head = newNode;               // Update the head to be the new node
}

void insertFromTail(Node* &tail, int D) {
    Node* newNode = new Node(D);  // Create a new node with given data
    tail->next = newNode;         // Link the current tail to the new node
    tail = tail->next ;           // tail = newNode    // Update the tail to be the new node
}

void insertAtPosition(Node* &head,Node* &tail, int position, int D){

    if(position ==1){
        insertFromHead(head,D) ;
        return ;
    }
    
    Node* temp = head ;
    int count =1 ;


    while (count < position-1) {
        temp =  temp->next ;
        count ++ ;
    }

    if(temp->next == nullptr){
        insertFromTail(tail,D);
        return;
    }

    Node* nodeToInsert = new Node(D) ;
    nodeToInsert ->next = temp ->next ;

    temp ->next = nodeToInsert ;

}

void deleteNode(int position, Node* &head, Node* &tail ){

    // for deleting the first node

    if (position == 1){
        Node* temp = head ;
        head= head ->next ;
        
        // making the memory free, from first node.  [DECONSTRUCTOR]
        temp->next = nullptr ;
        delete temp ; 
    }

    else{
        // for deleting the node in any position [middle] or [last]

        Node* curr = head ;
        Node* prev = nullptr ;

        int count = 1;
        // traverse towards the curr , that is to be deleted
        while (count < position) {
            prev = curr ;
            curr = curr->next ;
            count ++ ;
        }

        if (curr-> next == nullptr){     // to handle tail, if last node is to be deleted.
            tail = prev ;
        }


        prev->next = curr->next ;
        curr->next = nullptr ;
        delete curr ;

    }
}


void print(Node* head) {
    Node* current = head;  // Start from the head of the list

    cout << "Linked List: ";

    if (current == nullptr) {    // Check if the list is empty
        cout << "LinkedList is empty";
    }

    while (current != nullptr) { // Traverse the list
        cout << current->d << " "; // Print the data in each node
        current = current->next;   // Move to the next node
    }
    cout << endl;
}

int main() {
    // Create the first node with data 10
    Node* node = new Node(10);

    // Set head and tail to point to this first node
    Node* head = node;
    Node* tail = node;

    print(tail);  // Print the current list (only 10 at this point)

    // Insert nodes at the head (51 and 15 will be before 10)
    insertFromHead(head, 51); // List is now: 51 -> 10
    insertFromHead(head, 15); // List is now: 15 -> 51 -> 10

    // Insert nodes at the tail (20 and 30 will be after 10)
    insertFromTail(tail, 20); // List is now: 15 -> 51 -> 10 -> 20
    insertFromTail(tail, 30); // List is now: 15 -> 51 -> 10 -> 20 -> 30

    insertAtPosition(head,tail,6,40) ;

    deleteNode(6,head,tail) ;
    deleteNode(1,head,tail) ;

    print(head);  // Print the final linked list

    cout << tail ->d <<endl;
    // cout << tail ->d <<endl;
}
