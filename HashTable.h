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

 //intialises table to size of  1
 inline HashTable::HashTable(){
  cout << "constucting"<< endl;
  Table *temp = new Table(11,list<HashNode>());
  this->table = temp;
  this->num = 0;

  }

inline  HashTable::HashTable(size_t number){
    cout << "constucting";
    Table *temp = new Table(number, list<HashNode>());
    this->table = temp;
    this->num = 0;

  }

  inline size_t HashTable::size(){
    return this->table->size();
  }

  inline HashTable::~HashTable(){
    delete this->table;
  }

  inline size_t HashTable::hash_function(ulint key){
    return key % this->table->size();
  }

  inline void HashTable::insert(ulint key ,ulint value){
     HashNode *temp = new HashNode(key,value);
     size_t pos = hash_function(key);
     list<HashNode> mylist= this->table->at(pos);

     for (list<HashNode>::iterator it=mylist.begin(); it != mylist.end(); ++it){
       if((*it).getKey() == key){
         throw DUPLICATE_KEY;
       }
     }
     this->table->at(pos).push_back(*temp);

  }

  inline ulint HashTable::getValue(ulint key ){
    size_t hashPos = hash_function(key);
    list<HashNode> mylist= this->table->at(hashPos);

    for (list<HashNode>::iterator it=mylist.begin(); it != mylist.end(); ++it){
      if((*it).getKey() == key){
        return (*it).getValue();
      }
  }
 return KEY_NOT_FOUND;
}
/* Implement the
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods
*/

#endif
