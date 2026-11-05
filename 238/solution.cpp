#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // Step 1: Compute left (prefix) products
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftProduct;
            leftProduct *= nums[i];
        }
        
        // Step 2: Compute right (suffix) products and multiply with left products
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return ans;
    }
};
