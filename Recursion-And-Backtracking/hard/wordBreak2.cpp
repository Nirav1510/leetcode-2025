// https://leetcode.com/problems/word-break-ii/

string getSentence(vector<string> &v){
    string res;
    for(int i=0;i<v.size();i++){
        res+=v[i];
        if(i != v.size()-1){
            res+=" ";
        }
    }
    return res;
}

void solve(int start, string &s, vector<string> &curr, unordered_set<string> &wordSet, vector<string> &ans){
    if(start == s.size()){
        string sentence = getSentence(curr);
        ans.push_back(sentence);
        return;
    }

    string word;
    for(int i=start;i<s.size();i++){
        word+=s[i];
        if(wordSet.count(word)){
            curr.push_back(word);
            solve(i+1, s, curr, wordSet, ans);
            curr.pop_back();
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> ans;
    vector<string> curr;
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    solve(0, s, curr, wordSet, ans);

    return ans;
}