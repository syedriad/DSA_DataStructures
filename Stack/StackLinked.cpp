#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;       // Holds the value of the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = nullptr; // Initially, the next pointer is set to null
    }
};

// Stack class using linked list


class Stack {

    Node* top;      // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr; // Initially, the stack is empty, so top is null
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        // If the stack is empty, the new node becomes the top node
        
        if (top == nullptr) {
            top = newNode;
        } else {
            // If the stack is not empty, link the new node to the current top node
            newNode->next = top;
            // Update the top to the new node
            top = newNode;
        }
        cout << "Pushed " << value << " onto the stack." << endl;
    }


    // Function to pop (remove) the top element from the stack

    void pop() {
        // Check if the stack is empty
        if (top == nullptr) {
            cout << "Stack underflow - no element present in the stack." << endl;
            return; // Nothing to pop
        }
        // Store the current top node in a temporary pointer
        Node* temp = top;
        // Move the top pointer to the next node
        top = top->next;
        // Delete the old top node to free memory
        delete temp;
        cout << "Popped element from the stack." << endl;
    }

    // Function to get the top element of the stack without removing it
    int peek() {
        // Check if the stack is empty
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1; // Return a sentinel value indicating the stack is empty
        }
        // Return the data of the top node
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        // If top is null, the stack is empty
        return top == nullptr;
    }
};

int main() {
    Stack st; // Create a stack

    st.push(10); // Push 10 onto the stack
    st.push(20); // Push 20 onto the stack
    st.push(30); // Push 30 onto the stack

    cout << "Top element is: " << st.peek() << endl; // Get and print the top element


    return 0;
}
