#include <iostream>
using namespace std;

int main(){

    // NOT COMPLETED

    int arr[6] = {2,3,4,5,3,6} ;
    int dupli;

    for(int i=0; i<5; i++){

        
        for(int j=i+1; j<5; j++){
            
            if(arr[i] == arr[j]){
                dupli = arr[j] ;
            }
        }
    }

    cout << dupli ;

}