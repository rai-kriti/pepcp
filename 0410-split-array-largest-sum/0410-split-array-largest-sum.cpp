class Solution {
public:
    bool cansplit(vector<int> nums , int k , int mid){
        int parts =1;
        int sum=0 ;
        for(int x : nums){
            if(sum+x > mid){
                parts++;
                sum = x ;
            }else{
                sum+=x;
            }
        }
return parts<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);

        while(low <high){
            int mid =  low+(high-low)/2;

            if(cansplit(nums, k , mid))  high = mid;
            else low = mid+1;
        }

        return low;
    }
    
};