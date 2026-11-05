#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Count the frequency of each number
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: Create buckets where the index represents the frequency
        vector<vector<int>> freq(n + 1);
        for (auto& [num, cnt] : count) {
            freq[cnt].push_back(num);
        }
        
        // Step 3: Collect top k frequent elements from highest frequency to lowest
        vector<int> res;
        for (int i = n; i >= 0; --i) {
            for (int num : freq[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        
        return res;
    }
};
