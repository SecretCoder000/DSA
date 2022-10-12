#include<bits/stdc++.h>
using namespace std;
string decodedString(string s){
        stack<char> st;
        string ans;
        for(int i =0;i<s.size();i++){
            if(s[i] == ']'){
                string temp;
                while(st.top() != '['){
                    temp.insert(temp.begin(),st.top());
                    st.pop();   
                }
                st.pop();
                string num ;
                while(!st.empty() && st.top() >= 48 && st.top() <= 57){
                    num.insert(num.begin(),st.top());
                    st.pop();
                }
                int n = stoi(num);
                while(n--){
                    for(int i = 0;i<temp.size();i++)
                        st.push(temp[i]);       
                }
            }else 
                st.push(s[i]);
        }
        while(!st.empty()){
            ans.insert(ans.begin(),st.top());
            st.pop();
        }
        return ans;
    }