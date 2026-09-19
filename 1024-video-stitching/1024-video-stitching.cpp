#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // Sort clips primarily by start time
        sort(clips.begin(), clips.end());
        
        int count = 0;
        int curr_end = 0;
        int far_end = 0;
        int i = 0, n = clips.size();
        
        while (curr_end < time) {
            // Pick all valid clips starting <= curr_end and find max reach
            while (i < n && clips[i][0] <= curr_end) {
                far_end = max(far_end, clips[i][1]);
                i++;
            }
            
            // If no clip can extend curr_end, a gap exists
            if (curr_end == far_end) {
                return -1;
            }
            
            curr_end = far_end;
            count++;
        }
        
        return count;
    }
};