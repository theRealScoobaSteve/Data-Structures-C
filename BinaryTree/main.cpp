#include "tree.h"

int main() {
    tree<int> binaryTree;

    binaryTree.insert( 81 );
    binaryTree.insert( 91 );
    binaryTree.insert( 41 );
    binaryTree.insert( 51 );
    binaryTree.insert( 71 );
    binaryTree.insert( 1 );
    binaryTree.insert( 500 );
    binaryTree.insert( 434 );

    binaryTree.traverseInOrder();

    binaryTree.find( 92 );
    cout << endl << "91 was removed" << endl << endl;

    binaryTree.traverseInOrder();


    return 0;
}