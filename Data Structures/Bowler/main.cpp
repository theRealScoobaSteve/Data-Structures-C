#include "bowler.h"

void sortList( bowler arr[], int n ) {
    int j;
    bowler temp;

    for ( int i = 0; i < n; i++ ){
        j = i;

        while ( j > 0 && arr[j] < arr[j-1] ){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main() {
    int count = 0;
    const int MAX = 25;
    bowler list[MAX];
    string val = "";
    bool done = false;

    while( !done ) {
        string first;
        string last;
        int    score1;
        int    score2;
        int    score3;
        double avg;

        cout << "bowler first name: ";
        getline( cin, first );
        cout << "bowler last name: ";
        getline( cin, last );
        cin.ignore( 100, '\n' );
        cout << "bowler score 1: ";
        cin  >> score1;
        cout << "bowler score 2: ";
        cin  >> score2;
        cout << "bowler score 3: ";
        cin  >> score3;

        avg = ( score1 + score2 + score3 ) / 3;
        bowler *temp = new bowler( first, last, score1, score2, score3, avg );

        cout << "continue( Y/N )? ";
        getline( cin, val );

        count++;

        if( val == "N")
            done = true;
        else
            done = false;
    }

    return 0;
}