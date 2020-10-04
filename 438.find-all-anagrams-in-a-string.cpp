//
// Created by 麻艺龙 on 2020/10/4.
//

#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) {
            return {};
        }
        if (s == p) {
            return {0};
        }
        vector<int> ans;
        unordered_map<char, int> tmp;
        unordered_map<char, int> mp;
        int psize = p.size();
        for (int i = 0; i < psize; i++) {
            mp[p[i]]++;
        }


        for (int i = 0; i < s.size(); i++) {
            // 顺序很重要， 先将当前值考虑进去， 然后去掉可能已经废弃的数据
            tmp[s[i]]++;
            if (i >= psize) {
                if (tmp[s[i-psize]] == 1) {
                    tmp.erase(s[i-psize]);
                }
                else {
                    tmp[s[i-psize]]--;
                }
            }
            // 判断是不是相等
            if (tmp == mp) {
                ans.push_back(i-psize+1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();

}

