/*************************************************************************
	> File Name: 8.leetcode18.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Apr 17 23:43:31 2024
 ************************************************************************/

#include<iostream>
using namespace std;
/**
    3Sum
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < sz;)
        {
            for(int j = i + 1; j < sz;)
            {
                // target不强转会下溢出
                long long aim = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = sz - 1;
                while(left < right)
                {
                    int sum = nums[left] + nums[right];
                    if(sum > aim)
                    {
                        right--;
                    }
                    else if(sum < aim)
                    {
                        left++;
                    }
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++, right--;
                        while(left < right && nums[left] == nums[left - 1])left++;
                        while(left < right && nums[right] == nums[right + 1])right--;
                    }
                }
                j++;
                while(j < sz && nums[j] == nums[j - 1])j++;
            }
            i++;
            while(i < sz && nums[i] == nums[i - 1])i++;
        }
        return ans;
    }
};

