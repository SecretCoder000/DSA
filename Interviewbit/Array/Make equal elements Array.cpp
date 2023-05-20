//
// Created by himan on 5/11/2023.
//

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    set<int> temp;
    for(auto it : A){
        temp.insert(it);
        if(temp.size() > 3)
            return 0;
    }
    if(temp.size() == 2){
        auto itr = temp.begin();
        int a = *itr;
        itr++;
        int b = *itr;
        if(a - b == B)
            return 1;
        else
            return 0;
    }
    else if(temp.size() == 3) {
        auto itr = temp.begin();
        int a = *itr;
        itr++;
        int b = *itr;
        itr++;
        int c = *itr;
        if(b-a == B && c-b == B)
            return 1;
        else
            return 0;
    }else
        return 1;
}

