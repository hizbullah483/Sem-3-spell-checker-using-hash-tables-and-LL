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

int spellChecker::editdistance(const string & dictword, const string & misspelledWord){
    int length1 = dictword.length();
    int length2 = misspelledWord.length();
    int **editDistanceStorer = new int*[length1 + 1]; //+1 because of ""
    for(int i = 0; i < length1 + 1; i++)
        editDistanceStorer[i] = new int[length2 + 1];
    for(int i = 0; i < length1 + 1; i++) editDistanceStorer[i][0] = i;
    for(int j = 0; j<length2 +1; j++) editDistanceStorer[0][j] = j;

    for(int i = 1; i < length1 + 1; i++){
        for(int j = 1; j < length2 + 1; j++){
            int cost;
            if(dictword[i - 1] == misspelledWord[j - 1]){
                cost = 0; 
            }
            else{cost = 1;}
            //now we perform one of three operations. delete, insert or swap
            int insert = editDistanceStorer[i][j - 1]+ 1;
            int delet = editDistanceStorer[i - 1][j]+ 1;
            int substitute = editDistanceStorer[i - 1][j - 1]+ cost;
            //which one is better?
            if(delet < insert && delet < substitute)
                editDistanceStorer[i][j] = delet;
            else if(insert > delet && insert > substitute)
                editDistanceStorer[i][j] = insert;  
            else{
                editDistanceStorer[i][j] = substitute;
            }      
        }

        int finalCost = editDistanceStorer[length1][length2];
        for(int i = 0; i < length1 +1; i++) delete [] editDistanceStorer[i];
        delete[] editDistanceStorer;
        return finalCost;
    }

    
}

void spellChecker::checkSentence(const string &sentence){
    stringstream streamedSentence(sentence);
    string word;
    while(streamedSentence >> word){
        string updatedWord = lowerAndCleanWord(word);

        if(checkWord(updatedWord)) continue;

        else{cout<<"\n"<<word<<" not found\n";}
        //add recommendations here
       
    }
}

