#include<bits/stdc++.h>
using namespace std;
vector<int> leftSmaller(int n, int a[]){
        stack<int> st;
        st.push(n-1);
        vector<int> ans(n,0);
        for(int i = n-2;i>-1;i--){
            if(a[st.top()] <= a[i])
                st.push(i);
            else {
                while(!st.empty() && a[st.top()] > a[i]){
                    ans[st.top()] = a[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            ans[st.top()] = -1;
            st.pop();
        }
        return ans;
    }