// https://leetcode.com/problems/letter-case-permutation/

void solve(string &ip, string &op, int idx, vector<string> &ans){
    if(idx == ip.size()){
        ans.push_back(op);
        return;
    }

    if(isalpha(ip[idx])){
        string op1 = op;
        op1.push_back(tolower(ip[idx]));

        string op2 = op;
        op2.push_back(toupper(ip[idx]));

        solve(ip, op1, idx+1, ans);
        solve(ip, op2, idx+1, ans);

    }else{
        op = op + ip[idx];
        solve(ip, op, idx+1, ans);
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    string op;

    solve(s, op, 0, ans);
    return ans; 
}