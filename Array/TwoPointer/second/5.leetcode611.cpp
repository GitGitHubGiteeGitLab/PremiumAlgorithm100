/*************************************************************************
	> File Name: second/5.leetcode611.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Apr 26 23:52:03 2024
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution 
{
public:
    //triple pointer
    int triangleNumber(vector<int>& nums) 
    {
        int count = 0 ;
        sort(nums.begin(), nums.end());
        for(int k = nums.size() - 1; k >= 2; k--){
            for(int i = 0, j = k - 1; i < j;){
                if(nums[i] + nums[j] <= nums[k]){
                    i++;
                }
                else{
                    count += j - i;
                    j--;
                }
            }
        }
        return count;
    }
};
