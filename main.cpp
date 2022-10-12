#include<bits/stdc++.h>
using namespace std;
int largestPerimeter(vector<int>& nums) {
        int max = 0;
        for(int i =0;i<nums.size();i++){
            int temp = INT_MIN;
            for(int j = i+1;j<nums.size();j++){
                if(temp == INT_MIN){
					temp = nums[j];
					continue;
				}
                if(nums[i] >= temp && nums[i] >= nums[j] && nums[i] < temp + nums[j])
                    max = max<(nums[i]+nums[j]+temp)?(nums[i]+nums[j]+temp):max;
                else if(nums[j] >= temp && nums[j] >= nums[i] && nums[j] < temp + nums[i])
                    max = max<(nums[i]+nums[j]+temp)?(nums[i]+nums[j]+temp):max;
                else if(temp >= nums[i] && temp >= nums[j] && temp < nums[i] + nums[j])
                    max = max<(nums[i]+nums[j]+temp)?(nums[i]+nums[j]+temp):max;
				temp = temp<nums[j]?nums[j]:temp;
            }
        }
        return max;
    }
int main() {
	vector<int> arr= {3,6,2,3};
	cout<<largestPerimeter(arr);

	return 0;
}