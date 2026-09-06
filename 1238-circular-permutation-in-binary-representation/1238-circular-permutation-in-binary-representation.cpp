class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> result;
        int total = 1 << n; // 2^n elements total
        
        for (int i = 0; i < total; ++i) {
            // Standard Gray code for i is (i ^ (i >> 1))
            // XOR with 'start' to shift the entire sequence to begin at 'start'
            result.push_back(start ^ (i ^ (i >> 1)));
        }
        
        return result;
    }
};