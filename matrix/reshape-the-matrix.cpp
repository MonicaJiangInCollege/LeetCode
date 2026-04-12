class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        // 如果元素总数不匹配，无法重塑，返回原矩阵
        if (m * n != r * c) return mat;
        
        // 创建新矩阵
        vector<vector<int>> reshaped(r, vector<int>(c));
        int idx = 0; // 用于计算新矩阵中的位置
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                reshaped[idx / c][idx % c] = mat[i][j];
                ++idx;
            }
        }
        return reshaped;
    }
};