# Sem-3-spell-checker-using-hash-tables-and-LL

COPY PASTE THIS INTO TERMINAL FOR EXECUTION

g++ main.cpp hashTable.cpp spellChecker.cpp -o main

./main

FEATURES IMPLEMENTED:

dictionary loaded into hash tables

collisions handled via linked lists

functions that can take whole sentences 

false negative prevention by using tolower and isalpha

edit distance function which acts as core mechanic for recommendation feature

a recommendation feature for misspelled words (do you mean: ...) 

UPDATES

1.got rid of dupes in recommendation

2.can now process whole files too

3. massive optimization by ignoring dict words with length > 2 of the misspelled word



