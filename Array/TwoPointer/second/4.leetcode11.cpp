/*************************************************************************
	> File Name: 4.leetcode11.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Apr 24 23:02:09 2024
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution 
{
//求面积：一左一右，对撞指针(左+右-)
public:
    int maxArea(vector<int>& height) 
    {
        int i = 0, j = height.size() - 1;
        int maxS = 0;
        while(i < j){
            int tmpS = (j - i) * min(height[i], height[j]);
            maxS = max(maxS, tmpS);
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxS;
    }
};
