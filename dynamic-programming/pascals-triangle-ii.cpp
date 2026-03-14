class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1; // 第0行第一个元素
        for (int i = 1; i <= rowIndex; ++i) {
            // 从后往前更新，避免覆盖
            for (int j = i; j >= 1; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};