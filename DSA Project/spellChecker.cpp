#include<iostream>
#include<sstream>
#include<cctype>
#include "spellChecker.h"

using namespace std;

spellChecker::spellChecker(string dictionarytextFile){
    dict.loadDictionarytextFile(dictionarytextFile);
}

string spellChecker::lowerWord(const string &word){
    string updatedWord;
    for(int i = 0; i < word.length(); i++)
        updatedWord += tolower(word[i]);
    
    return updatedWord;
}

bool spellChecker::checkWord(const string &word){
    string updatedWord = lowerWord(word);
    return dict.search(updatedWord); //if true, no recommendation for that word
}

void spellChecker::checkSentence(const string &sentence){
    stringstream streamedSentence(sentence);
    string word;
    while(streamedSentence >> word){
        string updatedWord = lowerWord(word);

        if(checkWord(updatedWord)) continue;

        //add recommendations here
       
    }
}

