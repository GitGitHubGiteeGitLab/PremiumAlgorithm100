/*************************************************************************
	> File Name: 6.LCR179.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Apr 15 23:06:19 2024
 ************************************************************************/

#include<iostream>
using namespace std;
/**
    Note that price is in order
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0, right = price.size() - 1;
        while(left < right)
        {
            if(price[left] + price[right] > target)
            {
                right--;
            }
            else if(price[left] + price[right] < target)
            {
                left++;
            }
            else
            {
                return {price[left], price[right]};
            }
        }
        return {};
    }
};
