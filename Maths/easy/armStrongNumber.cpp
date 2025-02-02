// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1


bool armstrongNumber(int n) {
    int curr = n;
    int sum = 0;
    
    while(curr){
        int ld = curr%10;
        curr = curr/10;
        
        sum += ld*ld*ld;
    }
    
    return sum == n;
}