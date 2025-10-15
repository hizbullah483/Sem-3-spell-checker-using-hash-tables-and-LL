#ifndef spellCheckerHeader
#define spellCheckerHeader

#include<vector>
#include<string>
#include "hashTable.h"
using namespace std;

class spellChecker{
    hashTable dict;  

    public:
    spellChecker(string dictionarytextFile);
    void checkSentence(const string &sentence);
    string lowerWord(const string &word);
    bool checkWord(const string& word);
};

#endif