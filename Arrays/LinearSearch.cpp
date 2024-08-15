// In computer science, linear search or sequential search is a method for finding an element within a list. It sequentially checks each element of the list until a match is found or the whole list has been searched.


#include <iostream>
using namespace std;

int main(){

    int arr[10] = {10,50,40,60,70,30,20,80,100,90} ;
    
    int key;

    cout << "Enter the element to seach in an array"  << endl ;
    cin >> key ;

    int found = -1 ;
    int position;

    for(int i = 0 ; i<10; i++){
        if (arr[i] == key ){
            
            found = 1 ;
            position = i ;
        }   
    }

    if (found == -1){
    cout << "key is not found"  ;

    }else{

    cout << "key has found, at " << position << "th index"  ;
    }
    return 0 ;

}