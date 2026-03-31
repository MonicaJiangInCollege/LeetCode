char findTheDifference(string s, string t) {
    int cnt[26] = {0};
    for (char c : t) cnt[c - 'a']++;
    for (char c : s) cnt[c - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) return 'a' + i;
    }
    return ' ';
}