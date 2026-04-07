class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        bool negative = false;
        if (num < 0) {
            negative = true;
            num = -num;
        }
        
        string result;
        while (num > 0) {
            int remainder = num % 7;
            result.push_back('0' + remainder);  // 数字转字符
            num /= 7;
        }
        
        // 因为余数是从低位到高位收集的，需要反转
        reverse(result.begin(), result.end());
        
        if (negative) {
            result = "-" + result;
        }
        
        return result;
    }
};