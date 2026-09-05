#pragma GCC optimize("O3", "unroll-loops")

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // ---------------------------------------------------------
        // PRUNING 1: Frequency Check (Fail Fast)
        // ---------------------------------------------------------
        int boardCount[128] = {0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                boardCount[board[i][j]]++;
            }
        }
        
        int wordCount[128] = {0};
        for (char c : word) {
            wordCount[c]++;
            // If the board lacks the required number of a specific character, it's impossible.
            if (wordCount[c] > boardCount[c]) {
                return false; 
            }
        }
        
        // ---------------------------------------------------------
        // PRUNING 2: Word Reversal (Minimize DFS Branches)
        // ---------------------------------------------------------
        // If the first character of the word appears more often on the board 
        // than the last character, we reverse the word. This guarantees we start 
        // the DFS from the rarer character, drastically reducing false-start branches.
        if (boardCount[word.front()] > boardCount[word.back()]) {
            reverse(word.begin(), word.end());
        }
        
        // ---------------------------------------------------------
        // EXECUTE DFS
        // ---------------------------------------------------------
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Only start DFS if the first character matches
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index) {
        // Base case: Entire word found
        if (index == word.length()) return true;
        
        // Out of bounds or character mismatch
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // PRUNING 3: In-Place Visited Array
        char temp = board[i][j];
        board[i][j] = '*'; // Mark the current cell as visited
        
        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
                     
        // Backtrack: Restore the original character
        board[i][j] = temp;
        
        return found;
    }
};