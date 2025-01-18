// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

string FirstNonRepeating(string &s) {
    queue<int> q;
    string ans;
    unordered_map<char, int> freq;
    
    for(char c: s){
        freq[c]++;
        
        if(freq[c] == 1){
            q.push(c);
        }
        
        while(!q.empty() && freq[q.front()] > 1){
            q.pop();
        }
        
        if(q.empty()){
            ans.push_back('#');
        }else{
            ans.push_back(q.front());
        }
    }
    return ans;
}