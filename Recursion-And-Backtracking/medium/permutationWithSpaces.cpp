// https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1

void solve(vector<string> &ans, string &ip, string &op, int idx){
    if(idx == ip.size()){
        ans.push_back(op);
        return;
    }
    
    // include
    string op1 = op + ' ' + ip[idx];
    solve(ans, ip, op1, idx+1);
    
    // exclude
    string op2 = op + ip[idx];
    solve(ans, ip, op2, idx+1);
}

vector<string> permutation(string s) {
    vector<string> ans;
    string op;
    op.push_back(s[0]);
    string ip = s.substr(1);
    
    solve(ans, ip, op, 0);
    
    return ans;
}