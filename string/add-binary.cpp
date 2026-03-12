class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int length_a = a.size();
        int length_b = b.size();

        int carry = 0; // 进位
        int i = length_a - 1;
        int j = length_b - 1;

        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            carry = sum / 2;
            result += sum % 2 + '0';
        }

        reverse(result.begin(), result.end()); // 因为是先追加低位，后追加高位，所以结果需要反转
        return result;
    }
};