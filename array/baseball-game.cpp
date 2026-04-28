class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for (const string& op : operations) {
            if (op == "+") {
                int sum = scores[scores.size() - 1] + scores[scores.size() - 2];
                scores.push_back(sum);
            } else if (op == "D") {
                int doublePrev = scores.back() * 2;
                scores.push_back(doublePrev);
            } else if (op == "C") {
                scores.pop_back();
            } else {
                scores.push_back(stoi(op));
            }
        }
        int total = 0;
        for (int score : scores) {
            total += score;
        }
        return total;
    }
};