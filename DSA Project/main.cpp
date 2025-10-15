
//for ref:
//hash table: apartment
// buckets: apartment floors
// elements: each room on floor

#include "hashTable.h"
#include <iostream>
using namespace std;

int main(){

    hashTable table(100007);

    table.loadDictionarytextFile("Dictionary.txt");
    cout << "\nDictionary loaded successfully!\n";
    table.displayStats();

    return 0;
}

