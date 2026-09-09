class Solution {
    int row_taken[9] = {0};
    int col_taken[9] = {0};
    int grid_taken[9] = {0};
    vector<pair<int, int>> blanks;

    bool solve(int index, vector<vector<char>>& board) {
        // Base case: If we successfully filled all blanks, we are done
        if (index == blanks.size()) return true;

        // Fetch row and col from the pair
        int r = blanks[index].first;
        int c = blanks[index].second;
        
        // Calculate the 1D grid index on the fly
        int g = (r / 3) * 3 + (c / 3); 

        // 1. Find all numbers already used
        int taken_bits = row_taken[r] | col_taken[c] | grid_taken[g];
        
        // 2. Flip bits so 1 means SAFE, and mask with 0x3FE (bits 1-9)
        int safe_bits = ~taken_bits & 0x3FE;

        // 3. Loop through ONLY the safe options
        while (safe_bits > 0) {
            // Isolate the smallest available number's bit
            int current_bit = safe_bits & -safe_bits; 
            
            // Translate that bit into an actual number (1 to 9)
            int number_to_place = __builtin_ctz(current_bit); 
            
            // Place the number and mark its bit as taken
            board[r][c] = '0' + number_to_place;
            row_taken[r] |= current_bit;
            col_taken[c] |= current_bit;
            grid_taken[g] |= current_bit;

            // Recurse to the next blank cell
            if (solve(index + 1, board)) return true;

            // BACKTRACK: Remove the number and mark the bit as free again
            board[r][c] = '.';
            row_taken[r] ^= current_bit;
            col_taken[c] ^= current_bit;
            grid_taken[g] ^= current_bit;

            // 4. Delete this bit from our safe options and test the next one
            safe_bits &= (safe_bits - 1); 
        }
        
        return false; 
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // Scan the board once to set up the problem
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    // Push coordinates as a pair
                    blanks.push_back({r, c}); 
                } else {
                    int g = (r / 3) * 3 + (c / 3); 
                    int number = board[r][c] - '0';
                    int current_bit = 1 << number;
                    
                    row_taken[r] |= current_bit;
                    col_taken[c] |= current_bit;
                    grid_taken[g] |= current_bit; 
                }
            }
        }
        
        // Start solving from the first blank cell
        solve(0, board);
    }
};