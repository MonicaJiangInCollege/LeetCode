class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {
            columnNumber--;  // 转为0‑based，解决从1而不是0开始一一对应的问题
            int remainder = columnNumber % 26;   // 当前位的偏移
            result.push_back('A' + remainder);   // 添加到尾部
            columnNumber /= 26; // 进入下一轮
        }
        reverse(result.begin(), result.end());   // 逆序得到正确顺序
        return result;
    }
};