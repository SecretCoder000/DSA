#include<bits/stdc++.h>
using namespace std;
//1 3 2 4
    vector<long long> nextLargerElement(vector<long long> arr, long long n){
        stack<long long> st;
        vector<long long> ans(n,0);
        st.push(0);
        for(int i =1;i<n;i++){
            if(arr[st.top()] >= arr[i])
                st.push(i);
            else {
                while (!st.empty() && arr[st.top()] < arr[i]){
                    ans[st.top()] = arr[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while (!st.empty()){
            ans[st.top()] = -1;
            st.pop();
        }
        return ans;
    }
int main(){
    vector<long long> arr = {1 ,3 ,2 ,4};
    vector<long long> ans = nextLargerElement(arr,arr.size());
    for(int i =0;i<arr.size();i++)
        cout<<ans[i]<<"\t";
    return 0;
}