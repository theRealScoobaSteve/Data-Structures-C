//
// Created by steph on 4/30/2018.
//

#ifndef CHAINEDHASHTABLE_TABLE_H
#define CHAINEDHASHTABLE_TABLE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
using namespace std;

struct ListNode{
    string key;
    int count;
    bool isEmpty;
};
// an abstract struct to parent your various hasher classes
struct Hasher {
    virtual int hash ( string s , int N ) = 0;

};

// your first working hashing class
struct GeneralStringHasher : Hasher {
    int hash ( string key , int N ){
        unsigned hashVal = 0;
        for ( int i = 0; i < key . size (); i ++)
            hashVal = (127 * hashVal + key [i]) % 16908799;
        return hashVal % N ;
    }
};

struct ShiftHasher: Hasher {
    int hash ( string key , int N )
    {
        const unsigned shift = 6;
        const unsigned zero = 0;
        unsigned mask = ~zero >> (32 - shift); // low 6 bits on
        unsigned result = 0;
        for (int i = 0; i < key.size(); i++)
            result = (result << shift) | (key[i] & mask);
        return result % N;
    }

};

// A rough idea of these Hashers - //
// some modifications may be needed //
struct SumHasher : Hasher {
    int hash ( string s , int N ) {
        int result = 0;
        for ( int i =0; i < s . size (); ++ i )
            result += s [ i ];
        return abs ( result ) % N ;
    }

};
struct ProdHasher : Hasher {
    int hash ( string s , int N ) {
        int result = 1;
        for ( int i =0; i < s . size (); ++ i )
            result *= s [ i ];
        return abs ( result ) % N ;
    }
};


class ChainedHashTable {
public:
    ChainedHashTable( int capacity, Hasher *myHasher ) {
        size = capacity;
        table = new list<ListNode>[capacity];
        myHash =  myHasher;
        minChain = 0;
        maxChain = 0;

    }

    ChainedHashTable( const ChainedHashTable &temp ) {
        this->size = temp.size;
        this->myHash = temp.myHash;
        this->minChain = temp.minChain;
        this->maxChain = temp.maxChain;

        this->table = new list<ListNode>[size];

        ListNode *node;

        for ( int i = 0; i < temp.size; i++ ) {

            for (ListNode x : temp.table[i]) {
                node = new ListNode;
                node->key = x.key;
                node->isEmpty = false;
                node->count = 1;
                this->table[i].push_back( *node );
            }

        }
    }

    void duplicate( const ChainedHashTable &temp ) {
        this->size = temp.size;
        this->myHash = temp.myHash;
        this->minChain = temp.minChain;
        this->maxChain = temp.maxChain;

        this->table = new list<ListNode>[size];

        ListNode *node;

        for (int i = 0; i < temp.size; i++) {
            for (ListNode x : temp.table[i]){
                node = new ListNode;
                node->key = x.key;
                node->isEmpty = false;
                node->count = 1;
                this->table[i].push_back(*node);
            }

        }
    }

    //O(constant)
    void addNode( string value ) {
        ListNode temp;
        temp.key = value;
        temp.isEmpty = false;
        temp.count = 1;
        int index;

        index = myHash->hash( value,size );
        table[index].push_back( temp );
    }


    //O(N)
    void deleteNode( string value ) {

        list<ListNode> :: iterator i;
        int index;
        index = myHash->hash(value,size);

        for ( i = table[index].begin(); i != table[index].end(); i++ ) {
            if( i->key == value )
                break;

        }

        if (i != table[index].end())
            table[index].erase(i);


    }

//O(N)
    string findNode( string value ) {

        list<ListNode> :: iterator i;
        int index;
        index = myHash->hash(value,size);

        for ( i = table[index].begin(); i != table[index].end(); i++ ) {
            if( i->key == value)
                break;

        }

        if (i != table[index].end())
            return i->key;

    }


    //O(N)
    void print( ostream &out ) {
        for ( int i = 0; i < size; i++ ) {
            out << i;
            for (ListNode x : table[i]) {
                out << " --> " << x.key;
            }

            out << endl;
        }
    }

    void calcChainLength() {
        int count;
        for (int i = 0; i < size; i++) {
            count = 0;

            for (ListNode x : table[i]) {
                count++;
                if(count > maxChain)
                    maxChain = count;
            }
        }
    }

    int getMinChain() const {
        return minChain;
    }

    int getMaxChain() const {
        return maxChain;
    }

    int getSize() const {
        return size;
    }

private:
    Hasher *myHash;
    list<ListNode> *table;
    int size;
    int minChain;
    int maxChain;
};
#endif //CHAINEDHASHTABLE_TABLE_H
