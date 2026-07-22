class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /* parse input: store rows, columns and boxes as sets
             iterate over chars
             --> create hash map of sets for rows, columns, boxes
             --> for each char, check if already exists in respective sets of row, column and box
                    --> if yes, return false
                    --> if no, insert to respective sets and continue to next char
            after all chars passed, return true.
        */
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> boxes;

        for (int row{0}; row < 9; ++row) {
            for (int col{0}; col < 9; ++col) {
                char number{board[row][col]};
                if (number == '.') continue;

                // check for rows and columns
                if (rows[row].count(number) || cols[col].count(number)) {
                    return false;
                }

                // check for boxes
                pair<int, int> boxNumber = {row/3, col/3};
                if (boxes[boxNumber].count(number)) {
                    return false;
                }

                // insert to respective sets
                rows[row].insert(number);
                cols[col].insert(number);
                boxes[boxNumber].insert(number);
            }
        }
        return true;
    }
};
