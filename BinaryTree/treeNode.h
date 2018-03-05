//
// Created by steph on 3/3/2018.
//

#ifndef BINARYTREE_TREENODE_H
#define BINARYTREE_TREENODE_H

#include <string>
#include <iostream>
using namespace std;

template <class element>
class treeNode {
public:
    // Constructor
    treeNode( element data ){ this->data=data; leftChild= nullptr; rightChild= nullptr; }

    element getData() const {
        return data;
    }

    void setData(element data) {
        treeNode::data = data;
    }

    void insert( int value ) {
        // Check for duplicate
        if ( value != data ) {
            // Determine which side of tree to insert
            if ( value < data ) {
                // If empty your done add it right there
                if (leftChild == nullptr) {
                    leftChild = new treeNode<element>( value );
                }
                    // Or traverse left again
                else {
                    leftChild->insert( value );
                }
            }
                // Values greater so check right side
            else {
                // Insert if right child is empty
                if ( rightChild == nullptr ) {
                    rightChild = new treeNode<element>( value );
                }
                    // Not empty so traverse right
                else {
                    rightChild->insert( value );
                }
            }
        }
    }

    treeNode<element> *find( element data ) {
        // If empty or data is root return
        if ( this == nullptr || this->data == data )
            return this;

        // Traverse left if current child less than the search
        if (this->data < data)
            return this->rightChild->find( data );

        // Traverse right if current child greater than the search
        return this->leftChild->find( data );
    }

    treeNode<element> *remove( treeNode<element> *node, element value ) {
        // Tree is empty
        if( this == nullptr ) {
            return this;
        }

        // If the value is to the left traverse left and replace the left child with a lower value
        if( value < node->data ) {
            node->leftChild = node->leftChild->remove( node->leftChild, value );
        }
        // If the value is to the right traverse right and replace the right child with a higher value
        else {
            node->rightChild = node->rightChild->remove( node->rightChild, value );
        }

        if( value == node->data ) {
            // Cases 0 and 1: node to delete has 0 or 1 child(ren)
            if( node->leftChild == nullptr ) {
                return node->rightChild;
            }

            if( node->rightChild == nullptr ){
                return node->leftChild;
            }
            // Case 3: node to delete has 2 children
            // Replaces the node with smallest value from the right subtree
            node->data = node->rightChild->min();
            // Delete the node that had the smallest value in the right subtree
            node->rightChild = node->remove( node->rightChild, node->data );
        }

        return node;
    }

    // Finds the minimum value in the tree
    int min() {
        // Min found
        if ( leftChild == nullptr ) {
            return data;
        }
        // Traverse left
        else {
            return leftChild->min();
        }
    }

    // Finds the max value of the tree
    int max() {
        // Max found
        if ( rightChild == nullptr ) {
            return data;
        }
        // Keep traversing right
        else {
            return rightChild->max();
        }
    }

    void inOrder() {
        if (leftChild != nullptr) {
            leftChild->inOrder();
        }
        cout << data << endl;
        if (rightChild != nullptr) {
            rightChild->inOrder();
        }
    }

    void preOrder() {
        cout << data << endl;
        if (leftChild != nullptr) {
            leftChild->inOrder();
        }
        if (rightChild != nullptr) {
            rightChild->inOrder();
        }
    }

    void postOrder() {
        if (leftChild != nullptr) {
            leftChild->inOrder();
        }
        if (rightChild != nullptr) {
            rightChild->inOrder();
        }
        cout << data << endl;
    }

    ~treeNode(){ delete data; delete rightChild; delete leftChild; }
private:
    element  data;
    treeNode<element> *rightChild;
    treeNode<element> *leftChild;
};

#endif //BINARYTREE_TREENODE_H
