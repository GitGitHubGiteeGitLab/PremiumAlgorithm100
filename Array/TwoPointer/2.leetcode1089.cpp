/**
stack
If we had enough space available, 
we would be able to accommodate all the elements properly. 
The new length would be the original length of the array plus the number of zeros. 
Can we use this information somehow to solve the problem?
*/
//特殊的测试用例 [0,0,0,0,0,0,0]
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int left = 0, right = 0;
        size_t  sz = arr.size();
        //计数
        for(int i = 0; i < sz; i++,left++)
        {
           if(arr[i] == 0)
           {
               right += 2;
           } 
           else
           {
               right += 1;
           }
           
           if(right >= sz)
                break;
        }

//特殊的测试用例 [0,0,0,0,0,0,0]
        if(right == sz)
        {
            right--;
        }
        else
        {
           right -= 2;
           arr[right] = 0;
           right--;
           left--;//left也要减减
        }

        for(; left >= 0; left--)
        {
            if(arr[left] == 0)
            {
                arr[right] = 0;
                right--;
                arr[right] = 0;
                right--;
            }
            else
            {
                arr[right] = arr[left];
                right--;
            }
        }
        return;
    }
};