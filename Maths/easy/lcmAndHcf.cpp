// https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

int getGcd(int a, int b){
    if(b == 0){
        return a;
    }
    
    return getGcd(b, a%b);
}

vector<int> lcmAndGcd(int a, int b) {
    int gcd = getGcd(a,b);
    int lcm = (a*b)/gcd;
    return {lcm, gcd};
}