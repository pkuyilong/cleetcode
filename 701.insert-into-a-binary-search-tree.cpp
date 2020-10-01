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

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* root = new TreeNode(val);
            return root;
        }
        if (val < root->val) {
            // 犯的错误是 没有将新节点挂到树上
            // insertIntoBST(root->left, val);
            root->left = insertIntoBST(root->left, val);
        }
        else if (val >= root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};