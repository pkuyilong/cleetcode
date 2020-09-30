//
// Created by 麻艺龙 on 2020/9/30.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
核心思路就是前序遍历的反向思路
前序遍历  根左右
后序遍历  左右根 反向之后就是   根右左， 思路等同于前序遍历， 只不过把左右方向调换一下就可以，然后reverse就是后序遍历了
*/

#include<vector>
#include<stack>

using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                ans.push_back(cur->val);
                cur = cur->right;
            }
            TreeNode* node = stk.top();
            cur = node->left;
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};