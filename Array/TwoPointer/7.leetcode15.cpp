/*************************************************************************
	> File Name: 7.leetcode15.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Apr 16 23:46:22 2024
 ************************************************************************/

#include<iostream>
using namespace std;
/**
    这道题的主题思路跟和为s的两个数思路一致
    不同的是这道题要三次去重操作
        left去重, right去重, i去重
		每次去重前要判断是否越界
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        size_t sz = nums.size();
        for(int i = 0; i < sz;)
        {
            if(nums[i] > 0)
            {
                break;
            }
            int target = -nums[i];
            int left = i + 1;
            int right = sz - 1;
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                if(sum > target)
                {
                    right--;
                }
                else if(sum < target)
                {
                    left++;    
                }
                else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++, right--;
                    //去重
                    while(left < right && nums[left] == nums[left - 1])left++;
                    while(left < right && nums[right] == nums[right + 1])right--;
                }
            }
            i++;
            while(i < sz && nums[i] == nums[i-1])i++;
        }
        return ans;
    }
};
