class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 排序孩子的贪心因子和饼干尺寸
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int content = 0;
        // 双指针遍历
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // 当前饼干可以满足当前孩子
                content++;
                i++; // 处理下一个孩子
            }
            j++; // 无论是否满足，饼干指针都要后移（每个饼干只能用一次）
        }
        return content;
    }
};