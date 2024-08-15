#include <iostream>
using namespace std;

    // 1
    // 2 2
    // 3 3 3 
    // 4 4 4 4

int main(){
    
    int n;
    cin >> n ;

    int i=1 ;
    while (i<=n) {

        int j=0 ;
        while(j<i){
            cout << i << " " ;
            j++ ;
        }
        cout << endl;
        i++ ;
    }
}