// https://leetcode.com/problems/powx-n/

double myPow(double x, int n) {
    if(n == 0) return (double)1;
    if(n == 1) return x;
    if(n == -1) return (double)1/x;
    
    if(n % 2 == 0){
        double res = myPow(x, n/2);
        return res*res;
    }else{
        return x*myPow(x, n-1);
    }
}

// iterative
double myPow(double x, int n) {
    if (n == 0) return 1.0;

    long long absN = abs((long long)n); 
    double result = 1.0;

    while (absN > 0) {
        if (absN % 2 == 1) {
            result *= x;
        }
        x *= x;
        absN /= 2;
    }

    return (n < 0) ? 1.0 / result : result;
}