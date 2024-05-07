/*************************************************************************
	> File Name: 7.leetcode15.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue May  7 23:40:19 2024
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());     
        for(int k = nums.size() - 1; k >= 2;)
        {
            if(nums[k] < 0) 
                break;
            
            for(int i = 0, j = k - 1; i < j;)
            {
                if(nums[i] + nums[j] + nums[k] > 0)
                    j--;
                else if(nums[i] + nums[j] + nums[k] < 0)
                    i++;
                else{
                    ret.push_back({nums[i], nums[j],nums[k]});
                    i++, j--;
                    //去重
                    while(i < j && nums[i] == nums[i - 1])
                        i++;
                    while(i < j && nums[j] == nums[j + 1])
                        j--;
                }
            }
            k--;
            //去重
            while(k >= 2 && nums[k] == nums[k + 1])
                k--;
        }
        return ret;
    }
};
