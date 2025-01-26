// https://leetcode.com/problems/palindrome-partitioning/

bool isPalindrome(string &s, int start, int end){
    while(start<= end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve(int start, string &s, vector<string> &op, vector<vector<string>> &ans){
    if(start == s.size()){
        ans.push_back(op);
        return;
    }

    for(int i=start;i<s.size();i++){
        if(isPalindrome(s, start, i)){
            op.push_back(s.substr(start, i-start+1));
            solve(i+1, s, op, ans);
            op.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> op;

    solve(0, s, op, ans);

    return ans;
}