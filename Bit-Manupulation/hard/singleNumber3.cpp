// https://leetcode.com/problems/single-number-iii/

vector<int> singleNumber(vector<int>& nums) {
    long long int totalXor = 0; // Use long long to handle potential overflow issues.
                                
    // Step 1: Calculate XOR of all elements in the array.
    // This will give us the XOR of the two unique numbers (x and y),
    // since all other numbers occur twice and cancel each other out.
    for (int num : nums) {
        totalXor = totalXor ^ num;
    }

    // Step 2: Find the rightmost set bit in `totalXor`.
    // This bit represents a difference between the two unique numbers.
    int rightMostSetBit = (totalXor & (totalXor - 1)) ^ totalXor;

    // Step 3: Divide numbers into two groups based on the rightmost set bit.
    // One group has numbers where the bit is set, the other where it is not.
    int x = 0, y = 0; // Initialize the two unique numbers.

    for (int num : nums) {
        if (num & rightMostSetBit) {
            // If the current number has the rightmost set bit, XOR it with x.
            x = x ^ num;
        } else {
            // Otherwise, XOR it with y.
            y = y ^ num;
        }
    }

    // Step 4: Return the two unique numbers.
    // The numbers x and y are the two single numbers that appear only once.
    return {x, y};
}
