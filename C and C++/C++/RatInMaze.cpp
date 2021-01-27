#include <iostream>
#include <iomanip>
#define N 4
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

bool isSafe(int x, int y, int maze[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUntil(int x, int y, int sol[N][N], int maze[N][N])
{
    //Destination is Reached
    if (x == N - 1 & y == N - 1)
    {
        sol[x][y] = 1;
        return true;
    }

    //check if maze[x][y] is valid
    if (isSafe(x, y, maze))
    {
        sol[x][y] = 1;

        //Move forward in x direction
        if (solveMazeUntil(x + 1, y, sol, maze) == true)
            return true;

        /* If moving in x direction doesn't give solution then 
           Move down in y direction  */
        if (solveMazeUntil(x, y + 1, sol, maze) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:  
            unmark x, y as part of solution path */
        sol[x][y] = 0;
    }
    return false;
}

void solveMaze()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};
    int sol[N][N] = {0};

    if (solveMazeUntil(0, 0, sol, maze) == false)
        printf("Solution doesn't exist");
    else
        printSolution(sol);
}

int main()
{
    solveMaze();
}