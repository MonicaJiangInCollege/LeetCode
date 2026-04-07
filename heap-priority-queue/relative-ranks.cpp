vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    // 1. 复制分数，然后降序排序
    vector<int> sortedScore = score;
    sort(sortedScore.begin(), sortedScore.end(), greater<int>());
    
    // 2. 建立 分数 -> 名次字符串 的映射
    unordered_map<int, string> rankMap;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            rankMap[sortedScore[i]] = "Gold Medal";
        } else if (i == 1) {
            rankMap[sortedScore[i]] = "Silver Medal";
        } else if (i == 2) {
            rankMap[sortedScore[i]] = "Bronze Medal";
        } else {
            rankMap[sortedScore[i]] = to_string(i + 1);  // 第4名 -> "4"
        }
    }
    
    // 3. 生成结果，保持原顺序
    vector<string> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = rankMap[score[i]];
    }
    return result;
}