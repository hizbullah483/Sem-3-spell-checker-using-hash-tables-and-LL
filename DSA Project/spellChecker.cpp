#include<iostream>
#include<sstream>
#include<cctype>
#include "spellChecker.h"

using namespace std;

spellChecker::spellChecker(string dictionarytextFile){
    dict.loadDictionarytextFile(dictionarytextFile);
}

string spellChecker::lowerAndCleanWord(const string &word){
    string updatedWord;
    for(int i = 0; i < word.length(); i++){
        if(isalpha(word[i])) updatedWord += tolower(word[i]);
    }
    
    return updatedWord;
}

bool spellChecker::checkWord(const string &word){
    string updatedWord = lowerAndCleanWord(word);
    return dict.search(updatedWord); //if true, no recommendation for that word
}

void spellChecker::checkSentence(const string &sentence){
    stringstream streamedSentence(sentence);
    string word;
    while(streamedSentence >> word){
        string updatedWord = lowerAndCleanWord(word);

        if(checkWord(updatedWord)) continue;

        //add recommendations here
       
    }
}

