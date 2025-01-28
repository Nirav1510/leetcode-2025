// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

int getXorFrom1ToN(int n){
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    if(n % 4 == 3) return 0;
}

int findXOR(int l, int r) {
    int x = getXorFrom1ToN(l-1);
    int y = getXorFrom1ToN(r);
    
    return x^y;
}