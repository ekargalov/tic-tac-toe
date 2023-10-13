// tic-tac-toe.cpp: определяет точку входа для приложения.
//

#include "tic-tac-toe.h"

#include <vector>
#include <string>

using namespace std;

enum Status { 
    e_WIN = 0, 
    e_DRAW,
    e_IN_PROGRESS
};

class Player {
public:
    Player(string name, bool isCross)
    : d_name(name),
    d_isCross(isCross)
    {    
    }

    string getName() {
        return d_name;
    }

    bool getIsCross() {
        return d_isCross;
    }

private:
    string d_name;
    bool d_isCross;
};

class Field {
public:
    Field (int n) {
        for (int i = 0; i < n; ++i) {
            d_grid.push_back({});
            for (int j = 0; j < n; ++j) {
                d_grid.back().push_back(nullptr);
            }
        }
    }

    bool makeMove(const Player& player, int x, int y) {
        if ((x < d_grid.size()) && (y < d_grid[x].size())) { // Please check the condition
            if (d_grid[x][y] == nullptr) {
                d_grid[x][y] = &player;
                return true;
            }
        }
        return false;
    }

    Status status(const Player& player) { // 0 -- win,  1 -- draw,  2 -- the game in progress
        for (int i = 0; i < d_grid.size(); ++i) {
            for (int j = 0; j < d_grid[i].size(); ++j) {
                if ((checkWinDiagonals() == true) && (checkWinRows() == true) && (checkWinColumns() == true)) {
                    return e_WIN;
                }
                else if (checkInProgress() == true) {
                    return e_IN_PROGRESS;
                }
                else {
                    return e_DRAW;
                }
            }
        }
    }
    
private:
    vector<vector<const Player*>> d_grid;
};

void clearScreen() {
    system("cls");
}

// Functions for checking the win
bool checkWinDiagonals() { // I don't know, what pass to the function
    for (int i = 0; i < d_grid.size(); ++i) {
        for (int j = 0; j < d_grid[i].size(); ++j) {

            if (d_grid[0][0] != nullptr) {
                if ((d_grid[i][j] == d_grid[i + 1][j + 1]) && (d_grid[i + 1][j + 1] == d_grid[i + 2][j + 2])) {
                    return true;
                }
            }

            else if (d_grid[0][d_grid[i].size() - 1] != nullptr) {
                if ((d_grid[i][j] == d_grid[i + 1][j - 1]) && (d_grid[i + 1][j - 1] == d_grid[i + 2][j - 2])) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkWinRows() {
    for (int i = 0; i < d_grid.size(); ++i) {
        for (int j = 0; j < d_grid[i].size(); ++j) {
            if (d_grid[i][0] != nullptr) {
                if ((d_grid[i][j] == d_grid[i][j + 1]) && (d_grid[i][j] == d_grid[i][j + 2])) {
                    return true;
                }
            }
        }
    }
    return false;
}


bool checkWinColumns() {
    for (int i = 0; i < d_grid.size(); ++i) {
        for (int j = 0; j < d_grid[i].size(); ++j) {
            if (d_grid[0][j] != nullptr) {
                if ((d_grid[i][j] == d_grid[i + 1][j]) && (d_grid[i][j] == d_grid[i + 2][j])) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkInProgress() {
    for (int i = 0; i < d_grid.size(); ++i) {
        for (int j = 0; j < d_grid[i].size(); ++j) {
            if (d_grid[i][j] == nullptr) {
                return true;   
            }
        }
    }
    return false;
}

int main()
{
    string name1, name2;

    cout << "Enter the name of first player:\n";
    cin >> name1;
    clearScreen();

    cout << "Enter the name of second player:\n";
    cin >> name2;
    clearScreen();

    Player player1(name1, true);
    Player player2(name2, false);
    Field field(3);

    cout << "Welcome " << player1.getName() << " and " << player2.getName();
    return 0;
}
	