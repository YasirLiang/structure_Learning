#include "hash_exe.h"
//#include <cmath>
#include <cassert>
#include <memory.h>
#include <stdlib.h>

Node ::Node( int key, const string &str ):key( key ), value( str ),next( 0 )
{
}

HashTable::HashTable()
{
    memset( nodes, 0, sizeof(Node*) * SIZE );
}

unsigned int HashTable::hasher( int key )
{
    // 最简单的hash函数
	return abs(key) % SIZE;
}

bool HashTable::Insert( int key, const std::string &value )
{
    uint32_t_ adr = hasher( key );
    Node * node = nodes[adr];
    if(node == 0)
    {
        nodes[adr] = new Node( key, value );
    }
    else
    {
        return Insert( &node->next, key, value );
    }
}

bool HashTable::Insert( Node** next, int key, const string& value )
{
    Node *node = *next;
    if( node == 0 )
    {
        (*next) = new Node( key, value );
        return true;
    }
    else
    {
        return Insert( &node->next, key, value );
    }
}

bool HashTable::Find( int key )
{
    uint32_t_ adr = hasher( key );
    Node *node = nodes[adr];
    if( node == 0 )
    {
        return false;
    }
    else
    {
        do
        {
            if( node->key == key )
            {
                return true;
            }
            else
            {
                node = node->next;
            }
        }while( node != 0 );

        return false;
    }
}

Node* HashTable::FindNode( int key )
{
    uint32_t_ adr = hasher( key );
    Node *node = nodes[adr];
    if(node != 0)
    {
        do
        {
            if( node->key == key )
            {
                return node;
            }
            else
            {
                node = node->next;
            }
        }while( node != 0);
    }

    return 0;
}

string & HashTable::operator[](int key )
{
    Node* node = FindNode( key );
    assert( node != 0 );

    return node->value;
}
