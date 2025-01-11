// https://leetcode.com/problems/minimum-window-substring/

string minWindow(string s, string t) {
    vector<int> hash(256, 0);

    for(int i=0;i<t.size();i++){
        hash[t[i]]++;
    }

    int i=0, j=0, count = 0;
    int minLength = INT_MAX, startIdx = -1, n = s.size();

    while(j<n){
        if(hash[s[j]] > 0){
            count++;
        }
        hash[s[j]]--;

        while(count == t.size()){
            if(minLength > j-i+1){
                minLength = j-i+1;
                startIdx = i;
            }
            hash[s[i]]++;
            if(hash[s[i]]>0){
                count--;
            }
            i++;
        }
        j++;
    }

    return startIdx == -1 ? "" : s.substr(startIdx, minLength);
}