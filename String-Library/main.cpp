#include "my_string.h"
#include <fstream>

inline ostream &operator<<( ostream &out, const my_string &str );
inline istream &operator>>( istream &in, const my_string &str );
my_string copyConstructorTest( my_string );
void testReverse( my_string s);
void testIndex( );
void arithmeticTest( );

int main() {

    try {
        my_string test = "Hello";
        copyConstructorTest(test);
        testReverse(test);
        arithmeticTest();
        testIndex();
    }
    catch( my_string::invalidIndex ) {
        cout << "Invalid index";
    }
    catch( my_string::invalidLength ) {
        cout << "Invalid length";
    }
    catch( my_string s ) {
        cout << s;
    }
    catch( ... ) {
        cout << "Well this isn't good at all.\n";
    }

    return 0;
}

// Constant
inline ostream &operator<<( ostream &out, const my_string &str ) {
    str.print( out );
    return out;
}

// Constant
inline istream &operator>>( istream &in, my_string &str) {
    str.read( in );
    return in;
}

my_string copyConstructorTest( my_string s ) {
    return s;
}

void testReverse( my_string s ) {

    cout << s.reverse( ) << endl;
}

void testIndex ( ) {
    my_string test = "Test String Test";

    if( test[0] != 'T')
        throw "The first letter is not correct!----error----";

    if( test.indexOf('T') != 0 )
        throw "Index returned is not correct!-----error----";

    if( test.indexOf( "String" ) != 5)
        throw "Index returned is not correct!-----error----";

}

void arithmeticTest( ) {
    my_string temp1 = "Hello";
    my_string temp2 = "World";
    my_string temp3;
    my_string temp4 = "Test";
    temp3 = temp1 + temp2;
    cout << "temp3: " << temp3 << endl;

    temp4 += temp3;

    cout << "temp4: " << temp4 << endl;


    if( temp3 == "HelloWorld")
        cout << "Works\n";
    else
        throw ("These values are not the same!---error----\n");

    if( temp1 == temp2)
        throw "These values are not the same!---error----\n";
}
