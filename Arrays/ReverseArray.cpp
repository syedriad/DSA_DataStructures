#include <iostream>
using namespace std;

// PROGRAM TO REVERSE AN ARRAY

void printArr(int a[], int size){
        
    cout << endl << "The reversed array:" << endl ;
    for (int j=0; j<size; j++){

        cout << a[j] << " " ;

    }
        cout << endl;
}

void reverse(int a[], int size){
    int start = 0;
    int end = size-1 ;
    
    //SWAP
    while (start < end){    // jab start ki value end s bari hojaye. for ex: [1,2,3,4,5] =>  start m 0th index means value 0 hai. or end m 4th index means value 4 hai, when the whole array is swapped tou zror start end s aagy barh jaye swap hoty hoty.

        int temp = a[start] ;
        a[start] = a[end] ;
        a[end] = temp ;

        start ++ ;
        end -- ;
    }
}


int main (){

    int arr[10] = {10,50,40,60,70,30,20,80,100,90} ;  //even
    int arr2[5] = {55,32,12,44,22} ;
    
    reverse(arr,10) ;
    printArr(arr,10) ;

    reverse(arr2, 5) ;
    printArr(arr2,5) ;

}