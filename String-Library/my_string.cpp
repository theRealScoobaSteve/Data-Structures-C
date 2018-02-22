//
// Created by Stephen on 2/1/2018.
//
#include "./my_string.h"

// Constant
my_string::my_string() {
    size = 0;
    str = new char[size];
}

// N
my_string::my_string( const char *s ) {
    int i = 0;
    while (s[i] != '\0')
        i++;

    size = i+1;
    str = new char[size];
    for( int i = 0; i < size; ++i )
        str[i] = s[i];
}

// N
my_string::my_string( const my_string &s ) {
    str = strdup(s.str);
    size = s.size;
    cout << "Copy constructor called!\n";
}
// Constant
my_string &my_string::operator=( const my_string &s ) {
    if (this != &s) {
        if (s.size != size) {
            delete[] str;
            size = s.size;
            str = new char[size];
        }
        for( int i = 0; i < size; ++i )
            str[i] = s.str[i];
    }
    return *this;
}

// N
char &my_string::operator[]( const int index ) {
    return str[index];
}

// N
int my_string::length() const {
    return size;
}


// N
int my_string::indexOf( const char c ) const {
    int count = 0;
    while( count < size ) {
        if( c == str[count] )
            return count;
        else
            count++;
    }
    return -1;
}

// N
int my_string::indexOf(const my_string &pat) const
{


    for(int i = 0; i < size - pat.size; ++i) {
        bool check = true;
        for (int j = 0; j < pat.size - 1; ++j)
        {
            if (str[i + j] != pat.str[j])
            {
                check = false;
                break;
            }
        }


        if (check == true)
        {
            return i;
        }
    }
    return -1;

}

// N
bool my_string::operator==( const my_string &s ) {
    if( !strcmp( *this, s ) )
        return false;

    return true;
}

// N
my_string my_string::operator+( const my_string &s ) {
    char *temp = strdup( s.str );
    return my_string( strcat( str, temp ) );
}

// N
my_string my_string::operator+=( const my_string &s ) {
    char *temp = strdup( str );
    size = size + s.size;
    delete str;
    str = new char[size];
    str = strcat( temp, s.str );

    return *this;
}

// N
my_string my_string::reverse() const{
    int j = 0;
    my_string temp;
    temp.size = size;
    temp.str = new char[size];

    for( int i = size-1; i >= 0; --i ) {
        temp.str[j] = str[i];
        j++;
    }

    return temp;
}

// N
void my_string::print( ostream &out ) const {
    for ( int i = 0; i < size; ++i ) {
        out << str[i];
    }
}

// Constant
void my_string::read(istream &in) {
    for( int i = 0; i < size; i++)
        in >> str[i];
}

// N
my_string::~my_string() {
    delete[] str;
}

// Constant
bool my_string::strcmp(const my_string first, const my_string second) const {
    int length1 = first.size;
    int length2 = second.size;

    if(length1 != length2)
        return false;
    else {
        for( int i = 0; i < length1; i++ ){
            if(first.str[i] != second.str[i])
                return false;
        }
    }

    return true;

}

// N
char *my_string::strcat(char *first, char *second)
{
    char *temp;
    char *word1 = first;
    char *word2 = second;
    int total = 0;

    total += strlen(first);
    total += strlen(second);

    temp = new char[total + 1];

    for(int i = 0; i <= strlen(first);++i)
    {
        temp[i] = first[i];
    }

    for(int i = strlen(first); i <= total; ++i)
    {
        temp[i] = second[i - strlen(first)];
    }

    return temp;
}

char *my_string::strdup(char *string) {
    int count = strlen( string );
    char *temp = new char[count + 1];

    for(int i = 0; i < count + 1; ++i) {
        temp[i] = string[i];
    }

    return temp;
}

int my_string::strlen( char *string ) const {
    int count = 0;
    char *temp = string;

    while( *temp != '\0' ) {
        temp++;
        count++;
    }

    return count;
}