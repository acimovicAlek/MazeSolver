#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "maze.h"
#include <vector>


typedef std::pair< int, int > Point;
typedef std::tuple< int, int, Point > Node;

class MazeSolver
{
public:
    enum SolverType
        {
            BACKTRACKING,
            ASTAR,
            SIMPLEBOOLEAN,
            MODAL_LOGIC
        };
private:
    Maze* maze;
    SolverType solver;
    bool isPositionSafe(int x, int y);
    std::vector<std::pair<int, int> > visited;
    int mDistance(const Point &a, const Point &b);
    bool goalReached(int x, int y);
public:
    MazeSolver(Maze* _maze, SolverType _solver);
    bool solve();
    std::vector<std::pair<int, int> > getPath() const;
    SolverType getSolver() const;
    void setSolver(const SolverType &value);

    bool solveMazeWithBacktracking(int x, int y);
    bool solveMazeWithAstar(int x, int y);
    bool solveMazeWithSimpleBoolean(int x, int y);
    bool solveMazeWithModalLogic();
};

#endif // MAZESOLVER_H
