// tic-tac-toe.cpp: определяет точку входа для приложения.
//

#include "tic-tac-toe.h"

#include <vector>
#include <string>

using namespace std;

enum class Status {fail = -2, other, inProgress, draw, win};

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

    bool isCross() {
        return d_isCross;
    }

private:
    string d_name;
    bool d_isCross;
};

class Field {
public:
    Field (int n) {
        for (int i = 1; i <= n; ++i) {
            d_grid.push_back({});
            for (int j = 1; j <= n; ++j) {
                d_grid.back().push_back(nullptr);
            }
        }
    }

    bool makeMove(const Player& player, int x, int y) {
        if (d_grid[x][y] == nullptr) {
            d_grid[x][y] = &player;
            return true;
        }
        return false;
    }

    Status status(const Player& player) { // 2 -- win, -2 -- fail, 0 -- the game in progress 1 -- draw, -1 -- other;
        for (int i = 1; i <= d_grid.size(); ++i) {
            for (int j = 1; j <= d_grid.size(); ++j) {
                if (d_grid[i][j] == nullptr) {
                    return inProgress;
                }
                else {
                    return draw;
                }
            }
        }
    }
    
private:
    using enum Status;
    vector<vector<const Player*>> d_grid;
};

void clearScreen() {
    system("cls");
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

    cout << "Welcome " << player1.getName() << " and " << player2.getName();
    return 0;
}
	