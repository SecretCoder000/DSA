#include<bits/stdc++.h>
#include "LinkedList/linkedlist.h"
using namespace std;

vector<int> minPartition(int N){
    vector<int> arr = {1,2,5,10,20,50,100,200,500,2000};
    vector<int> ans;
    for(int i = arr.size()-1;i>-1 && N > 0;i--){
        int temp = N/arr[i];
        if(temp > 0){
            vector<int> temp2(temp,arr[i]);
            ans.insert(ans.end(),temp2.begin(),temp2.end());
            N = N%arr[i];
        }
    }
    return ans;
}