class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : st) {
            rank[x] = r++;
        }

        vector<int> ans;
        for (int x : arr) {
            ans.push_back(rank[x]);
        }

        return ans;
    }
};