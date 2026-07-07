class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted =  heights;
        sort(sorted.begin() , sorted.end());
    int count =0;
        int n = heights.size();
        for(int i = 0 ; i<n ; i++){
            if(heights[i] !=  sorted[i]) count++;
        }

        return count;
    }
};