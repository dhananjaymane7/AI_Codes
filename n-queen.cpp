#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int N)
{
    // If all queens are placed, return true
    if (col >= N) 
    {
        return true;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) 
    {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col, N)) 
        {
            // Place the queen
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1, N)) 
            {
                return true;
            }

            // If placing queen in board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0; // Backtrack
        }
    }

    // If the queen cannot be placed in any row in this column, then return false
    return false;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist";
        return;
    }

    // Print the solution
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;
    solveNQueens(N);
    return 0;
}


// The isSafe function checks whether it's safe to place a queen in a given position on the board by checking for conflicts with previously placed queens.
// The solveNQueenUtils function recursively tries to place queens in each column of the board, backtracking if a safe placement cannot be found.
// The solveNQueen function initializes the board and starts the backtracking process.