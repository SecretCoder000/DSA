#include<bits/stdc++.h>
using namespace std;


vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    int i ,j,k;
    i=j=k=0;
    vector<int> ans;
    while(i < n1 && j < n2 && k < n3){
        if(A[i] == B[j] && B[j] == C[k]){
            if(ans.empty())
                ans.push_back(A[i]);
            else if(ans[ans.size()-1] < A[i])
                ans.push_back(A[i]);
            i++;
        }else if( B[j] == C[k] && A[i] < B[j])
            i++;
        else if(B[j] == C[k] && A[i] > B[j])
            j++;
        else if(A[i] == B[j] && C[k] > B[j])
            j++;
        else if(A[i] == B[j] && C[k] < B[j])
            k++;
        else if (A[i] == C[k] && B[j] > A[i])
            k++;
        else if (A[i] == C[k] && B[j] < A[i])
            j++;
        else if(A[i] < B[j] && A[i] < C[k])
            i++;
        else if(B[j] < A[i] && B[j] < C[k])
            j++;
        else if(C[k] < A[i] && C[k] < B[j])
            k++;
    }
    return ans;
}