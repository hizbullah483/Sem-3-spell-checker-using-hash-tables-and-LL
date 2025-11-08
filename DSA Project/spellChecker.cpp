#include<iostream>
#include<sstream>
#include<cctype>
#include<fstream>
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

int spellChecker::editdistance(const string &dictword ,const string& misspelledWord){
    int length1= dictword.length();
    int length2 =misspelledWord.length();
    int **editDistanceStorer = new int*[length1+1]; //+1 because of ""
    for(int i = 0; i < length1 + 1; i++)
        editDistanceStorer[i] = new int[length2+1];
    for(int i = 0; i <length1 + 1; i++) editDistanceStorer[i][0] = i;
    for(int j = 0; j <length2 + 1; j++) editDistanceStorer[0][j] = j;

    for(int i = 1; i < length1 + 1; i++){
        for(int j = 1; j < length2 + 1; j++){
            int cost = 1;
            if(dictword[i-1] == misspelledWord[j-1]) cost = 0;

            int insert = editDistanceStorer[i][j-1] + 1;
            int delet = editDistanceStorer[i-1][j] + 1;
            int substitute = editDistanceStorer[i-1][j-1] + cost;

            if(delet < insert && delet < substitute)
                editDistanceStorer[i][j] = delet;
            else if(insert < delet && insert < substitute)
                editDistanceStorer[i][j] = insert;  
            else
                editDistanceStorer[i][j] = substitute;
        }
    }
    int finalCost = editDistanceStorer[length1][length2];

    for(int i = 0; i < length1 + 1; i++) delete [] editDistanceStorer[i];
    delete [] editDistanceStorer;

    return finalCost;
}


void spellChecker::loadDictinSpellChecker(const string& filename){
    ifstream file(filename);
    string word;
    while(file >> word){
        string updatedWord = lowerAndCleanWord(word);
        dictWords.push_back(updatedWord);
    }
    file.close();
}

void spellChecker::checkSentence(const string &sentence){
    stringstream streamedSentence(sentence);
    string word;
    misspelled.clear();
    while(streamedSentence >> word){
        string updatedWord = lowerAndCleanWord(word);

        if(checkWord(updatedWord)) continue;
        //add misspelled word to the list
        misspelled.push_back(word);
    }
    if(misspelled.empty()){
        cout<<"no misspellings\n";
        return;
    }
    printRecommendedWords(misspelled);
}

void spellChecker::printRecommendedWords(vector<string> misspelled){
    cout<<"\nmisspelled words alongside their best recommendation\n ";
    for(int i = 0; i < misspelled.size(); i++){
        cout<<"\n"<<i+1<<") "<<misspelled[i]<<" -> ";
        string singleRecommendation = " no recommendations";
        int minDistance = 999;
        for(int j = 0; j < dictWords.size(); j++){
            int distance = editdistance(dictWords[j], misspelled[i]);
            if(distance < minDistance){
                singleRecommendation = dictWords[j];
                minDistance =  distance;
            }
        }
        cout<<singleRecommendation;
    }

    char choice;
    while(true){ 
        cout<<"\ndo you want to see more recommendations? y/n: ";
        cin>>choice;
        if(choice == 'n') break;
        int num;
        cout<<"for which word do you want to see recommendations for (enter number): ";
        cin>>num;

        if(num < 1 || num > misspelled.size()){
            cout<<"invalid number.\n";
            continue;
        }

        string moreRecommendationsForThisWord = misspelled[num - 1];
        int minDistance = 999;
        vector<string> recommendations;

        for(int i = 0; i < dictWords.size(); i++){
            int distance = editdistance(dictWords[i], moreRecommendationsForThisWord);
            if(distance < minDistance){
                recommendations.clear();
                recommendations.push_back(dictWords[i]);
                minDistance = distance;
            }
            else if(distance == minDistance)
                recommendations.push_back(dictWords[i]);
        }

        cout<<"More recommendations for "<<moreRecommendationsForThisWord<<": ";
        for(int i = 0; i < recommendations.size(); i++)
            cout<<recommendations[i]<<" ";
        cout<<"\n";
    }
}

