/*************************************************************************
	> File Name: 8.leetcode18.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed May  8 23:15:48 2024
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i >= 3;)
        {
            for(int j = i - 1; j >= 2;)
            {
                long val = (long)target - nums[i] - nums[j]; 
                for(int left = 0, right = j - 1; left < right;)
                {
                    long sum = (long)nums[left] + nums[right];
                    if(sum > val)
                        right--;
                    else if(sum < val)
                        left++;
                    else{
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++, right--;
                        while(left < right && nums[left] == nums[left - 1])
                            left++;
                        while(left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
                j--;
                while(j >= 2 && nums[j] == nums[j + 1])
                    j--;
            }
            i--;
            while(i >= 3 && nums[i] == nums[i + 1])
                i--;
        }
        return ret;
    }
};
