class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> subboxes(9);

        for (int r{0}; r < 9; ++r) {
            for (int c{0}; c < 9; ++c) {
                auto cell{board[r][c]};

                if (cell == '.') continue;

                auto& row{rows[r]};
                auto& col{cols[c]};
                auto& subbox{subboxes[3*(r / 3) + (c / 3)]};

                if (row.count(cell) || col.count(cell) || subbox.count(cell)) return false;

                row.insert(cell);
                col.insert(cell);
                subbox.insert(cell);
            }
        }
        return true;
    }
};

/**

- define sets for each row, column, and sub-box.
- iterate board row-by-row
    - if cell is a number
        - return false if it already exists in the sets 
          corresponding to its row, column, and sub-box.
        - otherwise add it to its corresponding sets.

how to determine corresponding sets per cell?
given a cell at (row, column), 
 0 | 1 | 2 
 3 | 4 | 5 
 6 | 7 | 8
cell is in sub-box 3*row/3 + column/3

*/
