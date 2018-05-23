#include "tree.h"
#include <fstream>

void testFind( tree<string> * );
void testRemove( tree<string> * );
tree<string> *create();
void deleteTree( tree<string> * );

int main() {
    ofstream fout;
    fout.open( "output.txt" );
    try {
        tree<string> *tree = create();
        testFind( tree );
        testRemove( tree );
        deleteTree( tree );
        cout << "All tests passed";
    }
    catch( sameVal e ) {
        fout << "Can't pass 2 of the same values to this tree";
    }
    catch( emptyTree e ) {
        fout << "This tree is empty";
    }
    catch( string e ) {
        cout << e << endl;
    }
    catch( ... ) {
        fout << "Major Issues";
    }

    fout.close();

    return 0;
}

void testFind( tree<string> *tree ) {
    tree->find( "zonally");
    tree->find( "yell");
    tree->find( "image");
}

void testRemove( tree<string> *tree ) {
    tree->remove( "zonally" );
    tree->remove( "yell" );
    tree->remove( "image" );
}
tree<string> *create() {
    tree<string> *binaryTree = new tree<string>;
    string temp;
    ifstream fin;
    fin.open( "random.txt" );

    if( !fin ) {
        cout << "HERE";
        throw "Cant open file";
    }

    while( fin ) {
        getline( fin, temp );
        binaryTree->insert( temp );
    }

    fin.close();

    return binaryTree;
}
void deleteTree( tree<string> *tree ) {
    tree->deleteTree();
}