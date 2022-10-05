#include <iostream>
#include "Solution.hpp"
#include "../show.hpp"
int main() {
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    Solution sol;
    auto ans = sol.subdomainVisits(cpdomains);
    show(ans);
    return 0;
}
