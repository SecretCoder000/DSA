#include<bits/stdc++.h>
using namespace std;
 int maximizeSum(int a[], int n) {
    map<int,int> temp;
    for(int i =0;i<n;i++){
        auto itr = temp.find(a[i]);
        if(itr == temp.end())
            temp.insert({a[i],1});
        else 
            itr->second++;
    }
    int sum = 0;
    for(auto itr = temp.rbegin(); itr != temp.rend();){
        if(itr->second > 0){
            sum += itr->first;
            auto itr2 = temp.find(itr->first-1);
            if(itr2 != temp.end())
                itr2->second--;
            itr->second--;
        }
        else    
            itr++;
    }
    return sum;
}
int main(){
    vector<int> arr = {9 ,15 ,9 ,3 ,8 ,4 ,6 ,17 ,7 ,11 ,17 ,7 ,3 ,18 ,13 ,9 ,7 ,12 ,2 ,8};
    cout<<maximizeSum(arr.data(),arr.size());
}