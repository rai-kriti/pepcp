class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& s) {
        long long p[(int)1e5+1]= {};
        for(int i = 0; i<s.size(); i++){
            int l = s[i][0], r = s[i][1], c = s[i][2];
            p[l]+=c;
            p[r]-=c;
        }
        for(int i = 1; i<=1e5; i++) p[i]+=p[i-1];
        for(int i = 0; i<s.size(); i++){
            int l = s[i][0];
            if(p[l] > 0) p[l]*=-1;
        }
        vector<vector<long long>> ans;
        long long mag = 0;
        for(int i = 0; i<=1e5; i++){
            if(p[i]!=0){
                mag = abs(p[i]);
                int j = i+1;
                while(j<=1e5 && p[j]>0 && p[j] == mag)j++;
                vector<long long> temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(mag);
                ans.push_back(temp);
                i = j-1;
            }
        }
        return ans;
    }
};