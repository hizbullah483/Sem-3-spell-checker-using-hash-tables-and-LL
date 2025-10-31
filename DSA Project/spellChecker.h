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
    string lowerAndCleanWord(const string &word);
    bool checkWord(const string& word);
    int editdistance(const string & dictword, const string & misspelledWord);
    
};

#endif