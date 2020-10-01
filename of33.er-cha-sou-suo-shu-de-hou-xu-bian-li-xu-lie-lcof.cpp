//
// Created by 麻艺龙 on 2020/10/1.
//

/*
 * 思路
 * 由于后序遍历是左右根，并且这颗树是二叉搜索树， 根节点左边的节点的值都比根节点的值小，根节点右边的节点的值都比根节点的值要大
 * 所以序列的最有一个节点的值就是最初的根节点的值，之前的值就是就是左节点和右节点的值，需要用一个游标去进行划分，一般情况下，
 * 会有一部分数字比A小（左子树的节点），之后的数字都比A大（右子树的节点，然后进行递归处理
 *
 */

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size()-1);
    }
    bool helper(vector<int>& postorder, int i, int j) {
        if (i >= j) {
            return true;
        }
        int p = i;
        int pivot = postorder[j];
        while (postorder[p] < pivot) {
            p++;
        }
        int m = p;
        while (postorder[p] > pivot) {
            p++;
        }
        if (p == j) {
            return helper(postorder, i, m-1) && helper(postorder, m, j-1);
        }
        return false;
    }
};