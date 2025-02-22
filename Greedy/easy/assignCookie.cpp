// https://leetcode.com/problems/assign-cookies/

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int n = s.size(), m = g.size();
    int i = 0, j = 0;
    int ans = 0;

    while(i<n && j<m){
        if(s[i] >= g[j]){
            ans++;
            j++;
        }
        i++;
    }

    return ans;
}