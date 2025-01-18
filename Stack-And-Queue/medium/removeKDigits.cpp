// https://leetcode.com/problems/remove-k-digits/

string removeKDigits(string num, int k) {
    if(num.size() <= k){
        return "0";
    }
    if(k == 0){
        return num;
    }

    stack<char> s;
    string ans;

    for(char n : num){
        while(!s.empty() && s.top() > n && k>0){
            s.pop();
            k--;
        }

        if (!s.empty() || n != '0') {
            s.push(n);
        }
    }

    while(k && !s.empty()){
        k--;
        s.pop();
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans.size() == 0 ? "0" : ans;
}