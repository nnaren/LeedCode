#include <iostream>
#include "Solution.hpp"

int main() {
    string s1 = "abc", s2 = "bca";
    Solution sol;
    cout << sol.kSimilarity(s1, s2) << endl;
    string s3 ="bccaba", s4 = "abacbc";
    cout << sol.kSimilarityDFS(s3, s4) << endl;
    return 0;
}
