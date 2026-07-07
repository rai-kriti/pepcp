class Solution {
public:
    int numRescueBoats(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int i = 0;
        int j = arr.size() - 1;
        int count = 0;

        while (i <= j) {
            if (arr[i] + arr[j] <= k) {
                i++;
            }
            j--;
            count++;
        }

        return count;
    }
};