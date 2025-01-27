// https://leetcode.com/problems/word-break/

bool solve(int start, string &s, unordered_set<string> &wordSet, vector<int> &memo) {
    if (start == s.size()) {
        return true; 
    }

    if (memo[start] != -1) {
        return memo[start]; 
    }

    string word;
    for (int i = start; i < s.size(); i++) {
        word += s[i];
        if (wordSet.count(word) && solve(i + 1, s, wordSet, memo)) {
            return memo[start] = true; 
        }
    }
    return memo[start] = false; 
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<int> memo(s.size(), -1);
    return solve(0, s, wordSet, memo);
}