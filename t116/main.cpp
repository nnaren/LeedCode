#include <iostream>
#include "Solution.h"

int main() {
    Node *root = new Node(1, new Node(2, new Node(4), new Node(5), nullptr), new Node(3, nullptr, new Node(7), nullptr) ,nullptr); 
    Solution sol;
    Node* ans = sol.connect(root);
    

    return 0;
}
