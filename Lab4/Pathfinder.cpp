#include "Pathfinder.h"

string Pathfinder::toString() const {
    stringstream ss;
    for (int row = 0; row < ROW_SIZE; ++row) {
        for (int col = 0; col < COL_SIZE; ++col) {
            for (int len = 0; len < LEN_SIZE; ++len) {
                ss << maze_grid[row][col][len];
            }
            ss << endl;
        }
        ss << endl;
    }
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
            getline(file, line);
            stringstream ss(line);
            for (int col = 0; col < COL_SIZE; ++col) {
                for (int len = 0; len < LEN_SIZE; ++len) {
                }
            }
        }
    }
};
	
vector<string> Pathfinder::solveMaze() {

};