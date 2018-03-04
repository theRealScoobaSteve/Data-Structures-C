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
    treeNode( element data ){ this->data=data; leftChild= nullptr; rightChild= nullptr; }

    void insert( int value ) {
        if ( value != data ) {
            if ( value < data ) {
                if (leftChild == nullptr) {
                    leftChild = new treeNode<element>( value );
                }
                else {
                    leftChild->insert( value );
                }
            }
            else {
                if ( rightChild == nullptr ) {
                    rightChild = new treeNode<element>( value );
                }
                else {
                    rightChild->insert( value );
                }
            }
        }
    }

    treeNode<element> *find( element data ) {
        if ( this == nullptr || this->data == data )
            return this;

        if (this->data < data)
            return this->rightChild->find( data );

        return this->leftChild->find( data );
    }

    element getData() const {
        return data;
    }

    void setData(element data) {
        treeNode::data = data;
    }

    treeNode *getRightChild() const {
        return rightChild;
    }

    void setRightChild(treeNode *rightChild) {
        treeNode::rightChild = rightChild;
    }

    treeNode *getLeftChild() const {
        return leftChild;
    }

    void setLeftChild(treeNode *leftChild) {
        treeNode::leftChild = leftChild;
    }

    ~treeNode(){ delete data; }

private:
    element  data;
    treeNode *rightChild;
    treeNode *leftChild;
};

#endif //BINARYTREE_TREENODE_H
