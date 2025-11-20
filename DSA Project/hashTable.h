#ifndef hashTableHeader
#define hashTableHeader

#include<vector>
#include<string>
using namespace std;

//watch inception to know how hash tables and vectors relate
struct Node{
    string word;
    Node *next;

    Node(string w){
        word = w;
        next = nullptr;
    }
};

class hashTable{
    vector<Node*> table; //each element is the start of the linked list (ptr yo head)
    int tableSize;

    public:
    vector<string> allWords;
    int hashFunction(const string &word);
    hashTable(int size = 131071);
    
    void insert(const string &word);
    bool search(const string &word);
    void loadDictionarytextFile(const string &filename);
    void displayStats();
    string lowerWord(const string &word);
    ~hashTable();

};

#endif
