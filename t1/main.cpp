#include"Solution.hpp"

int main()
{
    vector<int> nums = {2,7,11,15} ;
    int target = 9;
    Solution slt;
    vector<int> res = slt.twoSumUseMap(nums, target);
    cout << res[0] << " and " << res[1]<<endl;
}