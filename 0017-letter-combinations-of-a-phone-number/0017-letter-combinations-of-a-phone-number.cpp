class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Return empty if input is empty
        
        vector<string> result;
        string current;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, 0, current, result, mapping);
        return result;
    }

private:
    void backtrack(const string &digits, int index, string &current, vector<string> &result, vector<string> &mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0']; // Get letters for the current digit
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result, mapping);
            current.pop_back(); // Backtrack step
        }
    }
};
