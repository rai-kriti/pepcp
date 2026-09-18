class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> current_row ;
                
        current_row.push_back(poured);

        for (int r = 0; r < query_row; ++r) {
            vector<double> next_row(r + 2, 0.0);
            
            for (int c = 0; c <= r; ++c) {
                double excess = (current_row[c] - 1.0) / 2.0;
                if (excess > 0) {
                    next_row[c] += excess;      // Left child
                    next_row[c + 1] += excess;  // Right child
                }
            }
            
            current_row = move(next_row);
        }

        return min(1.0, current_row[query_glass]);
    }
};