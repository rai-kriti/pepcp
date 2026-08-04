class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        if (nums1.empty() || nums2.empty() || k == 0) {
            return {};
        }

        vector<vector<int>> ans;
        set<pair<int, int>> visit;

        int m = nums1.size();
        int n = nums2.size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({nums1[0] + nums2[0], {0, 0}});
        visit.insert({0, 0});

        while (k-- && !pq.empty()) {

            auto tp = pq.top();
            pq.pop();

            int i = tp.second.first;
            int j = tp.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && visit.find({i + 1, j}) == visit.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visit.insert({i + 1, j});
            }

            if (j + 1 < n && visit.find({i, j + 1}) == visit.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visit.insert({i, j + 1});
            }
        }

        return ans;
    }
};