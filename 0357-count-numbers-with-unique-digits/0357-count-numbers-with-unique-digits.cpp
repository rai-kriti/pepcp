class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int totalCount = 10;
        int uniqueChoices = 9;
        int currentProduct = 9;

        for (int len = 2; len <= n && uniqueChoices > 0; ++len) {
            currentProduct *= uniqueChoices;
            totalCount += currentProduct;
            uniqueChoices--;
        }

        return totalCount;
    }
};