class Solution {
public:
    int minimumBeauty(int n, vector<int> &id) {
        sort(id.begin(),id.end());
        map<int,multiset<int>> mpp;
        for(int i=0;i<n;i++){
            int ele=id[i];
            if(mpp.find(ele-1)==mpp.end()){
                mpp[ele].insert(1);
            }
            else{
                auto it=mpp[ele-1].begin();
                mpp[ele-1].erase(it);
                if(mpp[ele-1].size()==0){
                    mpp.erase(ele-1);
                }
                mpp[ele].insert(*(it)+1);
            }
        }
        int mn=1e9;
        for(auto x:mpp){
            auto s=x.second;
            for(auto it=s.begin();it!=s.end();it++){
                mn=min(mn,*(it));
            }
        }
        return mn;
    }
};