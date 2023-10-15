#include "tic-tac-toe.h"

#include <vector>
#include <string>

using namespace std;

class Player {
public:
    Player(string name)
    : d_name(name)
    {    
    }

    string getName() {
        return d_name;
    }

private:
    string d_name;
};

class Field {
public:
    enum Status { 
    e_WIN = 0, 
    e_DRAW,
    e_IN_PROGRESS, 
    e_ERROR
    };

    Field (int m, int n, int k) 
        : d_k(k),
        d_cellsLeft(m * n)
    {
        for (int i = 0; i < m; i++) {
            d_grid.push_back({});
            for (int j = 0; j < n; j++) {
                d_grid.back().push_back(nullptr);
            }
        }
    }

    Status makeMove(const Player& player, int x, int y) {
        if ((x >= d_grid.size()) || (y >= d_grid.back().size()) || (d_grid[x][y] != nullptr)) {
            return e_ERROR;
        }
        d_grid[x][y] = &player;
        d_cellsLeft--;
    }

private:
    vector<vector<const Player*>> d_grid;
    int d_k;
    int d_cellsLeft;

    Status status(int x, int y) const { // 0 -- win,  1 -- draw,  2 -- the game in progress
        const Player *p = d_grid[x][y];
        int m = d_grid.size();
        int n = d_grid.front().size();

        // Horizontal checking
        int counter = 1;
        for (int k = 1; y - k >= 0 && d_grid[x][y - k] == p; k++) {
            counter++;
        }
        for (int k = 1; y + k >= 0 && d_grid[x][y + k] == p; k++) {
            counter++;
        }
        if (counter == d_k) {
            return e_WIN;
        }
    }
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

    Player player1(name1);
    Player player2(name2);
    Field field(3, 3, 3);

    cout << "Welcome " << player1.getName() << " and " << player2.getName();
    return 0;
}
	