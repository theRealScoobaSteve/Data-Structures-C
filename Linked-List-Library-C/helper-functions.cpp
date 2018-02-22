#include "./my_string.h"
#include "./node.h"
inline ostream &operator<<( ostream &out, const my_string &str );


// Constant
bool strcmp( my_string first, my_string second) {
    node *one = first.head;
    node *two = second.head;

    while( one != nullptr && two != nullptr ){
        if( one->letter != two->letter )
            return false;
        else {
            one = one->next;
            two = two->next;
        }
    }

    return true;
}

// N
my_string strcat(node *first, node *second) {
    node *temp1 = first;
    node *temp2 = second;
    my_string newString;
    node *tail = newString.head;
    node *newNode;

    while( temp1 != nullptr ) {
        newNode = new node;
        newNode->letter = temp1->letter;

        if( newString.head == nullptr) {
            newString .head = newNode;
        }
        else {
            tail->next = newNode;
        }

        tail = newNode;
        newNode->next = nullptr;
        temp1 = temp1->next;
    }

    while( temp2 != nullptr ) {
        newNode = new node;
        newNode->letter = temp2->letter;

        if( newString.head == nullptr) {
            newString.head = newNode;
        }
        else {
            tail->next = newNode;
        }

        tail = newNode;
        newNode->next = nullptr;
        temp2 = temp2->next;
    }

    return newString;
}

//node *strdup(my_string string) {
//    my_string temp;
//    node *sHead = string.head;
//
//    while( sHead != nullptr ) {
//        temp.add( sHead->letter );
//        sHead = sHead->next;
//    }
//
//    return temp.head;
//}



//// Constant
//inline istream &operator>>( istream &in, my_string &str) {
//    str.read( in );
//    return in;
//}