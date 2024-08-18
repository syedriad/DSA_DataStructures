
#include <iostream>
using namespace std;

// A Circular Linked List (Circular LL) is a type of linked list where 
//the last node's next pointer points back to the first node, forming a circle. 
//This means there is no nullptr at the end of the list, unlike in a standard singly or doubly linked list.

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

int main(){

    
}