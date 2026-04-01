class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;   // num1 的指针，从末位开始
        int j = num2.size() - 1;   // num2 的指针，从末位开始
        int carry = 0;             // 进位，初始为 0
        string result = "";        // 存储结果（逆序）
        // 只要还有数字未处理或存在进位，就继续循环
        while (i >= 0 || j >= 0 || carry > 0) {
            // 获取当前位的数字，如果指针越界则取 0
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            int sum = digit1 + digit2 + carry;  // 当前位的和
            carry = sum / 10;                   // 更新进位
            result += (sum % 10) + '0';  // 当前位的数字转为字符，添加到结果末尾
            // 指针前移，处理更高位
            i--;
            j--;
        }
        // 由于我们是从低位向高位添加，结果字符串是逆序的，需要反转
        reverse(result.begin(), result.end());
        return result;
    }
};