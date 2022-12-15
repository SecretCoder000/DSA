#include<bits/stdc++.h>
using namespace std;
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    for(int i =0;i<matrix.size()-1;i++){
        vector<int> r1 = matrix[i];
        vector<int> r2 = matrix[i+1];
        r1.erase(r1.end()-1);
        r2.erase(r2.begin());
        if(r1 != r2)
            return false;
    }
    return true;
}
//int main(){
//    vector<vector<int>> ans = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
//    cout<<isToeplitzMatrix(ans);
//    return 0;
//}
