#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs by their end value
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int curr_end = INT_MIN;

        for (const auto& pair : pairs) {
            // Valid successor requires start > previous end (b < c)
            if (pair[0] > curr_end) {
                curr_end = pair[1];
                count++;
            }
        }

        return count;
    }
};