//
// Created by steph on 3/3/2018.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H
#include "treeNode.h"
template <class element>
class tree {
public:
    tree(){ root= nullptr; }
    void insert( int value ) {
        if ( root == nullptr ) {
            root = new treeNode<element>( value );
        }
        else {
            root->insert( value );
        }
    }

    element find( element data ) {
        treeNode<element> *val = root->find( data );
        return val->getData();
    }

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
