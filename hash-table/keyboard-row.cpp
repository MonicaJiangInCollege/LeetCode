class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Define the three rows as strings for easy lookup
        const string row1 = "qwertyuiop";
        const string row2 = "asdfghjkl";
        const string row3 = "zxcvbnm";
        
        vector<string> result;
        
        for (const string& word : words) {
            // Convert word to lowercase for uniform checking
            string lower = word;
            for (char& c : lower) {
                c = tolower(c);
            }
            
            // Determine which row the first character belongs to
            int row = 0;
            if (row1.find(lower[0]) != string::npos) row = 1;
            else if (row2.find(lower[0]) != string::npos) row = 2;
            else if (row3.find(lower[0]) != string::npos) row = 3;
            
            // Check all characters belong to the same row
            bool valid = true;
            for (char c : lower) {
                if (row == 1 && row1.find(c) == string::npos) {
                    valid = false;
                    break;
                } else if (row == 2 && row2.find(c) == string::npos) {
                    valid = false;
                    break;
                } else if (row == 3 && row3.find(c) == string::npos) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};