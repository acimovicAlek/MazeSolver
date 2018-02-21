#include <random>
#include <QDebug>
#include <cstdio>
#include <vector>
#include <iostream>
#include <logictoolbox/Universe.h>

#include "maze.h"

int Maze::getWidth() const
{
    return width;
}

void Maze::setWidth(int value)
{
    width = value;
}

int Maze::getHeight() const
{
    return height;
}

void Maze::setHeight(int value)
{
    height = value;
}

void Maze::initMaze()
{
    map = std::vector<std::vector<int> > (height, std::vector<int>(width));
    for (int i = 0; i < height; i++)
        map[i] = std::vector<int>(width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            map[i][j] = 1;
}

void Maze::generateMaze()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disHeight(0, height-1);
    std::uniform_int_distribution<> disWidth(0, width-1);

    int r = disHeight(gen);
    while (r % 2 == 0) {
        r = disHeight(gen);
    }
    int c = disWidth(gen);
    while (c % 2 == 0) {
        c = disWidth(gen);
    }
    map[r][c] = 0;

    mazeUniverse->addVariable("x");
    World* terminal = new World(to_string(r) + ", " + to_string(c));
    Variable variable = Variable("x");
    vector<Variable> variables;
    variables.push_back(variable);
    variable.setValue(false);
    terminal->setVariables(variables);

    worlds.push_back(terminal);

    recursion(r, c, terminal);

    // Exit position
    mazeUniverse->setWorlds(worlds);
    map[height-2][width-2] = 2;
}

void Maze::recursion(int r, int c, World* prev)
{
    std::vector<int> randDirs = generateRandomDirections();
    for (int i = 0; i < 4; i++) {

        switch(randDirs[i]){
        case 1: // Up
            if (r - 2 <= 0)
                continue;
            if (map[r - 2][c] != 0) {

                World* first = nullptr;
                World* second = nullptr;
                if(map[r-1][c] == 0){
                    for(auto i: worlds){
                        if(i->getName() == to_string(r-1) + ", " + to_string(c)) first = i;
                    }
                }else {
                    first = new World(to_string(r - 1) + ", " + to_string(c));
                    Variable f_variable = Variable("x");
                    f_variable.setValue(false);
                    vector<Variable> variables;
                    variables.push_back(f_variable);
                    first->setVariables(variables);
                    worlds.push_back(first);
                }
                second = new World(to_string(r-2) + ", " + to_string(c));
                Variable s_variable = Variable("x");
                s_variable.setValue((height-2 == r-2 && width-2 == c)?true:false);
                vector<Variable> variables;
                variables.push_back(s_variable);
                second->setVariables(variables);
                worlds.push_back(second);

                prev->addAdjacent(first);
                first->addAdjacent(second);

                map[r-2][c] = 0;
                map[r-1][c] = 0;

                recursion(r - 2, c, second);
            }
            break;
        case 2: // Right
            if (c + 2 >= width - 1)
                continue;
            if (map[r][c + 2] != 0) {

                World* first = nullptr;
                World* second = nullptr;
                if(map[r][c+1] == 0){
                    for(auto i: worlds){
                        if(i->getName() == to_string(r) + ", " + to_string(c + 1)) first = i;
                    }
                }else {
                    first = new World(to_string(r) + ", " + to_string(c + 1));
                    Variable f_variable = Variable("x");
                    f_variable.setValue(false);
                    vector<Variable> variables;
                    variables.push_back(f_variable);
                    first->setVariables(variables);
                    worlds.push_back(first);
                }

                second = new World(to_string(r) + ", " + to_string(c + 2));
                Variable s_variable = Variable("x");
                s_variable.setValue((height - 2 == r && width - 2 == c + 2) ? true : false);
                vector<Variable> variables;
                variables.push_back(s_variable);
                second->setVariables(variables);
                worlds.push_back(second);

                prev->addAdjacent(first);
                first->addAdjacent(second);

                map[r][c + 2] = 0;
                map[r][c + 1] = 0;

                recursion(r, c + 2, second);
            }
            break;
        case 3: // Down
            if (r + 2 >= height - 1)
                continue;
            if (map[r + 2][c] != 0) {

                World* first = nullptr;
                World* second = nullptr;
                if(map[r+1][c] == 0){
                    for(auto i: worlds){
                        if(i->getName() == to_string(r+1) + ", " + to_string(c) ) first = i;
                    }
                }else {
                    first = new World(to_string(r + 1) + ", " + to_string(c));
                    Variable f_variable = Variable("x");
                    f_variable.setValue(false);
                    vector<Variable> variables;
                    variables.push_back(f_variable);
                    first->setVariables(variables);
                    worlds.push_back(first);
                }

                second = new World(to_string(r+2) + ", " + to_string(c));
                Variable s_variable = Variable("x");
                s_variable.setValue((height-2 == r+2 && width-2 == c)?true:false);
                vector<Variable> variables;
                variables.push_back(s_variable);
                second->setVariables(variables);
                worlds.push_back(second);

                prev->addAdjacent(first);
                first->addAdjacent(second);

                map[r+2][c] = 0;
                map[r+1][c] = 0;

                recursion(r + 2, c, second);
            }
            break;
        case 4: // Left
            if (c - 2 <= 0)
                continue;
            if (map[r][c - 2] != 0) {

                World* first = nullptr;
                World* second = nullptr;

                if(map[r][c-1] == 0){
                    for(auto i: worlds){
                        if(i->getName() == to_string(r) + ", " + to_string(c - 1)) first = i;
                    }
                }else {
                    first = new World(to_string(r) + ", " + to_string(c - 1));
                    Variable f_variable = Variable("x");
                    f_variable.setValue(false);
                    vector<Variable> variables;
                    variables.push_back(f_variable);
                    first->setVariables(variables);
                    worlds.push_back(first);
                }
                second = new World(to_string(r) + ", " + to_string(c-2));
                Variable s_variable = Variable("x");
                s_variable.setValue((height -2 == r && width-2 == c-2)?true:false);
                vector<Variable> variables;
                variables.push_back(s_variable);
                second->setVariables(variables);
                worlds.push_back(second);

                prev->addAdjacent(first);
                first->addAdjacent(second);

                map[r][c - 2] = 0;
                map[r][c - 1] = 0;

                recursion(r, c - 2, second);
            }
            break;
        }
    }
}

std::vector<int> Maze::generateRandomDirections()
{
    std::vector<int> res;
    for (int i = 0; i < 4; i++)
        res.push_back(i+1);
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(res.begin(), res.end(), g);
    return res;
}


Maze::Maze(int _w, int _h)
{
    width = _w;
    height = _h;
    mazeUniverse = new Universe("Maze");
    initMaze();
    generateMaze();
    //printMaze();
}

void Maze::printMaze()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << map[i][j]<< " ";
        std::cout << std::endl;
    }
}

int Maze::at(int i, int j)
{
    return map[i][j];
}

void Maze::set(int i, int j, int val)
{
    map[i][j] = val;
}

Universe* Maze::getMazeUniverse() const {
    return mazeUniverse;
}
