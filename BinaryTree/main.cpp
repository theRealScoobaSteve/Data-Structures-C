#include "tree.h"
#include <fstream>

bool testFind( tree<string> * );
bool testRemove( tree<string> * );
tree<string> *create();
bool deleteTree( tree<string> * );

int main() {
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

    return 0;
}

bool testFind( tree<string> *tree ) {
    if( tree->find( "zonally") )
        return true;

    return false;
}

bool testRemove( tree<string> *tree ) {
    tree->remove( "zonally" );
    return true;
}
//tree<string> *create();
//bool deleteTree();