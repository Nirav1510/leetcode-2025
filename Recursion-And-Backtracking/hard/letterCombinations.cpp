// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

void solve(int idx, string &digits, string &curr, vector<string> &ans, unordered_map<char, string> &digitMap){
    if (idx == digits.size()) {
        ans.push_back(curr); 
        return;
    }

    char currDigit = digits[idx];
    for (char letter : digitMap[currDigit]) { 
        curr.push_back(letter);               
        solve(idx + 1, digits, curr, ans, digitMap); 
        curr.pop_back();                      
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.size() == 0) return {};

    unordered_map<char, string> digitMap = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    string curr;
    vector<string> ans;
    solve(0, digits, curr, ans, digitMap);
    return ans;
}