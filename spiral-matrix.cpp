//
// Created by 麻艺龙 on 2020/10/2.
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }
        int l = 0;
        int u = 0;
        int d = matrix.size()-1;
        int r = matrix[0].size()-1;
        vector<int> ans;
        while (true) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[u][i]);
            }
            if (++u > d) {
                break;
            }

            for (int i = u; i <= d; i++) {
                ans.push_back(matrix[i][r]);
            }

            if (--r < l) {
                break;
            }
            // 要减掉最下边一列
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[d][i]);
            }
            if (--d < u) {
                break;
            }
            // 要减掉最左边一列
            for (int i = d; i >= u; i--) {
                ans.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }
        return ans;
    }
};