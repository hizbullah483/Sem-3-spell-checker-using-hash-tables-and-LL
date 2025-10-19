
//for ref:
//hash table: apartment
// buckets: apartment floors
// elements: each room on floor

#include<iostream>
#include "spellChecker.h"
using namespace std;

int main(){
    hashTable table;
    table.loadDictionarytextFile("Dictionary.txt");
    cout<<table.search("appel");
}


