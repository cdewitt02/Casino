#include <iostream>


#define N 9
using namespace std;
bool IsEmptySpot(int &row, int &col, int grid[N][N]);
bool checkGrid(int r, int c, int num, int grid[N][N]);

bool SolvePuzzle(int grid[N][N]) {
    int row , col;
    if (!IsEmptySpot(row, col, grid))
        return true;
    for(int i = 1; i <= N; i++){
        if(checkGrid(row, col, i, grid)){
            grid[row][col] = i;
            if(SolvePuzzle(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}
bool IsEmptySpot(int &row, int &col, int grid[N][N]) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}
bool InRow(int r, int grid[N][N], int num){
    int col = 0;
    while(col < N){
        if(grid[r][col] == num)
            return true;
        col++;
    }
    return false;
}
bool InSquare(int r, int c, int num, int grid[N][N]){
    bool p = false;
    for(int n = 0; n < 3; n++)
        for(int col = 0; col < 3; col++)
            if(grid[r+n][c+col] == num)
                p = true;
    return p;
}
bool InColumn(int c, int grid[N][N], int num){
    for(int r = 0; r < N; r++)
        if (grid[r][c] == num)
            return true;
    return false;

}
bool checkGrid(int r, int c, int num, int grid[N][N]){
    return (!InRow(r, grid, num) && !InColumn(c, grid, num) && !InSquare( (r - r % 3), (c - c % 3), num, grid));
}
void printgrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
            if (j == (N - 1))
                cout << "\n";
        }

    }
}
int main() {
    int grid[N][N] = {5, 3, 0, 0, 7, 0, 0, 0, 0,
                      6, 0, 0, 1, 9, 5, 0, 0, 0,
                      0, 9, 8, 0, 0, 0, 0, 6, 0,
                      8, 0, 0, 0, 6, 0, 0, 0, 3,
                      4, 0, 0, 8, 0, 3, 0, 0, 1,
                      7, 0, 0, 0, 2, 0, 0, 0, 6,
                      0, 6, 0, 0, 0, 0, 2, 8, 0,
                      0, 0, 0, 4, 1, 9, 0, 0, 5,
                      0, 0, 0, 0, 8, 0, 0, 7, 9};
    if (SolvePuzzle(grid) == true)
        printgrid(grid);
    else
        cout << "Puzzle has no solution";
    return 0;
};