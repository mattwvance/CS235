#include "Pathfinder.h"

string Pathfinder::toString() const {
    stringstream ss;
    for (int row = 0; row < ROW_SIZE; ++row) {
        for (int col = 0; col < COL_SIZE; ++col) {
            for (int len = 0; len < LEN_SIZE; ++len) {
                ss << maze_grid[row][col][len] << " ";
            }
            ss << endl;
        }
        ss << endl;
    }
    return ss.str();
};

void Pathfinder::createRandomMaze() {

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
                stringstream ss(line);
                for (int len = 0; len < LEN_SIZE; ++len) {
                    int value;
                    ss >> value;
                    //cout << "[" << row << "][" << col << "][" << len << "]" << value << endl;
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
    return solution;
};

bool Pathfinder::findPath(int x, int y, int z) {
    solution.push_back("(x, y, z)");
    if (x > ROW_SIZE || y > COL_SIZE || z > LEN_SIZE || maze_grid[x][y][z] != 1) {
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