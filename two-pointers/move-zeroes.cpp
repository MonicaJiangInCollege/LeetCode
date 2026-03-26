class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroPos = 0;                     // 1. 初始化指针，指向下一个非零元素要放的位置
        
        // 2. 第一遍扫描：移动非零元素
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {                 // 如果当前元素不是零
                nums[nonZeroPos++] = nums[i];   // 将它放到 nonZeroPos 位置，并后移 nonZeroPos
            }
        }
        
        // 3. 第二遍扫描：填充零
        for (int i = nonZeroPos; i < nums.size(); ++i) {
            nums[i] = 0;                        // 将剩余位置全部置为 0
        }
    }
};