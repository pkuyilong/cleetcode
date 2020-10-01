//
// Created by 麻艺龙 on 2020/10/1.
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
 * 思路
 * 求最大深度的升级版，没什么不同
 */
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        for (int i = 0; i < root->children.size(); i++) {
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};

