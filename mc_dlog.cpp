#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include "HashTable.h"


/* Implement mc_dlog in this file */

//intialises table to size of  1
 HashTable::HashTable(){
 cout << "constucting"<< endl;
 Table *temp = new Table(11,list<HashNode>());
 this->table = temp;
 this->num = 0;

 }

 HashTable::HashTable(size_t number){
   cout << "constucting";
   Table *temp = new Table(number, list<HashNode>());
   this->table = temp;
   this->num = 0;

 }

  size_t HashTable::size(){
   return this->table->size();
 }

HashTable::~HashTable(){
   delete this->table;
 }

size_t HashTable::hash_function(ulint key){
   return key % this->table->size();
 }

void HashTable::insert(ulint key ,ulint value){
  cout << "ins-1" << endl;
    HashNode temp(key,value);
    cout << "ins0" << endl;
    list<HashNode> *mylist;
    mylist = &(table->at(hash_function(key)));

    for (list<HashNode>::iterator it=mylist->begin(); it != mylist->end(); ++it){
      cout << "in bitch" << "it key is:"<<it->getKey() << "Key is:"<<key<< endl;
      if(it->getKey() == key){
        throw "Duplicate Key";
      }
    }
    cout << key << endl;
    mylist->push_back(temp);
    num++;
    if (9 * num >= 10 * size()) {
		rehash(8*size()+1); //+1 to make it a prime again
}
}

 ulint HashTable::getValue(ulint key ){
   size_t hashPos = hash_function(key);
   list<HashNode> mylist= this->table->at(hashPos);

   for (list<HashNode>::iterator it=mylist.begin(); it != mylist.end(); ++it){
     if(it->getKey() == key){
       return it->getValue();
     }
 }
  throw KEY_NOT_FOUND;
}

void HashTable::rehash(size_t newSize){
cout << "8====D11" << endl;
Table oldTable = *table;
cout << "8====D12" << endl;
table->clear();
cout << "8====D13" << endl;
table->resize(newSize);
cout << "8====D14" << endl;
  for(list<HashNode> &hash: oldTable){
    cout << "8====D15" << endl;
    for (HashNode &node : hash) {
      cout << "8====D16" << endl;
      cout << node.getKey() << endl;
      insert(node.getKey(), node.getValue());
  }
}

}

void HashTable::erase(ulint key){
cout << "erase" << endl;
size_t hashPos = hash_function(key);
   list<HashNode> *mylist;
   mylist = &(table->at(hashPos));


   list<HashNode>::iterator it;
   for ( it =mylist->begin(); it != mylist->end(); ++it){
    cout << "in iterator" << endl;
     if(it->getKey() == key){
      cout << it->getKey() << endl;
     mylist->erase(it);
     num--;
     return;
     }
 }
throw KEY_NOT_FOUND;

}
