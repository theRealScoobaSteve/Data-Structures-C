//
// Created by steph on 3/3/2018.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H
#include "treeNode.h"
template <class element>
class tree {
public:
    // Constructor
    tree(){ root= nullptr; }

    // Inserts nodes into the tree
    void insert( element value ) {
        // If empty this value is the root
        if ( root == nullptr ) {
            root = new treeNode<element>( value );
        }
        // Else traverse tree and find correct spot
        else {
            root->insert( value );
        }
    }

    // Searches for a value in the tree
    bool find( element data ) {
        treeNode<element> *val = root->find( data );
        if( val == nullptr )
            return false;
        return true;
    }

    // Removes values from the tree
    void remove( element data ) {
        root = root->remove( root, data );
    }

    void traverseInOrder() {
        root->inOrder();
    }

    void traversePreOrder() {
        root->preOrder();
    }

    void traversePostOrder() {
        root->postOrder();
    }

private:
    treeNode<element> *root;
};

#endif //BINARYTREE_TREE_H
