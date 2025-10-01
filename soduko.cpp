#include <iostream>
#include <vector>
using namespace std;

#define N 9  // Sudoku size

// Function to print the board
void printBoard(vector<vector<int>> &board) {
    cout << "\n===== Sudoku Board =====\n";
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) cout << "---------------------\n";
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) cout << "| ";
            if (board[i][j] == 0) cout << ". ";
            else cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if placing num at (row, col) is valid
bool isValid(vector<vector<int>> &board, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) return false; // row
        if (board[x][col] == num) return false; // col
        if (board[3*(row/3) + x/3][3*(col/3) + x%3] == num) return false; // box
    }
    return true;
}

// Backtracking Sudoku Solver
bool solveSudoku(vector<vector<int>> &board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) { // empty cell
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) return true;
                        board[row][col] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true; // solved
}

// Check if board is fully filled
bool isComplete(vector<vector<int>> &board) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 0) return false;
    return true;
}

// Main Game Loop
int main() {
    // Example Sudoku puzzle (0 means empty)
    vector<vector<int>> board = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    cout << "Welcome to Sudoku ??\n";
    printBoard(board);

    while (true) {
        int row, col, num;
        cout << "\nEnter row col num (1-9) OR 0 0 0 to solve automatically: ";
        cin >> row >> col >> num;

        if (row == 0 && col == 0 && num == 0) {
            cout << "\nSolving with AI...\n";
            if (solveSudoku(board)) {
                printBoard(board);
                cout << "Solved! ??\n";
            } else {
                cout << "No solution exists ??\n";
            }
            break;
        }

        // Adjust for 0-based index
        row--; col--;

        if (row < 0 || row >= 9 || col < 0 || col >= 9 || num < 1 || num > 9) {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (board[row][col] != 0) {
            cout << "Cell already filled! ??\n";
        } else if (!isValid(board, row, col, num)) {
            cout << "Not valid move! ?\n";
        } else {
            board[row][col] = num;
            printBoard(board);

            if (isComplete(board)) {
                cout << "Congratulations! You solved it ????\n";
                break;
            }
        }
    }

    return 0;
}
