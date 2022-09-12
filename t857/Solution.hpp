#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        // 找到根据性价比排序  以第 K个人的性价比来算平均工资（单位质量）
        // 排序显示的是人ID，按性价比从高到底排序
        vector<double> w_q (n);
        vector<int> name(n);

        iota(name.begin(), name.end(), 0);
        // 按性价比从高到底排序
        sort(name.begin(), name.end(), [&](int i, int j) {
                                        return wage[i] * quality[j] < wage[j] *quality[i];
                                        }
        );
        for(auto & n : name) {
            cout << n << endl;
        }

        // 前k-1位的总质量
        double res = 1e9;
        int total_q = 0;
        priority_queue<int, vector<int>, less<int>> pQue;
        // 需要一个性价比前k-1位质量排行
        for(int i = 0; i < k-1; i++) {
            total_q += quality[name[i]];
            pQue.push(quality[name[i]]);
        }

        for(int i = k-1; i<n;i++) {
            int name_ = name[i];
            total_q += quality[name_];
            double totalc = ((double) wage[name_] / quality[name_]) *total_q;
            res = min(res, totalc);
            pQue.push(quality[name_]); // 添加 第i位
            total_q -= pQue.top(); // 挤掉 第k-1位
            total_q.pop();
        }
        cout<< res <<endl;
        return res;
    }
};