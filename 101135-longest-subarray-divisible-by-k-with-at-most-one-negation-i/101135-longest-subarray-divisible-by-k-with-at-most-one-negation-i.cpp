class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int l=0 ; l<n ; l++){
         
            vector<bool> found(k , false);
            long long sum =0;

            for(int r = l  ; r<n ; r++){
                sum = sum+ nums[r];
                int rem = ((sum % k) + k ) % k;
                
                int negelement =  ((2LL* nums[r] %k + k ) %k);
                found[negelement] = true;

                if(rem == 0){
                    ans = max(ans  , r-l+1);
                }else if(found[rem]) ans = max(ans , r-l+1);
            
                

            
            }
            
        }
        return ans;
    }
};