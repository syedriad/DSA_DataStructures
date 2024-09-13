#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) { // Constructor
        data = value;
        next = nullptr;
    }
};

// Queue using Linked List
class Queue {
public:
    Node* front; 
    Node* rear;

    Queue() { // Constructor
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int data) { // Enqueue Operation
        Node* newNode = new Node(data);
        if (rear == nullptr) { // If the queue is empty
            front = rear = newNode;
            return;
        }
        rear->next = newNode; // Link the new node at the rear
        rear = newNode; // Update rear to the new node
    }

    int dequeue() { // Dequeue Operation
        if (isEmpty()) { // If queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = front->data; // Store front data
        Node* temp = front; // Temporary pointer to the front
        front = front->next; // Move front to the next node

        if (front == nullptr) { // If queue becomes empty
            rear = nullptr;
        }
        delete temp; // Delete the old front
        return ans;
    }

    int peek() { // Peek Operation
        if (isEmpty()) { // If queue is empty
            return -1;
        }
        return front->data; // Return front data
    }

    bool isEmpty() { // Check if Queue is empty
        return front == nullptr;
    }

    void display() { // Display Queue
        if (isEmpty()) { // If queue is empty
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front; // Temporary pointer to traverse
        cout << "QUEUE ELEMENTS: ";
        while (temp != nullptr) { // Traverse till end
            cout << temp->data << " "; // Print data
            temp = temp->next; // Move to next node
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(5); // Enqueue 5
    q.enqueue(20); // Enqueue 20
    q.enqueue(30); // Enqueue 30

    cout << "Peek element is: " << q.peek() << endl; // Peek at front
    q.display(); // Display queue

    q.dequeue(); // Dequeue
    cout << "Peek element is: " << q.peek() << endl; // Peek at front
    q.display(); // Display queue

    cout << q.isEmpty() << endl;
