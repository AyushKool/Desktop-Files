#include <iostream>
#include <iomanip>
#define N 8
using namespace std;

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setw(3) << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == 0);
}

bool solveKTUntil(int x, int y, int move, int sol[N][N], int xMoves[], int yMoves[])
{
    int k = 0, nextX, nextY;
    if (move == N*N + 1)
        return true;

    /* Try all next moves from the current coordinate x, y */
    for (k = 0; k < 8; k++)
    {
        nextX = x + xMoves[k];
        nextY = y + yMoves[k];
        if (isSafe(nextX, nextY, sol))
        {
            sol[nextX][nextY] = move;
            if (solveKTUntil(nextX, nextY, move + 1, sol, xMoves, yMoves) == true)
                return true;
            else
                sol[nextX][nextY] = 0; // backtracking
        }
    }
    return false;
}

void solveKT()
{
    int sol[N][N] = {0};
    sol[0][0] = 1;
    int xMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    if (solveKTUntil(0, 0, 2, sol, xMoves, yMoves) == false)
    {
        cout << "Solution doesn't exist";
        return;
    }
    else
        printSolution(sol);
}

int main()
{
    solveKT();
}