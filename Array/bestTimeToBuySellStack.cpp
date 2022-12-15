#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    vector<int> temp(prices.size(),0);
    int max = INT_MIN;
    for(int i = prices.size()-1;i>-1;i--){
        if(max < prices[i])
            max = prices[i];
        temp[i] = max;
    }        
    max = INT_MIN;
    for(int i = 0;i<prices.size();i++){
        if(temp[i]-prices[i] > max)
            max = temp[i]-prices[i];
    }
    return max;
}