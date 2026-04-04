vector<string> findWords(vector<string>& words) {
    const string row1 = "qwertyuiop";
    const string row2 = "asdfghjkl";
    const string row3 = "zxcvbnm";
    
    vector<string> result;  // 存放符合条件的单词
    
    for (const string& word : words) {   // 遍历每个单词
        string lower = word;
        for (char& c : lower) c = tolower(c);   // 转小写
        
        int row = 0;
        // 确定第一个字母属于哪一行
        if (row1.find(lower[0]) != string::npos) row = 1;
        else if (row2.find(lower[0]) != string::npos) row = 2;
        else if (row3.find(lower[0]) != string::npos) row = 3;
        
        bool valid = true;
        // 检查所有字母是否都在同一行
        for (char c : lower) {
            if (row == 1 && row1.find(c) == string::npos) { valid = false; break; }
            if (row == 2 && row2.find(c) == string::npos) { valid = false; break; }
            if (row == 3 && row3.find(c) == string::npos) { valid = false; break; }
        }
        
        if (valid) result.push_back(word);   // 满足条件则加入原单词
    }
    return result;
}