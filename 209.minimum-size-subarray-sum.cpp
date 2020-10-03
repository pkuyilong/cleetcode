//
// Created by 麻艺龙 on 2020/10/3.
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int sum = nums[0];
        while (r < nums.size()) {
            if (sum >= s) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                l++;
            }
            else if (sum < s) {
                r++;
                if (r < nums.size()) {
                    sum += nums[r];
                }
            }
        }
        if (minLen == INT_MAX) {
            return 0;
        }
        return minLen;
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> ans({2,3,1,2,4,3});
    vector<int> ans( {2,16,14,15});
    int s = 20;
    int res = sol.minSubArrayLen(s, ans);
    cout << res << endl;

}

