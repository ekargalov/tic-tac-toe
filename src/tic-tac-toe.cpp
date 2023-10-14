#include "tic-tac-toe.h"

#include <vector>
#include <string>
#include <utility>

class Player {
    // DATA
    std::string d_name;

public:
    // CREATORS
    Player(const std::string &name)
            : d_name(name) {
    }

    // ACCESSORS
    const std::string &name() const {
        return d_name;
    }
};

class Field {
public:
    // PUBLIC TYPES
    enum Status {
        e_WIN = 0,
        e_CONTINUE,
        e_DRAW,
        e_ERROR
    };

private:
    // DATA
    std::vector<std::vector<const Player *>> d_grid;
    int d_k;
    int d_cellsLeft;

    // PRIVATE ACCESSORS
    Status status(int x, int y) const {
        const Player *p = d_grid[x][y];
        int m = d_grid.size();
        int n = d_grid.front().size();

        // Horizontal
        int counter = 1;
        for (int k = 1; y - k >= 0 && d_grid[x][y - k] == p; k++) {
            counter++;
        }
        for (int k = 1; y + k < n && d_grid[x][y + k] == p; k++) {
            counter++;
        }
        if (counter >= d_k) {
            return e_WIN;
        }

        // Vertical
        counter = 1;
        for (int k = 1; x - k >= 0 && d_grid[x - k][y] == p; k++) {
            counter++;
        }
        for (int k = 1; x + k < m && d_grid[x + k][y] == p; k++) {
            counter++;
        }
        if (counter >= d_k) {
            return e_WIN;
        }

        // Diagonal
        counter = 1;
        for (int k = 1; x - k >= 0 && y - k >= 0 && d_grid[x - k][y - k] == p; k++) {
            counter++;
        }
        for (int k = 1;
             x + k < m && y + k < n && d_grid[x + k][y + k] == p; k++) {
            counter++;
        }
        if (counter >= d_k) {
            return e_WIN;
        }

        // Anti-diagonal
        counter = 1;
        for (int k = 1; x - k >= 0 && y + k < n && d_grid[x - k][y + k] == p; k++) {
            counter++;
        }
        for (int k = 1; x + k < m && y - k >= 0 && d_grid[x + k][y - k] == p; k++) {
            counter++;
        }
        if (counter >= d_k) {
            return e_WIN;
        }

        if (d_cellsLeft == 0) {
            return e_DRAW;
        }

        return e_CONTINUE;
    }

public:
    // CREATORS
    Field(int m, int n, int k)
            : d_grid(m, {static_cast<std::size_t>(n), nullptr}),
              d_k(k),
              d_cellsLeft(m * n) {
    }

    // MANIPULATORS
    Status makeMove(const Player &player, int x, int y) {
        if (x >= d_grid.size() || y >= d_grid.back().size() || d_grid[x][y] != nullptr) {
            return e_ERROR;
        }
        d_grid[x][y] = &player;
        d_cellsLeft--;

        return status(x, y);
    }

    // ACCESSORS
    std::ostream &print(std::ostream &os) const {
        return os << "Printing game field ... TBD\n";
    }
};

std::ostream &operator<<(std::ostream &os, const Field &field) {
    return field.print(os);
}

void clearScreen() {
    system("cls");
}


int main() {
    Player player1("Mike");
    Player player2("Elliot");
    std::cout << "Welcome " << player1.name() << " and " << player2.name() << "\n";

    Field field(3, 3, 3);
    Field::Status status = Field::e_ERROR;

    status =  field.makeMove(player1, 0,0);
    status =  field.makeMove(player2, 1,2);
    status =  field.makeMove(player1, 1,0);
    status =  field.makeMove(player2, 1,1);
    status =  field.makeMove(player1, 2,0);

    std::cout << field;

    return 0;
}
