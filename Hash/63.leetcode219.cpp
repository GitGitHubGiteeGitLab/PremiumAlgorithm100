class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // key : nums[i]  value : i
        unordered_map<int, int> hash;
        for(size_t i = 0; i < nums.size(); i++)
        {
            if(hash.count(nums[i]) && (i - hash[nums[i]] <= k))
                return true;
            hash[nums[i]] = i;
        }
        return false;
    }
};