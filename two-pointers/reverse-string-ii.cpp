class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k) {
            // 确定反转的区间 [i, j)
            int left = i;
            int right = min(i + k, n); // 右边界不包含
            // 反转 [left, right)
            reverse(s.begin() + left, s.begin() + right);
        }
        return s;
    }
};