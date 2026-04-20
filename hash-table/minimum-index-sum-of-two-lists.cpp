class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        for (int i = 0; i < list1.size(); ++i) {
            indexMap[list1[i]] = i;
        }
        
        vector<string> result;
        int minSum = INT_MAX;
        
        for (int j = 0; j < list2.size(); ++j) {
            const string& s = list2[j];
            if (indexMap.find(s) != indexMap.end()) {
                int sum = indexMap[s] + j;
                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(s);
                } else if (sum == minSum) {
                    result.push_back(s);
                }
            }
        }
        return result;
    }
};