class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // 构造 s + s，并去掉首尾字符
        string t = s + s;
        // substr(1, 2*n-2) 表示从索引1开始，取2*n-2个字符。
        // 也就是去掉原s+s的第一个字符和最后一个字符
        t = t.substr(1, 2 * n - 2); 
        // 如果 t 中包含 s，则说明 s 可以由重复子串构成
        return t.find(s) != string::npos;
        // 如果找到，返回第一次出现的位置索引；如果没找到，返回string::npos（一个很大的常数）
    }
};