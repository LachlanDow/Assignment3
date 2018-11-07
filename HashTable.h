#ifndef MY_HASH_TABLE
#define MY_HASH_TABLE

#include "HashNode.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

enum HashTableError { OUT_OF_MEMORY, KEY_NOT_FOUND, DUPLICATE_KEY }; // extend if necessary

typedef unsigned long ulint;

class HashTable {
  typedef vector <list<HashNode> > Table;
  Table *table; // size of table is stored in the Table data structure
  size_t num;   // number of entries in the HashTable;

public:
  HashTable();       // constructor, initializes table of size 1;
  HashTable(size_t); // constructor, requires size of table as arg
  ~HashTable();      // deconstructor

  size_t size(); // returns size of the hash table (number of buckets)
  size_t hash_function(ulint);  // the table's hash function
  ulint getValue(ulint);    // find and return data associated with key

  void insert(ulint,ulint); // insert data associated with key into table
  void erase(ulint);        // remove key and associated data from table

  void rehash(size_t); // sets a new size for the hash table, rehashes the hash table 

  // extend if necessary
};
 
 //intialises table to size of 1
 HashTable::HashTable(){
  cout << "constucting";
  this->table = new Table[1];
  this->num = 11;

  
  }  

  HashTable::HashTable(size_t number){
    cout << "constucting";
    this->table = new Table[number]; 
    this->num = 11;

    for (int i = 0; i < 11; i++) {
        this->table.at(i) = new HashNode;
        this->table.at(i)->value = NULL;
        this->table.at(i)->key = NULL;
    }
  }

  size_t HashTable::size(){
    return this->num;
  }

  HashTable::~HashTable(){
    delete this;
  }
/* Implement the 
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods 
*/

#endif
