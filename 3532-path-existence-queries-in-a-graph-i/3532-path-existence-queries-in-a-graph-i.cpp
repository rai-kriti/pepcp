class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         vector<int> prefix;

         int i =0;
         int count =0;
         //window i se expand krenge ek ek krke
         while(i<n){
            int j =i;
            prefix.push_back(count);
            //agar kam h to window badha do
            while(j+1 < n && nums[j+1] -  nums[j] <= maxDiff){
              //prefix k element count k euqal
               prefix.push_back(count);

                j++;
            }
            i = j + 1;
            count++;
         }

        vector<bool> ans;

        for(auto query:queries){
            ans.push_back(prefix[query[0]] == prefix[query[1]]);
        }
        return ans;

    }
};