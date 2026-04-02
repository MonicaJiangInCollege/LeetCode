class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        // 1. 去除破折号并转为大写
        string clean;
        for (char c : s) {
            if (c != '-') {
                clean += toupper(c);
            }
        }
        // 2. 从后向前每 k 个字符插入一个破折号
        string result;
        int n = clean.size();
        int count = 0;
        for (int i = n - 1; i >= 0; --i) {
            result += clean[i];
            count++;
            if (count % k == 0 && i != 0) {
                result += '-';
            }
        }
        // 3. 反转得到正确顺序
        reverse(result.begin(), result.end());
        return result;
    }
};