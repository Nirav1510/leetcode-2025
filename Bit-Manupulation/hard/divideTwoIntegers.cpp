// https://leetcode.com/problems/divide-two-integers/

int divide(int dividend, int divisor) {
    if(dividend == 0) return 0;
    if(dividend == divisor) return 1;

    bool isPositive = (dividend > 0) == (divisor > 0);

    long long int ans = 0; // quotient
    long long int n = abs((long long int)dividend), d = abs((long long int)divisor);

    while(n >= d){
        long long int count = 0;

        while(n >= (d << count+1)){
            count++;
        }

        long long int powerOf2 = 1LL << count;
        ans = ans + powerOf2;
        n = n - (d * powerOf2); 
    }

    ans = isPositive ? ans : -ans;
    return (ans < INT_MIN || ans > INT_MAX) ? INT_MAX : ans;
}