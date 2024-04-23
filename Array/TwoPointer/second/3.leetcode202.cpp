/*************************************************************************
	> File Name: 3.leetcode202.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Apr 23 23:27:59 2024
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution 
{
public:
    int calculate(int n)
    {
        int ret = 0;
        while(n){
            ret += pow(n % 10, 2);
            n /= 10;
        }
        return ret;
    }
    //链表成环: 快慢指针
    bool isHappy(int n) 
    {
        int slow = n;
        //快的要先走一步
        int fast = calculate(n);
        while(fast != slow && fast != 1){
            fast = calculate(calculate(fast));
            slow = calculate(slow);
        }
        return fast == 1;
    }
};

