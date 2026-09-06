class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        
        for (int i = 0; i < nums.size(); i++) {
            // Flip the i-th character of the i-th string
            if (nums[i][i] == '0') {
                ans += '1';
            } else {
                ans += '0';
            }
        }
        
        return ans;
    }
};