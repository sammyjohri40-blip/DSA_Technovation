class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pvoit = -1,  n = nums.size();
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                pvoit = i;
                break;
            }
        }
        if(pvoit == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = n-1; i>=0; i--){
            if(nums[i] > nums[pvoit]){
                swap(nums[i], nums[pvoit]);
                break;
            }
        }
        int i = pvoit + 1, j = n-1;
        while(i<=j){
            swap(nums[i], nums[j]);
            i++,j--;
        }
    }
};
