// https://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable

pair<int, int> get(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;
    
    return {a,b};
}