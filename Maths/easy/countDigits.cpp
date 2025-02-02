// https://www.geeksforgeeks.org/problems/count-digits5716/1

int evenlyDivides(int n) {
    int temp = n, ans = 0;
    
    while(temp){
        int lastDigit = temp%10;
        temp = temp/10;
        
        if(lastDigit != 0 && n % lastDigit == 0){
            ans++;
        }
    }
    return ans;
}