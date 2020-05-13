#include "Pathfinder.h"

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
    ifstream file (file_name.c_str());
    if (file.is_open()) {
        string line;
        int row_count = 0;
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
                    cout << value << endl;
                    //cout << "[" << row << "][" << col << "][" << len << "]" << value << endl;
                    maze_grid[row][col][len] = value;
                }
            }
        }
    }
    return true;
};
	
vector<string> Pathfinder::solveMaze() {
    for (int row = 0; row < ROW_SIZE; ++row)
    {
        // getline(file, line);
        // stringstream ss(line);
        for (int col = 0; col < COL_SIZE; ++col)
        {
            for (int len = 0; len < LEN_SIZE; ++len)
            {
                findPath(row, col, len);
            }
        }
    }
    resetMaze();
    for (int i = 0; i < solution.size(); ++ i) {
        cout << solution[i] << endl;
    }
    return solution;
};

bool Pathfinder::findPath(int x, int y, int z) {
    solution.push_back("(x, y, z)");
    if (x > ROW_SIZE || x < 0 || y > COL_SIZE || y < 0 || z > LEN_SIZE || y < 0 || maze_grid[x][y][z] != 1) {
        solution.pop_back();
        return false;
    }
    if (x == ROW_SIZE && y == COL_SIZE && z == LEN_SIZE) {
        return true;
    }
    maze_grid[x][y][z] = 2;
    if (findPath(x + 1, y, z) || findPath(x - 1, y, z) || findPath(x, y + 1, z) ||
        findPath(x, y - 1, z) || findPath(x, y, z + 1) || findPath(x, y, z - 1)) {
        return true;
    } else {
        solution.pop_back();
        return false;
    }
};

void Pathfinder::resetMaze() {
    for (int row = 0; row < ROW_SIZE; ++row) {
        for (int col = 0; col < COL_SIZE; ++col) {
            for (int len = 0; len < LEN_SIZE; ++len) {
                if (maze_grid[row][col][len] == 2) {
                    maze_grid[row][col][len] = 1;
                }
            }
        }
    }
}