#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Function to check if placing the queen at position (row, col) is safe
bool isSafe(const vector<int>& solution, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (solution[i] == row || abs(solution[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}
// Function to recursively find all solutions
void solveNQueens(int n, int col, vector<int>& solution, vector<vector<int>>& results) {
    if (col == n) {
        // Found a valid solution, store it
        results.push_back(solution);
        return;
    }
   // Try placing the queen in each row of the current column
    for (int row = 1; row <= n; row++) {
        if (isSafe(solution, row, col)) {
            solution[col] = row;
            solveNQueens(n, col + 1, solution, results);
        }
    }
}
// Function to solve the N-Queens problem
vector<vector<int>> nQueens(int n) {
    vector<vector<int>> results;
    vector<int> solution(n, 0);  // Stores one possible solution
    solveNQueens(n, 0, solution, results);
    return results;
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
   vector<vector<int>> solutions = nQueens(n);
    cout << "Distinct solutions for " << n << "-Queens problem:\n";
    for (const auto& solution : solutions) {
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << solution[i];
            if (i < n - 1) cout << ", ";
        }
        cout << "]\n";
    }
   return 0;
