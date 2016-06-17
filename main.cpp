#include <iostream>
#include <string>
#include "hash_exe.h"

using namespace std;

int main( void )
{
    HashTable ht;

    ht.Insert( 1, "you" );
    string value = ht[1];
    cout << value << endl;

    ht.Insert( 101, "girl" );
    value = ht[101];
    cout << value << endl;

    ht.Insert( 201, "boy" );
    value = ht[201];
    cout << value << endl;

    ht[201] = "man";
    cout << ht[201] << endl;

    cin.get();

    return 0;
}
