#include "tree.h"
#include <fstream>

void testFind( tree<string> * );
void testRemove( tree<string> * );
tree<string> *create();
void deleteTree( tree<string> * );

int main() {
    ofstream fout;
    fout.open( "C:\\Users\\steph\\Desktop\\Data-Structures-C\\BinaryTree\\output.txt" );
    try {
        tree<string> *tree = create();
        testFind( tree );
        testRemove( tree );
        deleteTree( tree );
        fout << "All tests passed";
    }
    catch( sameVal ) {
        fout << "Can't pass 2 of the same values to this tree";
    }
    catch( emptyTree ) {
        fout << "This tree is empty";
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
    fin.open( "C:\\Users\\steph\\Desktop\\Data-Structures-C\\BinaryTree\\random.txt" );

    while( fin ) {
        getline( fin, temp );
        binaryTree->insert( temp );
    }

    binaryTree->traverseInOrder();

    fin.close();

    return binaryTree;
}
void deleteTree( tree<string> *tree ) {
    tree->deleteTree();
    tree->traverseInOrder();
}