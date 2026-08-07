class Solution {
    static constexpr auto size{9};
public:
    bool isValidSudoku(const vector<vector<char>>& board) {

        array<uint16_t, size> rows{};
        array<uint16_t, size> cols{};
        array<uint16_t, size> subboxes{};

        for (int r{0}; r < size; ++r) {
            for (int c{0}; c < size; ++c) {
                const auto cell{board[r][c]};

                if (cell == '.') continue;

                auto& row{rows[r]};
                auto& col{cols[c]};
                auto& subbox{subboxes[3*(r / 3) + (c / 3)]};

                const auto cellValue{cell - '0'};
                const uint16_t bitMask{static_cast<uint16_t>(1u << cellValue - 1)};

                if ((row | col | subbox) & bitMask) return false;

                row |= bitMask;
                col |= bitMask;
                subbox |= bitMask;
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

OR store as uint16_t and bit mask

how to determine corresponding sets per cell?
given a cell at (row, column), 
 0 | 1 | 2 
 3 | 4 | 5 
 6 | 7 | 8
cell is in sub-box 3*row/3 + column/3

*/
