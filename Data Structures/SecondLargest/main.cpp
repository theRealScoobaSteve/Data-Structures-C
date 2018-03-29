#include <iostream>
using namespace std;

int secondLargest( int a[], int size ) {
    int currentMax = a[0];
    int secondMax=0;
    for( int i = 0; i< size; i++ ) {
        if ( a[i] >secondMax )
            secondMax = a[i];

        if ( a[i]>currentMax ){
            secondMax=currentMax;
            currentMax=a[i];
        }

        return secondMax;
    }
}
int main () {


    int a[10]={ 9,8,3,1,6,5,7,2,10,4 };
    cout << "The max of the array is :" << secondLargest( a,10 ) << endl;

    return 0;
}