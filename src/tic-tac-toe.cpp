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
        if ((x >= d_grid.size()) || (x < 0) ||
            (y >= d_grid.back().size()) || (y < 0) || 
            (d_grid[x][y] != nullptr)) {

            return e_ERROR;
        }
        d_grid[x][y] = &player;
        d_cellsLeft--;

        return status(x, y);
    }

    void getGrid(const Player& player1, const Player& player2) const {
        for (auto row : d_grid) {
            for (auto item : row) {
                if (item == &player1) {
                    cout << "X" << " ";
                }
                else if (item == &player2) {
                    cout << "O" << " ";
                }
                else {
                    cout << "  ";
                }
            }
            cout << "\n";
        }
    }

private:
    vector<vector<const Player*>> d_grid;
    int d_k;
    int d_cellsLeft;

    Status status(int x, int y) const { // 0 -- win,  1 -- draw,  2 -- the game in progress
        const Player *p = d_grid[x][y];
        size_t m = d_grid.size();
        size_t n = d_grid.front().size();

        // Horizontal checking
        int counter = 1;
        for (int k = 1; (y - k) >= 0 && d_grid[x][y - k] == p; k++) {
            counter++;
        }
        for (int k = 1; (y + k) < n && d_grid[x][y + k] == p; k++) {
            counter++;
        }
        if (counter >= d_k) {
            return e_WIN;
        }

        // Vertical checking
        counter = 1;
        for (int k = 1; (x - k) >= 0 && d_grid[x - k][y] == p; k++) {
            counter++;
        }
        for (int k = 1; (x + k) < m && d_grid[x + k][y] == p; k++) {
            counter++;
        }
        if (counter >= d_k) {
            return e_WIN;
        }

        // Diagonal checking
        counter = 1;
        for (int k = 1; (x - k) >= 0 && (y - k) >= 0 && d_grid[x - k][y - k] == p; k++) {
            counter++;
        }
        for (int k = 1; (x + k) < m && (y + k) < n && d_grid[x + k][y + k] == p; k++) {
            counter++;
        }
        if (counter >= d_k) {
            return e_WIN;
        }

        // Anti-diagonal checking
        counter = 1;
        for (int k = 1; (x - k) >= 0 && (y + k) >= 0 && d_grid[x - k][y + k] == p; k++) {
            counter++;
        }
        for (int k = 1; (x + k) < m && (y - k) < n && d_grid[x + k][y - k] == p; k++) {
            counter++;
        }
        if (counter >= d_k) {
            return e_WIN;
        }

        if (d_cellsLeft == 0) {
            return e_DRAW;
        }

        return e_IN_PROGRESS;
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
    cout << "Welcome " << player1.getName() << " and " << player2.getName() << "\n";

    // DRAW TEST
    Field field(3, 3, 3);
    cout << field.makeMove(player1, 0, 0) << " ";
    cout << field.makeMove(player2, 1, 1) << " ";
    cout << field.makeMove(player1, 0, 1) << " ";
    cout << field.makeMove(player2, 1, 0) << " ";
    cout << field.makeMove(player1, 2, 2) << " ";
    cout << field.makeMove(player2, 2, 1) << " ";
    cout << field.makeMove(player1, 2, 0) << " ";
    cout << field.makeMove(player2, 1, 2) << " ";
    cout << field.makeMove(player1, 0, 2) << "\n";

    // HORIZONTAL WIN TEST
    Field field2(3, 3, 3);
    cout << field2.makeMove(player1, 0, 0) << " ";
    cout << field2.makeMove(player2, 1, 0) << " ";
    cout << field2.makeMove(player1, 0, 1) << " ";
    cout << field2.makeMove(player2, 1, 1) << " ";
    cout << field2.makeMove(player1, 0, 2) << "\n";

    // VERTICAL WIN TEST
    Field field3(3, 3, 3);
    cout << field3.makeMove(player1, 0, 0) << " ";
    cout << field3.makeMove(player2, 0, 1) << " ";
    cout << field3.makeMove(player1, 1, 0) << " ";
    cout << field3.makeMove(player2, 1, 1) << " ";
    cout << field3.makeMove(player1, 2, 0) << "\n";

    // DIAGONAL WIN TEST
    Field field4(3, 3, 3);
    cout << field4.makeMove(player1, 0, 0) << " ";
    cout << field4.makeMove(player2, 0, 1) << " ";
    cout << field4.makeMove(player1, 1, 1) << " ";
    cout << field4.makeMove(player2, 2, 1) << " ";
    cout << field4.makeMove(player1, 2, 2) << "\n";

    // ANTI-DIAGONAL WIN TEST
    Field field5(3, 3, 3);
    cout << field5.makeMove(player1, 0, 2) << " ";
    cout << field5.makeMove(player2, 0, 1) << " ";
    cout << field5.makeMove(player1, 1, 1) << " ";
    cout << field5.makeMove(player2, 1, 0) << " ";
    cout << field5.makeMove(player1, 2, 0) << "\n";

    // ERROR TEST
    Field field6(3, 3, 3);
    cout << field6.makeMove(player1, 0, 3) << " ";
    cout << field6.makeMove(player2, -1, 2) << " ";
    cout << field6.makeMove(player1, 3, 0) << " ";
    cout << field6.makeMove(player2, -1, 0) << " ";
    cout << field6.makeMove(player1, 0, 0) << " ";
    cout << field6.makeMove(player2, 0, 0) << " "; 

    // OUTPUT FIELD
    Field field_output(3, 3, 3);

    // First move player1
    clearScreen();
    field_output.makeMove(player1, 0, 0);
    field_output.getGrid(player1, player2); 
    
    // First move player2
    clearScreen();
    field_output.makeMove(player2, 0, 1);
    field_output.getGrid(player1, player2); 

    // Second move player1
    clearScreen();
    field_output.makeMove(player1, 1, 1);
    field_output.getGrid(player1, player2); 

    // Second move player2
    clearScreen();
    field_output.makeMove(player2, 2, 1);
    field_output.getGrid(player1, player2); 

    // Final move player1
    clearScreen();
    field_output.makeMove(player1, 2, 2);
    field_output.getGrid(player1, player2); 
    
    return 0;
}
	