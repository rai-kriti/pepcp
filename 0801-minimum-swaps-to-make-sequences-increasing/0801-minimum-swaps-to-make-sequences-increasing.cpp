
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int keep = 0;
        int swapped = 1;

        for (int i = 1; i < n; i++) {
            int keepNew = INT_MAX;
            int swappedNew = INT_MAX;

            // Both arrays increase without a cross-swap
            if (nums1[i] > nums1[i - 1] &&
                nums2[i] > nums2[i - 1]) {

                keepNew = keep;
                swappedNew = swapped + 1;
            }

            // Both arrays increase with a cross-swap
            if (nums1[i] > nums2[i - 1] &&
                nums2[i] > nums1[i - 1]) {

                keepNew = min(keepNew, swapped);
                swappedNew = min(swappedNew, keep + 1);
            }

            keep = keepNew;
            swapped = swappedNew;
        }

        return min(keep, swapped);
    }
};
