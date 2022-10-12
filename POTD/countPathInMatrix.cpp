#include<bits/stdc++.h>
using namespace std;
void solve(int x,int y,long long int & count){
    if(x == 0 && y == 0)
        count++;
    else if(x < 0 || y < 0)
        return ;
    else {
        solve(x-1,y,count);   
        solve(x,y-1,count);   
    }
}
long long int numberOfPaths(int m, int n){
    long long int count = 0;
    solve(m-1,n-1,count);
    return count;
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<numberOfPaths(m,n);
    return 0;
}