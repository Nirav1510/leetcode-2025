// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1

void solve(int n, string op, vector<string> &ans) {
    if (n == 0) {
        ans.push_back(op);
        return;
    }

    // Add '0' to the current string and recurse
    solve(n - 1, op + '0', ans);

    // Add '1' only if the previous character is not '1'
    if (op.empty() || op.back() != '1') {
        solve(n - 1, op + '1', ans);
    }
}

vector<string> generateBinaryStrings(int n){
    vector<string> ans;
    string op;
    solve(n, op, ans);
    return ans;
}