#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // max_reach[i] store karega ki start point 'i' se maximum kitni aage tak ja sakte hain
        vector<int> max_reach(time + 1, 0);
        
        for (const auto& clip : clips) {
            int start = clip[0];
            int end = clip[1];
            if (start <= time) {
                max_reach[start] = max(max_reach[start], end);
            }
        }
        
        int count = 0;
        int curr_end = 0;
        int far_end = 0;
        
        for (int i = 0; i < time; i++) {
            // Abhi tak ke saare reachable points me se farthest end compute karo
            far_end = max(far_end, max_reach[i]);
            
            // Jab hum current boundary ke end tak pahunch jayein
            if (i == curr_end) {
                // Agar hum aage nahi badh pa rahe, toh coverage impossible hai
                if (far_end <= i) {
                    return -1;
                }
                count++;
                curr_end = far_end; // Agli boundary set karo
            }
        }
        
        return curr_end >= time ? count : -1;
    }
};