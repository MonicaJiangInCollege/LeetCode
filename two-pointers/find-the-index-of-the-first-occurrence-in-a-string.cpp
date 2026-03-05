class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) 
            return 0;
        if (m > n) 
            return -1;

        // 1. 构建前缀函数（next数组）
        vector<int> next(m, 0);  // 创建初始长度为m的vector，初始值均为0
        for (int i = 1, j = 0; i < m; i++) {  // i用于遍历模式串，j用于记录已匹配的前缀长度
            while (j > 0 && needle[i] != needle[j])
                j = next[j - 1];
            if (needle[i] == needle[j])
                j++;
            next[i] = j;
        }

        // 2. KMP匹配
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == m)
                return i - m + 1;       // 匹配成功，返回起始下标
        }
        return -1;
    }
};