Spell Checker – Hash Table & Linked List Implementation

A DSA project that implements a complete spell checker using a hash table with separate chaining (linked lists for collisions).  
It loads a dictionary, checks words in user input or files, identifies misspellings, and provides correction suggestions based on edit distance (Levenshtein).

> Built as a final project for Data Structures & Algorithms course.


Optional (provide custom dictionary)

The program expects Dictionary.txt or 10kdictionary.txt in the same directory.
You can rename your preferred dictionary file to Dictionary.txt.


Usage Example

Enter a sentence: Did you recieve my call
'recieve' is misspelled.
Did you mean: receive, relieve, retrieve


How It Works

1. Hash Table

· Array of buckets (size chosen based on dictionary size)
· Each bucket is a linked list of Node{string word, Node* next}
· Hash function: polynomial rolling hash modulo table size

2. Spell Checking

· Tokenize input by spaces and punctuation
· Lowercase each token
· Check existence in hash table (search())
· If not found then compute suggestions

3. Correction Suggestions

· For each misspelled word w, iterate over dictionary words d
· If abs(len(w) - len(d)) <= 2 then compute edit distance (Levenshtein)
· Keep top 3 words with smallest distance
· Remove duplicates before displaying

4. Optimizations

· Early length filter reduces edit distance calls by 80-90%
· Dictionary loaded once into memory → O(1) lookups
