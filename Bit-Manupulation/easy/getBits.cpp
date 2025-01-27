// https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1

void bitManipulation(int num, int i) {
    // Get ith bit
    int getBit = (num & (1 << (i - 1))) ? 1 : 0;

    // Set ith bit
    int setBit = num | (1 << (i - 1));

    // Clear ith bit
    int clearBit = num & ~(1 << (i - 1));

    // Output the results
    cout << getBit << " " << setBit << " " << clearBit;
}