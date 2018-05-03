#include <iostream>
#include "fstream"
#include "Table.h"
#include <chrono>

using  ns = chrono::nanoseconds;
using get_time = chrono::steady_clock ;

void insertAll( const char *filename, ChainedHashTable &myTable );
void removeAll( const char *filename, ChainedHashTable myTable );
void findAll( const char *filename, ChainedHashTable myTable );

int main() {
    ofstream fout;

    double elapsed;

    Hasher *hash1 = new ProdHasher;
    Hasher *hash2 = new SumHasher;
    Hasher *hash3 = new GeneralStringHasher;
    Hasher *hash4 = new ShiftHasher;
    ChainedHashTable result(10,hash1);




    const char* FILE = "words.txt";
    fout.open( "HashTableView.txt" );

    for( int k = 1; k <= 10; k++ ) {
        ChainedHashTable myTable( k*4500,hash1 );
        clock_t start = clock();
        insertAll( FILE,myTable );
        findAll( FILE,myTable );
        removeAll( FILE,myTable );
        clock_t end = clock();
        elapsed = (double)( end - start ) / CLOCKS_PER_SEC;

        cout << "It took " << elapsed << " Second(s) to complete"
                " the functions 1 when K = " << k << endl << endl;
        result.duplicate( myTable );
    }



    for( int k = 1; k <= 10; k++ ) {
        ChainedHashTable myTable( k*4500,hash2 );
        clock_t start = clock();
        insertAll( FILE,myTable );
        findAll( FILE,myTable );
        removeAll( FILE,myTable );
        clock_t end = clock();
        elapsed = (double)( end - start ) / CLOCKS_PER_SEC;

        cout << "It took " << elapsed << " Second(s) to complete"
                " the functions 2 when K = " << k << endl << endl;
        result.duplicate( myTable );
    }


    for( int k = 1; k <= 10; k++ ) {
        ChainedHashTable myTable( k*4500,hash3 );
        clock_t start = clock();
        insertAll( FILE,myTable );
        findAll( FILE,myTable );
        removeAll( FILE,myTable );
        clock_t end = clock();
        elapsed = (double)( end - start ) / CLOCKS_PER_SEC;

        cout << "It took " << elapsed << " Second(s) to complete"
                " the functions 3 when K = " << k << endl << endl;
        result.duplicate( myTable );
    }



    for(int k = 1; k <= 10; k++) {
        ChainedHashTable myTable( k*4500,hash4 );
        clock_t start = clock();
        insertAll( FILE,myTable );
        findAll( FILE,myTable );
        removeAll( FILE,myTable );
        clock_t end = clock();
        elapsed = (double)( end - start ) / CLOCKS_PER_SEC;

        cout << "It took " << elapsed << " Second(s) to complete"
                " the functions 4 when K = " << k << endl << endl;
        result.duplicate( myTable );
    }

    fout << "The Resulting Hash Table Looks Like...\n";
    result.print( fout );

    fout.close();

    return 0;
}

void insertAll( const char *filename, ChainedHashTable &myTable ) {
    int i = 0;
    string value;
    ifstream fin;
    fin.open(filename);

    if(!fin)
        cout << "Didn't open file\n";

    while( fin >> value && i < myTable.getSize() ) {
        myTable.addNode(value);
        i++;
    }

    myTable.calcChainLength();
    cout << "Done inserting them all!\n";
    cout << "Max Chain is: " << myTable.getMaxChain() << endl;
    cout << "Min Chain is: " << myTable.getMinChain() << endl;
    fin.close();
}

void removeAll( const char *filename, ChainedHashTable myTable ) {

    int i = 0;
    string value;
    ifstream fin;
    fin.open(filename);

    if(!fin)
    {
        cout << "Didn't open file\n";
    }


    while(fin >> value  && i < myTable.getSize())
    {
        myTable.deleteNode(value);
        i++;
    }

    cout << "Done Removing Them All!\n";
}

void findAll( const char *filename, ChainedHashTable myTable ) {
    int i = 0;
    string value;
    ifstream fin;
    fin.open( filename );

    if( !fin )
        cout << "Didn't open file\n";


    while( fin >> value  && i < myTable.getSize() ) {
        myTable.findNode( value );
        i++;
    }

    cout << "Done Finding Them All!\n";
    fin.close();
}

