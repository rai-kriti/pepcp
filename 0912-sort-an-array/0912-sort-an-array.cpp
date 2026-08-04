class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        vector<int> freq(max_val - min_val + 1, 0);
        for (int num : nums) {
            freq[num - min_val]++;
        }
        
        vector<int> ans;
        ans.reserve(nums.size());
        
        for (int i = 0; i < freq.size(); ++i) {
            while (freq[i] > 0) {
                ans.push_back(i + min_val);
                freq[i]--;
            }
        }
        
        return ans;
    }
};