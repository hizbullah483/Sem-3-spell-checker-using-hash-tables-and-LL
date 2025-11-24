#ifndef spellCheckerHeader
#define spellCheckerHeader

#include<vector>
#include<string>
#include "hashTable.h"
using namespace std;

class spellChecker{
    hashTable dict;  
    vector<string>dictWords;
    vector<string>misspelled;
    public:
    spellChecker(string dictionarytextFile);
    void checkSentence(const string &sentence);
    string lowerAndCleanWord(const string &word);
    bool checkWord(const string& word);
    int editdistance(const string & dictword, const string & misspelledWord);
    void loadDictinSpellChecker(const string &filename);
    void printRecommendedWords(vector<string> misspelled);
    void checkfile(const string &name);
};

#endif