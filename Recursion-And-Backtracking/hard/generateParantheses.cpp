void solve(int open, int close, string &op, vector<string> &ans){
    if(open == 0 && close == 0){
        ans.push_back(op);
        return;
    }
    
    if(open != 0){
        string op1 = op + '(';
        solve(open-1, close, op1, ans);
    }
    
    if(close > open){
        string op2 = op + ')';
        solve(open, close-1, op2, ans);
    }
    return;
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string op;
    
    solve(n, n, op, ans);
    return ans;
}
