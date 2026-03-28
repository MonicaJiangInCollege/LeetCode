/*摩尔投票算法:抵消策略---将数组中任意两个不同的元素配对，互相“抵消”，
那么最后剩下的元素（或之一）就有可能是多数元素。
因为多数元素的数量大于其他元素的总和，所以经过抵消后，它一定会被保留下来。*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            }
            else {
                count--;
            }
        }
        return candidate;
    }
};