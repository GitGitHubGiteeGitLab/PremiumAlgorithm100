/**
    Try to use two-pointers. 
    Set one pointer to the left and one to the right of the array.
    Always move the pointer that points to the lower line.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max = 0, mini = 0;
        while(left < right)
        {
            int tmp = (right - left) * min(height[left], height[right]);
            max = tmp > max ? tmp : max;
            if(height[left] > height[right])
            {
                mini = right;
                right--;
            }
            else
            {
                mini = left;
                left++;
            }
        }
        return max;
    }
};