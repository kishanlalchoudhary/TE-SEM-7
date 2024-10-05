#include <iostream>
#include <vector>
using namespace std;

void solve(int row, int &n, vector<vector<int>> &board, vector<int> &column, vector<int> &leftDiagonal, vector<int> &rightDiagonal, vector<vector<vector<int>>> &result)
{
    if (row == n)
    {
        // Add current board to result vector
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        // Check queen can be placed or not
        if (!column[col] && !leftDiagonal[row + col] && !rightDiagonal[n + col - row - 1])
        {
            // Place the queen and update status of column, left diagonal and right diagonal to block
            board[row][col] = 1;
            column[col] = 1;
            leftDiagonal[row + col] = 1;
            rightDiagonal[n + col - row - 1] = 1;

            // Invoke solve function for moving to next row
            solve(row + 1, n, board, column, leftDiagonal, rightDiagonal, result);

            // Remove the queen and update status of column, left diagonal and right diagonal to unblock
            board[row][col] = 0;
            column[col] = 0;
            leftDiagonal[row + col] = 0;
            rightDiagonal[n + col - row - 1] = 0;
        }
    }
    return;
}

vector<vector<vector<int>>> solveNQueen(int n, vector<vector<int>> board)
{
    // Initialize vectors to store column, left diagonal and right diagonal
    vector<int> column(n, 0);
    vector<int> leftDiagonal(2 * n - 1, 0);
    vector<int> rightDiagonal(2 * n - 1, 0);

    // Initialize result vector
    vector<vector<vector<int>>> result;

    // Invoke solve function to get results and store them in result vector
    solve(0, n, board, column, leftDiagonal, rightDiagonal, result);
    return result;
}

int main()
{
    // Input size of board
    int n;
    cin >> n;

    // Iitialize empty board
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Invoke solve NQueen function to get results
    vector<vector<vector<int>>> result = solveNQueen(n, board);

    // Display results
    cout << endl;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << result[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}