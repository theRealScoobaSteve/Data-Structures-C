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

    treeNode<element> *find( element data ) {
        return root->find( data );
    }

private:
    treeNode<element> *root;
};

#endif //BINARYTREE_TREE_H
