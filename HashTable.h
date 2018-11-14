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
 //check if anything exists at hashtable position key
  void rehash(size_t); // sets a new size for the hash table, rehashes the hash table
  bool check(ulint);

  ulint order(int x, int n);
  ulint discrete(int x, int n, int a);
  ulint combine(int x, int n, int a);
  ulint intpow(ulint,ulint);

  // extend if necessary
};
inline HashTable::HashTable(){
Table *temp = new Table(11,list<HashNode>());
this->table = temp;
this->num = 0;

}

inline HashTable::HashTable(size_t number){
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
   HashNode temp(key,value);
   list<HashNode> *mylist;
   mylist = &(table->at(hash_function(key)));

   for (list<HashNode>::iterator it=mylist->begin(); it != mylist->end(); ++it){
     if(it->getKey() == key){
       throw "Duplicate Key";
     }
   }

   mylist->push_back(temp);
   num++;
   if (9 * num >= 10 * size()) {
   rehash(8*size()+1); //+1 to make it a prime again
}
}

inline ulint HashTable::getValue(ulint key ){
  size_t hashPos = hash_function(key);
  list<HashNode> mylist= this->table->at(hashPos);

  for (list<HashNode>::iterator it=mylist.begin(); it != mylist.end(); ++it){
    if(it->getKey() == key){
      return it->getValue();
    }
}
 throw KEY_NOT_FOUND;
}

inline void HashTable::rehash(size_t newSize){
Table oldTable = *table;
table->clear();
table->resize(newSize);
 for(list<HashNode> &hash: oldTable){

   for (HashNode &node : hash) {


     insert(node.getKey(), node.getValue());
 }
}

}

inline void HashTable::erase(ulint key){
size_t hashPos = hash_function(key);
  list<HashNode> *mylist;
  mylist = &(table->at(hashPos));


  list<HashNode>::iterator it;
  for ( it =mylist->begin(); it != mylist->end(); ++it){
    if(it->getKey() == key){
    mylist->erase(it);
    num--;
    return;
    }
}
throw KEY_NOT_FOUND;
}
inline bool HashTable::check(ulint key){

size_t hashPos = hash_function(key);
  list<HashNode> *mylist;
  mylist = &(table->at(hashPos));


  list<HashNode>::iterator it;
  for ( it =mylist->begin(); it != mylist->end(); ++it){
    if(it->getKey() == key){}
    return true;
    }
return false;
}



/* Implement the
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods
*/

#endif
