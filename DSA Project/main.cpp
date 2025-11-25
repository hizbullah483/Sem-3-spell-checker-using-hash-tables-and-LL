
//for ref:
//hash table: apartment
// buckets: apartment floors
// elements: each room on floor

#include <iostream>
#include "spellChecker.h"

using namespace std;

int main() {
    hashTable h;
    h.loadDictionarytextFile("Dictionary.txt");
    h.displayStats();
    spellChecker s("Dictionary.txt");
    s.loadDictinSpellChecker("Dictionary.txt");

    while (true){
        cout << "\n1 Terminal spell checking\n";
        cout << "2 File spell checking\n";
        cout<<"3 to exit\n";

        int choice;
        cin >> choice;
        cin.ignore(); 

        if (choice == 1){
            cout << "\nEnter sentences. Use STOP to terminate\n";
            string sentence;
            while (true){
                getline(cin, sentence);
                if (sentence.empty()) continue;
                if (sentence == "STOP") break;
                s.checkSentence(sentence);
            }
        } 
        else if(choice == 2){
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            cin.ignore(); 
            s.checkfile(filename);
        } 
        else if(choice == 3){
            cout << "terminated\n";
            break;
        } 
        else{
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
