#include <iostream>
using namespace std ;

// Stack is a linear data structure that holds a linear, ordered sequence pf elements. A Stack works on
// LIFO process (Last in , First Out) i.e: the element that was inserted last , will be removed first. 

class Stack{

    // properties
public:
    int top ;
    int *arr ;
    int size ;



    //behaviours
    Stack(int s){
        this->top = -1 ;
        this->arr = new int[s] ;
        this->size = s ;
    }

    void push(int value){
        
        // check if there's space available

        if(size - top > 1){         // agar 5 size ka array and 4 filled hen,mtlb 5-4 =1 means condition true
            top ++ ;
            arr[top] = value ;
        }
        else{
            cout << "Stack overflow -no space is available. " ;
        }
    }

    void pop(){

        if(top >= 0){
            top -- ;
        }
        else{
            cout << "Stack underflow -no element present in the stack" ;
        }
    }

    int peek(){                // this peek function returns the top element in the stack
        if(top >= 0){
            return arr[top] ;
        }
        else{
            return -1 ;
        }
    }

    bool isEmpty(){
        if (top == -1){
            return true ;
        }
        else{
            return false ;
        }
    }



};

int main (){

    // Stack st = new Stack (5) ;     it doesnot work in c++ i guess

    Stack st(5)  ;

    st.push(3);
    st.push(8);
    st.push(11);

    int ans = st.peek() ;
    cout << ans << endl;

    st.pop() ;
    cout << st.peek() << endl;
    st.pop() ;
    cout << st.peek() << endl;


    st.pop() ;
    cout << st.peek() << endl;   // will return -1 b/c stack became empty

    // st.pop() ;
    st.isEmpty() ;
    cout << st.top ;
 
    
}