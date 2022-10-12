#include<bits/stdc++.h>
using namespace std;

int max_path_sum(int A[], int B[], int l1, int l2){
    int i,j;
    i=j=0;
    int s1,s2;
    s1 = s2 = 0;
    int sum = 0;
    while(i < l1 && j < l2){
        if(A[i] < B[j]){
            s1 += A[i];
            i++;
        }
        else if(A[i] > B[j]){
            s2 += B[j];
            j++;
        }
        else {
            sum += (s1>s2?s1:s2);
            s1=s2=0;
            while (A[i] == B[j] && i < l1 && j < l2){
                sum += A[i];
                i++;
                j++;
            }            
        }
    }
    while(i < l1)
        s1 += A[i++];
    while(j < l2)
        s2 += B[j++];
    return sum+(s1>s2?s1:s2);
}
int main() {
    int n,m;
    cin>>m>>n;
    int arr[m];
    int brr[n];
    for(int i =0;i<m;i++)
        cin>>arr[i];
    for(int i =0;i<n;i++)
        cin>>brr[i];
    cout<<max_path_sum(arr,brr,m,n);
    return 0;
}