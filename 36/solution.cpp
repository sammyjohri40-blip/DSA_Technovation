#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current = board[i][j];
                if (current == '.') continue;
                
                string rowKey = to_string(i) + "r" + current;
                string colKey = to_string(j) + "c" + current;
                string boxKey = to_string(i / 3) + "_" + to_string(j / 3) + "b" + current;
                
                // If any of these keys already exist, the Sudoku is invalid
                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                    return false;
                }
                
                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }
        
        return true;
    }
};
