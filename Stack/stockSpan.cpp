#include<bits/stdc++.h>
using namespace std;
vector<int> calculateSpan(int price[], int n){
    stack<int> st;
    vector<int> ans(n,0);
    st.push(0);
    for(int i = 1;i<n;i++) {
        while (!st.empty() && price[st.top()] < price[i])
            st.pop();
        if(st.empty())
            ans[i] = i+1;
        else 
            ans[i] = i-st.top();
        st.push(i);
    }
    while (!st.empty())
    st.pop();
    return ans;
}