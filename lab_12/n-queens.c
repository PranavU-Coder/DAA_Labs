#include <stdio.h>
#include <stdbool.h>

void print(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || (board[i] - i) == (col - row) || (board[i] + i) == (col + row))
            return false;
    }
    return true;
}

void solveNQueens(int board[], int row, int n) {
    if (row == n) {
        print(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; 
            solveNQueens(board, row + 1, n); 
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid input. N must be >= 1.\n");
        return 1;
    }

    int board[n]; 
    printf("Solutions for %d-Queens problem:\n\n", n);
    solveNQueens(board, 0, n);

    return 0;
}
