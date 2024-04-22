class Solution {
public:
    //i需要调整为守门员
    void duplicateZeros(vector<int>& arr) {
        //i,j不同的初始值后续处理不同
        int i = 0;
        int j = 0;

        while(j < arr.size())
        {
            if(arr[i] == 0)
            {
                j += 2;
            }
            else
            {
                j += 1;
            }
            i++;
        }

        if(i == arr.size())
        {
            return; 
        }

        if(j == arr.size())
        {
            i--;
            j--;
        }
    
        if(j == arr.size() + 1)
        {
            j -= 2;
            arr[j--] = 0;
            i -= 2;
        }
        

        while(i >= 0)
        {
            if(arr[i] == 0)
            {
                arr[j--] = 0;
                arr[j--] = 0;
            }
            else
            {
                arr[j--] = arr[i];
            }
            i--;
        }


    }
};
