/*************************************************************************
	> File Name: 3.leetcode202.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  4/ 9 22:33:16 2024
 ************************************************************************/

#include<iostream>
using namespace std;
/**
    链表有环/龟兔赛跑问题
    fast slow 
    do while
    fast == 1
*/
class Solution {
public:
    int cal(int n)
    {
        int val = 0;
        while(n)
        {
            val += (n % 10) * (n % 10);
            n = n / 10; 
        }
        return val;
    }
    bool isHappy(int n) {
        if(n == 1)
        {
            return true;
        }
        int slow = n;
        int fast = n;
        do{
            slow = cal(slow);
            fast = cal(cal(fast));
        }while(fast != 1 && fast != slow);
        return fast == 1;

    }
};
