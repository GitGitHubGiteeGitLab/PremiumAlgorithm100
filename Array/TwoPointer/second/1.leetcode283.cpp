/*************************************************************************
	> File Name: 1.leetcode283.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Apr 18 23:27:34 2024
 ************************************************************************/

#include<iostream>
using namespace std;

//这道题的关键是想好指针的含义
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = -1;
        while(i < nums.size())
        {
            if(nums[i])
            {
                swap(nums[++j], nums[i]);
            }
            i++;
        }
    }
};
