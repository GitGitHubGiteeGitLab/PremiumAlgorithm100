/**
                    left     right
    initial value    -1        0
    
    The idea would be to have one pointer for iterating the array 
    and another pointer that just works on the non-zero elements of the array.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t sz = nums.size();
        int left = -1, right = 0;
        while(right < sz)
        {
            if(nums[right])
            {
                left++;
                swap(nums[left], nums[right]);
            }
            right++;
        }
        return;


    }
};