#include <iostream>
using namespace std;

// A queue is an ordered collection of items where the addition of new items happens at one end, called the “rear,” and the removal of existing items occurs at the other end, commonly called the “front.”

// Queue using Array

class Queue{

public:
    int front;
    int rear;
    int size;
    int* arr;

    // Constructor
    Queue(int s){
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // Push Operation
    void enqueue(int data){
        if (rear == size){
         cout<<"Queue Full"<<endl;   
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    // Pop Operation
     int dequeue(){
        if (isEmpty()){
          return -1;   
        }
        else {
            int ans = arr[front];
            arr[front] = -1;        // removed ko queue sai hta diya
            front++;

            // queue sai remove kiye hue space ko start s start krdiya
            if (rear == front){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }
    // Front Operation
    int peek(){
        if (front == rear){
         return -1;
        }
        else{
            return arr[front];
        }
    }
    // Empty Operation
    bool isEmpty(){
        if (front == rear){
            return true;
        } else
        {
            return false;
        }
    }

     void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "QUEUE ELEMENTS: ";
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};
int main(){
    
    Queue q(5) ;

    q.enqueue(5) ;
    q.enqueue(20) ;
    q.enqueue(30) ;
  
    cout << "Peek element is: " << q.peek() << endl ;
    q.display() ;

    q.dequeue();
    cout << "Peek element is: " << q.peek() << endl ;
    q.display() ;

    cout<< q.isEmpty() << endl;
}