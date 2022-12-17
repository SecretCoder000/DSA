#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> arr) {
    stack<string> st;
    int n = arr.size();
    for(int i =0;i<n;i++){
        if(arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/"){
            int a = stoi(st.top());
            st.pop();
            int b = stoi(st.top());
            st.pop();
            int res;
            if(arr[i] == "+")
                res = a+b;
            else if(arr[i] == "-")
                res = a-b;
            else if(arr[i] == "/")
                res = b/a;
            else
                res = b*a;
            st.push(to_string(res));
        }else
            st.push(arr[i]);
    }

    return stoi(st.top());
}