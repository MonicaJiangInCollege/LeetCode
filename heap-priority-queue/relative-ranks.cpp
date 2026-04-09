class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        // 复制分数并排序（降序）
        vector<int> sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        
        // 建立分数到排名的映射
        unordered_map<int, string> rankMap;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                rankMap[sortedScore[i]] = "Gold Medal";
            } else if (i == 1) {
                rankMap[sortedScore[i]] = "Silver Medal";
            } else if (i == 2) {
                rankMap[sortedScore[i]] = "Bronze Medal";
            } else {
                rankMap[sortedScore[i]] = to_string(i + 1);
            }
        }
        
        // 生成结果数组
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = rankMap[score[i]];
        }
        return result;
    }
};