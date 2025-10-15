#include "hashTable.h"
#include<iostream>
#include<fstream>
#include <cctype> // for tolower. if tolower works without this, remove it

using namespace std;

hashTable::hashTable(int size){ //for some reason cant do int size = 100007 here
    tableSize = size;
    table.resize(tableSize, nullptr);
}

//poly hash. only one i understood
int hashTable::hashFunction(const string &word){
    unsigned long hash = 0;
    int poly = 71;  //change to 31 or 37 if spread not good
    char ch;
    for(int i = 0; i < word.length(); i++){
        ch = word[i];
        hash = (hash * poly + tolower(ch)) % tableSize;
    }
    return hash;
}
//explaination:
//% tablesize prevents overflow. limited to size of table
// characters are added to contribute to final hash
//poly prevents ab and ba to have collision (same linked list)
//by effecting hash value based on order of chars



void hashTable::insert(const string &word){
    int index = hashFunction(word);
    Node *newNode = new Node(word);
    newNode->next = table[index]; 
    table[index] = newNode;
}
//explaination:
//remember how table stored heads of lists?
//we are basically doing newnode next = head, head = newnode

bool hashTable::search(const string &word){
    int index = hashFunction(word);
    Node *current = table[index];

    while(current != nullptr){
        if(current->word == word) return true;
        current = current->next;
    }
    return false;
}

void hashTable::loadDictionarytextFile(const string &filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout<<"\nfile not opened";
         return;
    }

    string word;
    while(file >> word){
        insert(word);
    }
    file.close();
}

void hashTable::displayStats(){
    int usefulBuckets = 0;
    int totalWords = 0;

    for(int i = 0; i < tableSize; i++){
        if(table[i] != nullptr){
            usefulBuckets++;
            Node *current = table[i];
            while(current){
                totalWords++;
                current = current->next;
            }
        }
    }

    cout<<"\ntotal words in table: "<<totalWords;
    cout<<"\ntotal buckets in use: "<<usefulBuckets;

}

hashTable::~hashTable(){
    for(int i = 0; i < tableSize; i++){ //go to every bucket (linked list) and delete all elements
        Node *current = table[i];
        while(current != nullptr){
            Node *toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
}