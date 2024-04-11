/*************************************************************************
	> File Name: 5.leetcode611.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Apr 11 23:56:35 2024
 ************************************************************************/

#include<iostream>
using namespace std;
/**
    先排序：升序
    fix biggest number nums[i];
            initial value
    left        0
    right       i - 1
    省略了nums
    left + right >  i  [left, right - 1]  right  i都可以
    left + right <= i  left [left + 1, right] i都不可以
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        size_t sz = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = sz - 1; i >= 2; i--)
        {
           int left = 0;
           int right = i - 1;
           while(left < right) 
           {
               if( nums[left] + nums[right] > nums[i])
               {
                  ans += right - left; 
                  right--;
               }
               else
               {
                  left++; 
               }
           }
        }
        return ans;
    }
};
