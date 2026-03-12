class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        // 1. 将 n 转换为二进制字符串（不含前导零）
        string binary = "";
        int temp = n;
        while (temp > 0) {
            binary = (temp % 2 == 0 ? "0" : "1") + binary;
            temp /= 2;
        }
        
        // 2. 翻转每一位
        for (char &c : binary) {
            c = (c == '0') ? '1' : '0';
        }
        
        // 3. 将翻转后的二进制字符串转回整数
        int result = 0;
        for (char c : binary) {
            result = result * 2 + (c - '0');
        }
        
        return result;
    }
};