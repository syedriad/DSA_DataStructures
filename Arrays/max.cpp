#include <iostream>
using namespace std;


void printArr(int a[], int size){
    for(int k=0; k<size; k++){
        cout << a[k] << endl ; 
    }
    cout << "loop done" ;
}

int main(){

    //maximum element in an array

    int arr[6] = {12,15,19,11,10,5};

    int max = arr[0] ;
    for (int i = 0; i<6; i++){
        if (arr[i] > max){
            max = arr[i] ;
        }        
    }
    cout << max <<endl ;

    // take input in an array
    int arr2[5] = {} ;
    for (int j =0; j< 5; j++){
        cin >> arr2[j] ; 
    }
    printArr(arr2, 5) ;
    return 0 ;
}