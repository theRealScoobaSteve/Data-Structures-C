#include "arQueue.h"
#include "arStack.h"
#include "llQueue.h"
#include "llStack.h"
#include <fstream>

void fillAll( stack &list );
void fillAll( queue &list );
void emptyAll( ostream &fout, stack &list );
void emptyAll( ostream &fout, queue &list );

int main() {
    ofstream fout;

    fout.open( "C:\\Users\\steph\\Desktop\\Data-Structures-C\\Stacks-Queues\\output.txt" );

    arStack list1;
    llStack list2;

    fillAll( list1 );
    fillAll( list2 );
    fout << "Below is the output for the arStack!\n\n";
    emptyAll( fout, list1 );
    fout << "\nBelow is the output for the llStack!\n\n";
    emptyAll( fout, list2 );

    fout.close();

    return 0;
}

void fillAll( stack &list ) {
    ifstream inFile;
    string word;

    inFile.open( "C:\\Users\\steph\\Desktop\\Data-Structures-C\\Stacks-Queues\\words.txt" );

    if( !inFile )
        cout << "Error opening file.\n";

    while( getline( inFile, word ) ) {
        list.push( word );
    }

    inFile.close();
}

void emptyAll( ostream &fout, stack &list ) {
    while( !list.isEmpty() ) {
        fout << list.pop() << endl;
    }
}