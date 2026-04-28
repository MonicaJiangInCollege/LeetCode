class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int len = flowerbed.size();
        for (int i = 0; i < len; ++i) {
            if (flowerbed[i] == 0) {
                // Check left and right (or boundaries)
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == len - 1) || (flowerbed[i + 1] == 0);
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // plant a flower
                    count++;
                    if (count >= n) return true;
                }
            }
        }
        return count >= n;
    }
};