#include<bits/stdc++.h>
using namespace std;


int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> que;
        for(int i =0;i<=r;i++){
            que.push(arr[i]);
            while(que.size() > k)
                que.pop();
        }
        return que.top();
    }