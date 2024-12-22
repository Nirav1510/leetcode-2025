vector<int> findTwoElement(vector<int>& arr) {
    long long n = arr.size();
    long long s1 = 0, s2 = 0;
    
    // Calculate the sum and sum of squares of elements in the array
    for (long long a : arr) {
        s1 += a;
        s2 += ((long long)a * (long long)a);
    }
    
    // Sum and sum of squares of first n natural numbers
    long long s1n = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    
    // Differences
    long long v1 = s1n - s1;       // Missing - Repeated
    long long v2 = s2n - s2;       // Missing^2 - Repeated^2
    
    // Calculate missing and repeated numbers
    v2 = v2 / v1;                  // (Missing + Repeated)
    long long missing = (v1 + v2) / 2;
    long long repeated = missing - v1;
    
    // Return as integers
    return {(int)repeated, (int)missing};
}