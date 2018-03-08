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
        if( root )
            root->inOrder();
        else
            cout << endl << "Empty tree" << endl << endl;
    }

    void traversePreOrder() {
        if( root )
            root->preOrder();
        else
            cout << endl << "Empty tree" << endl << endl;
    }

    void traversePostOrder() {
        if ( root )
            root->postOrder();
        else
            cout << endl << "Empty tree" << endl << endl;
    }

    void deleteTree() {
        if ( root ) {
            root->deleteTree( root );
            delete root;
            root = nullptr;
        }
        else
            cout << endl << "Empty tree" << endl << endl;
    }

    ~tree() { deleteTree(); delete root; }

private:
    treeNode<element> *root;
};

#endif //BINARYTREE_TREE_H
