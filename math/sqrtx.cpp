class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int right = x;
        int left = 1;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;  // 防止大数直接相加时溢出
            if ((long long)mid * mid < x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};