// https://leetcode.com/problems/fractional-knapsack/

static bool compare(pair<int,int> &a, pair<int,int> &b){
    double r1 = (double)a.first/(double)a.second;
    double r2 = (double)b.first/(double)b.second;
    
    return r1 > r2;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = wt.size();
    vector<pair<int, int>> ratio;

    for (int i = 0; i < n; i++) {
        ratio.push_back({val[i], wt[i]});
    }

    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0;

    for (int i = 0; i < n; i++) {
        double value = ratio[i].first;
        double weight = ratio[i].second; 

        if (capacity >= weight) {
            ans += value;
            capacity -= weight;
        } else {
            ans += (value / weight) * capacity;
            break;
        }
    }
    return ans;
}