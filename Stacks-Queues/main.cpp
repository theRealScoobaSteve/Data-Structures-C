#include "arQueue.h"
#include "arStack.h"
#include "llQueue.h"
#include "llStack.h"
#include <fstream>

void fillAll( stack &list );
void fillAll( queue &list );
void emptyAll( ostream &fout, stack &list );
void emptyAll( ostream &fout, queue &list );
void isBalanced( string text );

int main() {
    ofstream fout;

    fout.open( "C:\\Users\\steph\\Desktop\\Data-Structures-C\\Stacks-Queues\\output.txt" );

    arStack list1;
    llStack list2;
    arQueue list3;
    llQueue list4;

    fillAll( list1 );
    fillAll( list2 );
    fillAll( list3 );
    fillAll( list4 );

    fout << "Below is the output for the arStack!\n\n";
    emptyAll( fout, list1 );
    fout << "\nBelow is the output for the llStack!\n\n";
    emptyAll( fout, list2 );
    fout << "\nBelow is the output for the arQueue!\n\n";
    emptyAll( fout, list3 );
    fout << "\nBelow is the output for the llQueue!\n\n";
    emptyAll( fout, list4 );

    fout.close();

    isBalanced( "({(())})((([({})])))(((((()([{()}])(()))))))()" );
    cout << endl;
    isBalanced( "({(())})((([({})])))(((((()([{()}])(())))))" );
    cout << endl;
    isBalanced( "({(())})((([({})])))(((((()([{()}])(()))))))()])" );

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

void fillAll( queue &list ) {
    ifstream inFile;
    string word;

    inFile.open( "C:\\Users\\steph\\Desktop\\Data-Structures-C\\Stacks-Queues\\words.txt" );

    if( !inFile )
        cout << "Error opening file.\n";

    while( getline( inFile, word ) ) {
        list.enq( word );
    }

    inFile.close();
}

void emptyAll( ostream &fout, stack &list ) {
    while( !list.isEmpty() ) {
        fout << list.pop() << endl;
    }
}

void emptyAll( ostream &fout, queue &list ) {
    while( !list.isEmpty() ) {
        fout << list.deq() << endl;
    }
}

void isBalanced( string text ) {
    llStack paranList;
    llStack frenchList;
    llStack brackList;
    bool poppedEmptyList = false;
    int length = text.length();

    for( int i = 0; i < length; ++i ) {
        if( text[i] == '(' ) {
            paranList.push("(");
        }
        if( text[i] == ')' ) {
            if( !paranList.isEmpty() )
                paranList.pop();
            else
                poppedEmptyList = true;
        }
        if( text[i] == '{' ) {
            frenchList.push("{");
        }
        if( text[i] == '}' ) {
            if( !frenchList.isEmpty() )
                frenchList.pop();
            else
                poppedEmptyList = true;
        }
        if( text[i] == '[' ) {
            brackList.push("[");
        }
        if( text[i] == ']' ) {
            if( !brackList.isEmpty() )
                brackList.pop();
            else
                poppedEmptyList = true;
        }
    }

    cout << "The string " << text;

    if( paranList.isEmpty() && frenchList.isEmpty() && brackList.isEmpty() && !poppedEmptyList )
        cout << " is balanced!\n";
    else
        cout << " is not balanced!\n";
}