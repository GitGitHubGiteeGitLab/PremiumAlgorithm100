class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2)
            return false;
        unordered_map<int, int> hash;
        for(auto& e : nums)
        {
            if(++hash[e] == 2)
                return true;
        }
        return false;
    }
};