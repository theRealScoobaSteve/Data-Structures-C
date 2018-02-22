//
// Created by Stephen on 2/10/2018.
//
#include "./my_string.h"

// Constant
my_string::my_string() {
    head = nullptr;
}

// N
my_string::my_string( const char *s ) {
    node *ptr = new node;
    node *tail;
    head = nullptr;
    tail = head;
    int i = 0;

    while( s[i] != '\0' ) {
        ptr->letter = s[i];
        if( head == nullptr ) {
            head = ptr;
        }
        else {
            tail->next = ptr;
        }
        tail = ptr;
        ptr->next = nullptr;
        ptr = new node;
        i++;
    }
}

// N
my_string::my_string( const my_string &s ) {
    node *ptr = new node;
    node *tail;
    node *it = s.head;
    head = nullptr;
    tail = head;

    while( it != nullptr ) {
        ptr->letter = it->letter;
        if( head == nullptr ) {
            head = ptr;
        }
        else {
            tail->next = ptr;
        }
        tail = ptr;
        ptr->next = nullptr;
        ptr = new node;
        it = it->next;
    }
    cout << "Copy constructor called!\n";
}

// Constant
my_string &my_string::operator=( const my_string &s ) {
    my_string temp(s);
    return temp;
}

// N
char my_string::operator[]( const int index ) {
    node *temp = head;
    int i = 0;

    while( temp != nullptr ) {
        if( index == i )
            return temp->letter;
        else {
            i++;
            temp = temp->next;
        }
    }
}

// N
int my_string::length() const {
    int count = 0;
    node *temp = head;

    while( temp != nullptr ) {
        temp = temp->next;
        count++;
    }

    return count;
}

// N
int my_string::indexOf( const char c ) const {
    int count = 0;
    node *temp = head;
    while( temp != nullptr ) {
        if( c == temp->letter )
            return count;
        else {
            count++;
            temp = temp->next;
        }
    }
    return -1;
}

// N
int my_string::indexOf( const my_string &pat ) const {
    my_string temp = *this;
    my_string temp2 = pat;

    for(int i = 0; i < this->length() - pat.length() + 1; ++i) {
        bool check = true;
        for ( int j = 0; j < pat.length(); ++j ) {
            if ( temp[i + j] != temp2[j] ) {
                check = false;
                break;
            }
        }

        if ( check ) {
            return i;
        }
    }
    return -1;
}

// N
bool my_string::operator==( const my_string &s ) {
    if( strcmp( *this, s ) )
        return true;

    return false;
}

// N
my_string my_string::operator+( const my_string &s ) {
    node *temp = s.head;
    return strcat( head, temp );
}

// N
my_string &my_string::operator+=( const my_string &s ) {
    *this = *this + s;
    return *this;
}

// N
my_string my_string::reverse() {
    my_string temp;
    node *value = new node;
    node *tail = temp.head;

    int length = this->length();
    for(int i = length; i > 0; --i) {
        value->letter = (*this)[i-1];
        if(temp.head == nullptr) {
            temp.head = value;
        }
        else {
            tail->next = value;
        }
        value->next = nullptr;
        tail = value;
        value = new node;
    }

    return temp;
}

// N
void my_string::print( ostream &out ) const{
    node *temp = head;
    while( temp != nullptr ) {
        cout << temp->letter;
        temp = temp->next;
    }
}

// N
void my_string::clear() {
    node * temp;
    while( head != nullptr ) {
        temp = head;
        head = temp->next;
        delete temp;
    }

    head = nullptr;
    temp = nullptr;
}

// N
my_string::~my_string() {
    clear();
}

