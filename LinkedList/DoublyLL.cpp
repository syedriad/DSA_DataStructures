#include <iostream>
using namespace std ;

// Double linked list is a type of linked list in which each node contains three elements: 
// 1) Data: The value or information stored in the node. 
// 2) Next Pointer: A reference (pointer) to the next node in the list. 
// 3) Previous Pointer: A reference (pointer) to the previous node in the list.

class Node{
public:

    int d;
    Node* next ;
    Node* prev;

    Node(int data){

        this->d = data ;
        this->next = nullptr ;
        this->prev = nullptr ;
    }

    // deconstructor
    ~Node(){
        int deleted = this->d ;
        if (this->next != nullptr ){
            delete next ;
            this->next = nullptr ;
        }

        cout << "Memory is free from Node for the data " << deleted << endl;
    }
};

void insertAtHead(Node* &head,Node* &tail, int data){

    if(head == nullptr){

        Node* temp = new Node(data) ;
        head = temp ;
        tail = temp ;
    }
    else{

        Node* temp = new Node(data) ;
        temp->next = head ;
        head->prev = temp;
        head = temp ;

    }

}

void insertAtTail(Node* &tail,Node* &head, int data){

    if(tail == nullptr){

        Node* temp = new Node(data);
        tail = temp;
        head = temp ;
    }
    else{
        Node* temp = new Node (data) ;
        tail->next = temp ;
        temp->prev = tail ;
        tail = temp ;

    }

}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    if(position ==1){
        insertAtHead(head,tail,data) ;
        return ;   // so that won't go further [jtna mjh smjh aya]
    }

    Node* temp = head ;
    int cnt =1 ;

    while( cnt < position -1 ){
        temp = temp->next ;
        cnt ++ ;
    }

    // inserting at last posit
    if(temp->next == nullptr){
        insertAtTail(tail,head,data) ;
        return ;
    }

    Node* nodeToInsert = new Node(data) ;
    nodeToInsert->next = temp ->next ;
    temp->next->prev   = nodeToInsert ;
    temp->next         = nodeToInsert ;
    nodeToInsert->prev = temp ; 

}

void deleteNode(int position, Node* &head, Node* &tail ){

    if (position==1){
        Node* temp = head ;
        temp->next->prev = nullptr;
        head = temp->next ;

        //making the node free from memory  --Deconstructor
        temp->next = nullptr ;
        delete temp ;

    }
        // deleting any middle or last node
    else{

        Node* curr = head ;
        Node* prev = nullptr ;

        int cnt =1 ;
        while(cnt < position){
            prev = curr ;
            curr = curr->next ;
            cnt ++ ;
        }

        if (curr->next == nullptr) {
            tail = prev; // If curr is the last node
        } 
        else {
            curr->next->prev = prev; // If curr is a middle node
        }

        prev->next = curr->next;
        curr->next = nullptr;

        delete curr;


        // curr->prev = nullptr ;
        // prev->next = curr->next ;
        // curr ->next = nullptr ;

        // delete curr ;
    }
}


void printLL(Node* head){

    Node* temp = head ;
    cout << "Double LinkedList: " ;

    while(temp != nullptr){
        cout << temp->d << " " ;
        temp = temp->next ;
    }

    cout << endl ;
}

int getLength(Node* &head){
    int length = 0 ;
    Node* temp = head ;

    while (temp != nullptr) {
        length ++ ;
        temp = temp->next ;
    }
    return length ;
}

int main(){

    // Node* newNode = new Node(10) ;
    // Node* head = newNode ;     
    // Node* tail = newNode ;
    Node* head = nullptr ;
    Node* tail = nullptr ;

    // printLL(head) ;
    // cout <<  "Lenght is: " << getLength(head) ;

    insertAtHead(head,tail,4) ;
    printLL(head) ;


    insertAtHead(head,tail,14) ;
    printLL(head) ;


    insertAtTail(tail,head,45) ;
    insertAtTail(tail,head,30) ;
    printLL(head) ;


    insertAtPosition(head,tail,2,100) ;
    insertAtPosition(head,tail,1,90) ;
    insertAtPosition(head,tail,7,60) ;
    printLL(head) ;


    deleteNode(3,head,tail) ;
    printLL(head) ;

    cout <<  "Lenght is: " << getLength(head) ;


}