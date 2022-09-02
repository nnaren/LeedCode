#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    string word = "apple";
    string prefix = "app";
    Trie* obj = new Trie();
     obj->insert(word);
     bool param_2 = obj->search(word);
     bool param_3 = obj->startsWith(prefix);
    return 0;
}
