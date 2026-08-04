class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : arr) {
            if (k > 0) {
                pq.push(num);
                k--;
            } else if (abs(pq.top() - x) > abs(num - x)) {
                pq.pop();
                pq.push(num);
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};