
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
    h.displayStats();
    spellChecker s("Dictionary.txt");
    s.loadDictinSpellChecker("Dictionary.txt");
    cout<<"\nenter sentences. use STOP to terminate\n";
    string sentence;
    while (true){
        getline(cin, sentence);
        if(sentence.empty()) continue;
        if (sentence == "STOP") break;
        s.checkSentence(sentence);
    }
}

