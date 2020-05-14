#include "Pathfinder.h"

Pathfinder::Pathfinder() {
    srand(time(0));
    for (int row = 0; row < ROW_SIZE; ++row) {
        for (int col = 0; col < COL_SIZE; ++col) {
            for (int len = 0; len < LEN_SIZE; ++len) {
                maze_grid[row][col][len] = BACKGROUND;
            }
        }
    }
};

Pathfinder::~Pathfinder() {

};

string Pathfinder::toString() const {
    stringstream ss;
    for (int row = 0; row < ROW_SIZE; ++row) {
        for (int col = 0; col < COL_SIZE; ++col) {
            for (int len = 0; len < LEN_SIZE; ++len) {
                if (len == 4) {
                    ss << maze_grid[row][col][len];
                } else {
                    ss << maze_grid[row][col][len] << " ";
                }
            }
            ss << endl;
        }
        if (row < 4) {
            ss << endl;
        }
    }
    return ss.str();
};

void Pathfinder::createRandomMaze() {
    for (int row = 0; row < ROW_SIZE; ++row) {
        for (int col = 0; col < COL_SIZE; ++col) {
            for (int len = 0; len < LEN_SIZE; ++len) {
                maze_grid[row][col][len] = rand() % 2;
            }
        }
    }
    maze_grid[0][0][0] = 1;
    maze_grid[4][4][4] = 1;
};

bool Pathfinder::importMaze(string file_name) {
    cout << "importMaze from " << file_name << endl;
    ifstream file(file_name.c_str());
    ifstream fileCheck(file_name.c_str());
    stringstream buffer;
    buffer << fileCheck.rdbuf();
    string maze = buffer.str();
    cout << maze.size();
    if (!isValid(maze)) {
        return false;
    }
    if (file.is_open()) {
        string line;
        for (int row = 0; row < ROW_SIZE; ++row) {
            for (int col = 0; col < COL_SIZE; ++col) {
                getline(file, line);
                while(line.length() == 0) {
                    getline(file, line);
                }
                stringstream ss(line);
                cout << line << endl;
                for (int len = 0; len < LEN_SIZE; ++len) {
                    int value;
                    ss >> value;
                    if(value > 1 || value < 0) {
                        return false;
                    }
                    //cout << "[" << row << "][" << col << "][" << len << "]" << value << endl;
                    maze_grid[row][col][len] = value;
                }
            }
        }
    } else {
        return false;
    } if (!isValid(maze)) {
        return false;
    }
    return true;
};
	
vector<string> Pathfinder::solveMaze() {
    solution.clear();
    findPath(maze_grid, 0, 0, 0);
    resetMaze();
    return solution;
};

bool Pathfinder::findPath(int maze[ROW_SIZE][COL_SIZE][LEN_SIZE], int x, int y, int z) {
    solution.push_back("(" + to_string(z) + ", " + to_string(y) + ", " + to_string(x) + ")");
    if (x >= ROW_SIZE || x < WALL || y >= COL_SIZE || y < WALL || z >= LEN_SIZE || z < WALL) {
        solution.pop_back();
        return false;
    } else if (maze[x][y][z] != BACKGROUND) {
        solution.pop_back();
        return false;
    } else if (x == ROW_SIZE - 1 && y == COL_SIZE - 1 && z == LEN_SIZE - 1) {
        maze[x][y][z] = PATH;
        //solution.push_back("(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")");
        return true;
    } else {
        //solution.push_back("(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")");
        maze[x][y][z] = TEMPORARY;
        if ((findPath(maze, x - 1, y, z) || findPath(maze, x + 1, y, z) || findPath(maze, x, y - 1, z) ||
            findPath(maze, x, y + 1, z) || findPath(maze, x, y, z - 1) || findPath(maze, x, y, z + 1)) && maze[x][y][z] != 0) {
            //cout << "here" << " " << endl;
            //solution.push_back("(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")");
            return true;
        } else {
            solution.pop_back();
            maze[x][y][z] = TEMPORARY;
            return false;
        }
    }
};

void Pathfinder::resetMaze() {
    for (int row = 0; row < ROW_SIZE; ++row) {
        for (int col = 0; col < COL_SIZE; ++col) {
            for (int len = 0; len < LEN_SIZE; ++len) {
                if (maze_grid[row][col][len] != 1 && maze_grid[row][col][len] != 0) {
                    maze_grid[row][col][len] = 1;
                }
            }
        }
    }
};

bool Pathfinder::isValid(string maze) {
    int count = 0;
    for (int i = 0; i < maze.length(); ++i) {
        if (maze[i] != ' ') {
            maze[count++] = maze[i];
        }
    }
    maze[count] = '\0';
    if (maze.size() != 253) {
        return false;
    } 
    if (maze_grid[0][0][0] != 1 || maze_grid[4][4][4] != 1) {
        return false;
    }
    return true;
}