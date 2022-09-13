#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    // 优先队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> que;
        for (int i = 0; i < k; i++) {
            que.emplace(nums[i], i);  // emplace 会构造
        }
        vector<int> ans = {que.top().first};
        for (int i = k; i <n; i++) {
            que.emplace(nums[i], i); // 先入栈
            while(que.top().second <= i-k ) {
                que.pop();
            }
            ans.emplace_back(que.top().first);
        }
        return ans;
    }
    // 方法二 单调队列
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> que;
        for(int i = 0; i < k; i++) {
            while(!que.empty() && nums[i] >= nums[que.back()]) {  // 严格单调递减  ，最前面最大
                que.pop_back();
            }
            que.push_back(i);
        }
        vector<int> ans = {nums[que.front()]};
        for (int i = k; i < n; ++i) {
            // 先入队列：排除比当前元素小或者等于的 单调递减：去掉小于的和等于 单调递增去掉大于或者等于的
            while (!que.empty() && nums[i] >= nums[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);
            while (que.front() <= i - k) {
                que.pop_front();
            }
            ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};