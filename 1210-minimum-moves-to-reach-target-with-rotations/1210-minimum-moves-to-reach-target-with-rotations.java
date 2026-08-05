import java.util.*;

class Solution {
    public int minimumMoves(int[][] grid) {
        int n = grid.length;

        // row, col, direction, steps
        // direction: 0 = Horizontal, 1 = Vertical
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 0, 0});

        boolean[][][] visited = new boolean[n][n][2];
        visited[0][0][0] = true;

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();

            int r = curr[0];
            int c = curr[1];
            int dir = curr[2];
            int steps = curr[3];

            // Target State
            if (r == n - 1 && c == n - 2 && dir == 0) {
                return steps;
            }

            if (dir == 0) { // Horizontal

                // Move Right
                if (c + 2 < n &&
                    grid[r][c + 2] == 0 &&
                    !visited[r][c + 1][0]) {

                    visited[r][c + 1][0] = true;
                    queue.offer(new int[]{r, c + 1, 0, steps + 1});
                }

                // Move Down
                if (r + 1 < n &&
                    grid[r + 1][c] == 0 &&
                    grid[r + 1][c + 1] == 0) {

                    // Move Down
                    if (!visited[r + 1][c][0]) {
                        visited[r + 1][c][0] = true;
                        queue.offer(new int[]{r + 1, c, 0, steps + 1});
                    }

                    // Clockwise Rotation
                    if (!visited[r][c][1]) {
                        visited[r][c][1] = true;
                        queue.offer(new int[]{r, c, 1, steps + 1});
                    }
                }

            } else { // Vertical

                // Move Down
                if (r + 2 < n &&
                    grid[r + 2][c] == 0 &&
                    !visited[r + 1][c][1]) {

                    visited[r + 1][c][1] = true;
                    queue.offer(new int[]{r + 1, c, 1, steps + 1});
                }

                // Move Right
                if (c + 1 < n &&
                    grid[r][c + 1] == 0 &&
                    grid[r + 1][c + 1] == 0) {

                    // Move Right
                    if (!visited[r][c + 1][1]) {
                        visited[r][c + 1][1] = true;
                        queue.offer(new int[]{r, c + 1, 1, steps + 1});
                    }

                    // Counter-Clockwise Rotation
                    if (!visited[r][c][0]) {
                        visited[r][c][0] = true;
                        queue.offer(new int[]{r, c, 0, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
}