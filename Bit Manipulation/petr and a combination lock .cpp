#include <bits/stdc++.h>
using namespace std;
bool checkBitSet(int n ,int i) {
    return n&(1<<i);
}
bool solve(vector<int> arr) {
    int n = arr.size();
    int r = 1<<n;
    int ans=0;
    for(int i =0;i<r;i++){
        int clockWise = 0;
        int antiClockWise = 0;
        for(int j = 0;j<n;j++){
            if(checkBitSet(i,j))
                clockWise += arr[j];
            else
                antiClockWise += arr[j];
        }
        int totalRotation = abs(clockWise-antiClockWise);
        if(totalRotation%360 == 0)
            return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++)
        cin>>arr[i];
    cout<<(solve(arr)?"YES":"NO");
    return 0;
}