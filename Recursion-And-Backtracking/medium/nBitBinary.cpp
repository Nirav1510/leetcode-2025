// https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

void solve(int one, int zero, int n, string op, vector<string> &ans) {
    if (n == 0) {
        ans.push_back(op);
        return;
    }

    if(n>0){
        solve(one + 1, zero, n - 1, op + '1', ans);
    }

    if (one > zero) {
        solve(one, zero + 1, n - 1, op + '0', ans);
    }
}

vector<string> NBitBinary(int n){
    vector<string> ans;
    string op;
    solve(0, 0, n, op, ans);
    return ans;
}