#include "tree.h"

int main() {
    tree<int> binaryTree;

    binaryTree.insert( 91 );
    binaryTree.insert( 81 );
    binaryTree.insert( 71 );
    binaryTree.insert( 61 );
    binaryTree.insert( 51 );
    binaryTree.insert( 41 );

    binaryTree.find( 91 );

    return 0;
}