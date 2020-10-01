//
// Created by 麻艺龙 on 2020/10/1.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
  * 主要考虑缺少子树的情况，如果一棵树只有左子树，
  * 那么直接使用min(minDepth(root->left), minDepth(root->right)) + 1就只会返回1
  * 这很明显不符合要求，应该返回的是左子树的深度
  * 所以需要按情况讨论
  */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left && root->right) {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
        else if (!root->left) {
            return minDepth(root->right) + 1;
        }
        else {
            return minDepth(root->left) + 1;
        }
    }
};