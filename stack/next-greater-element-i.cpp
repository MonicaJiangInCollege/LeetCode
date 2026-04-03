class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // 存储每个元素的下一个更大元素
        stack<int> st; // 单调递减栈
        // 遍历 nums2，计算每个元素的下一个更大元素
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        // 栈中剩余元素没有下一个更大元素
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        // 构造结果数组
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};