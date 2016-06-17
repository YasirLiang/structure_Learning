#ifndef __HASH_EXE_H__
#define __HASH_EXE_H__

//#pragma once
#include <string>
using std::string;

typedef unsigned int uint32_t_;

class Node
{
	public:
		Node( int key, const string & str );
		int key;
		string value;
		Node *next;
};

class HashTable
{
	public:
		HashTable( );

		bool Insert( int key, const string & value );
		bool Find( int key );
		string& operator[]( int key );
	
	private:
		bool Insert( Node** node, int key, const string& value);
		Node* FindNode( int key );
		unsigned int hasher( int key );

		enum{ SIZE = 100 };
		Node* nodes[SIZE];
};

#endif
