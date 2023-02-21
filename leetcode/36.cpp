class Solution {
public:
    bool nok(bitset<10> &used, char x) {
        if ( x == '.') return false;
        else if (!used[x-'0']) return used[x-'0'] = 1, false;
        else return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            bitset<10> used{}, used2{};
            for (int j = 0; j < 9; ++j) {
                //row
                if( nok(used, board[i][j]) ) return false;

                // column
                if ( nok(used2, board[j][i]) ) return false;
            }
        }

        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                bitset<10> used{};
                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        if ( nok(used, board[x][y]) ) return false;
                    }
                }
            }
        }
        return true;
    }
};