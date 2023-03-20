#include<bits/stdc++.h>
using namespace std;
set<int> temp;
long long numberOfSubsequences(int n, long long arr[]){
    int count = 0;
    for(int i = 1;i<=100000000;i++)
        temp.insert(pow(2,i));
    for(int i =0;i<n;i++){
        if(temp.find(arr[i]) != temp.end())
            count++; 
    }
    long long ans = pow(2,count)-1;
    return ans%(100000000+7);
}
int main(){
    cout<<(-18778424)%1000000007;
    return 0;
}