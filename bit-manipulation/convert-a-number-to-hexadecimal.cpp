class Solution {
public:
    string toHex(int num) {
        // 处理特殊情况：num 为 0 时直接返回 "0"
        if (num == 0) return "0";
        // 十六进制字符映射表（小写）
        string hexChars = "0123456789abcdef";
        string result = "";
        // 将 int 转为 unsigned int，以得到其二进制补码表示
        unsigned int n = static_cast<unsigned int>(num);
        // 每次取低 4 位，转换为十六进制字符，然后右移 4 位
        while (n != 0) {
            int digit = n%16;          // 取低 4 位（0-15）
            result = hexChars[digit] + result; // 将字符拼接到结果字符串的前面
            n >>= 4;                      // 右移 4 位，处理下一个 4 位组
        }
        return result;
    }
};