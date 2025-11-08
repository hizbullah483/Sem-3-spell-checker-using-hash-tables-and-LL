
//for ref:
//hash table: apartment
// buckets: apartment floors
// elements: each room on floor

#include<iostream>
#include "spellChecker.h"

using namespace std;

int main(){
    hashTable h;
    h.loadDictionarytextFile("Dictionary.txt");
    spellChecker s("Dictionary.txt");
    cout<<"enter sentences. use STOP to terminate\n";
    string sentence;
    cin>>sentence;
    while(sentence != "STOP"){
        s.checkSentence(sentence);
        cin>>sentence;
    }
}

