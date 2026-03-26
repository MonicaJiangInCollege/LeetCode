// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            // 防止溢出：如果直接 (left+right)/2，可能超出 int 范围
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                // mid 是坏的，第一个坏版本在 [left, mid] 中
                right = mid;
            } else {
                // mid 是好的，第一个坏版本在 [mid+1, right] 中
                left = mid + 1;
            }
        }
        return left;   // 或者 return right，此时 left == right
    }
};