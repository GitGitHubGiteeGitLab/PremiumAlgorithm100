class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) 
    {
        for(int i = 0, j = price.size() - 1; i < j;)
        {
            if(price[i] + price[j] > target)
                j--;
            else if(price[i] + price[j] < target)
                i++;
            else
                return {price[i], price[j]};
        }
        return {};
    }
};
