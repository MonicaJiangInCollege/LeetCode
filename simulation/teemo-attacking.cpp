class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // 如果没有攻击，中毒时间为0
        if (timeSeries.empty()) return 0;
        
        int total = 0;  // 总中毒秒数
        
        // 遍历每一对相邻的攻击（除了最后一次攻击）
        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            int current = timeSeries[i];      // 当前攻击时刻
            int next = timeSeries[i + 1];     // 下一次攻击时刻
            int interval = next - current;    // 两次攻击的时间间隔
            
            // 如果间隔小于中毒持续时间，则当前攻击的中毒会被下一次攻击打断
            // 实际贡献的中毒时间就是间隔长度
            // 否则，当前攻击完整贡献 duration 秒
            if (interval < duration) {
                total += interval;
            } else {
                total += duration;
            }
        }
        
        // 最后一次攻击结束后没有下一次攻击，所以它的中毒效果完整持续 duration 秒
        total += duration;
        
        return total;
    }
};