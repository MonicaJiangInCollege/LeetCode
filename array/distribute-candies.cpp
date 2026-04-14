class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types(candyType.begin(), candyType.end());
        int n = candyType.size();
        return min((int)types.size(), n / 2);
    }
};