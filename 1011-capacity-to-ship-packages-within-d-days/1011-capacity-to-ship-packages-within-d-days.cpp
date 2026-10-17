class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

         while (low < high) {
            int mid = low + (high - low) / 2;

            int daytook = 1;
            int currcap =0;
            for(int w :weights){
                if(currcap + w > mid){
                    daytook++;
                    currcap = 0;
                }

                currcap +=w;
            }
            if(daytook<= days) high = mid;
            else  low = mid+1;
        }
        return low ;
    }
};