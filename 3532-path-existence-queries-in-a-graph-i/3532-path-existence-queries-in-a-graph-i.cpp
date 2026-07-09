class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         vector<int> prefix(n , 1 );

         int i =1;
         int count =1;
        
         while(i<n){
            
            //agar kam h to window badha do
            if( nums[i] -  nums[i-1] <= maxDiff){
                  count++;
              //prefix k element count k euqal
               prefix[i] = count;
            }else{
                count =1;
            }
            i++;
         }

         vector<bool> ans;
         for(auto q: queries){
            int l = min(q[0] , q[1]);
            int r = max(q[0] , q[1]);
            
            
            if(  prefix[r] >= abs(r-l)+1){ ans.push_back(true);}
            else {
                ans.push_back(false);
            }

         }
         return ans;
    }
};