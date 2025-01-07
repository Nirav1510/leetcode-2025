// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

int search(string &a, string &b) {
    unordered_map<char, int> mp;
    int ans = 0, i = 0, j = 0, k = b.length();
    int n = a.length();

    // If b is longer than a, there can be no anagrams
    if (k > n) return 0;

    // Populate the frequency map for string b
    for (char c : b) {
        mp[c]++;
    }

    int count = mp.size(); // Count of unique characters in b

    // Sliding window logic
    while (j < n) {
        // Process the current character
        if (mp.find(a[j]) != mp.end()) {
            mp[a[j]]--;
            if (mp[a[j]] == 0) {
                count--; // Unique character matched
            }
        }

        // Check window size
        if (j - i + 1 == k) {
            // If all characters are matched, it's an anagram
            if (count == 0) {
                ans++;
            }

            // Slide the window
            if (mp.find(a[i]) != mp.end()) {
                mp[a[i]]++;
                if (mp[a[i]] == 1) {
                    count++; // Unique character unmatched
                }
            }
            i++;
        }
        j++;
    }

    return ans;
}
