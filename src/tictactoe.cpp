#include "tictactoe.h"

// ------------
// class Player
// ------------

// CREATORS
Player::Player(const std::string &name)
        : d_name(name) {
}

// ACCESSORS
const std::string &Player::name() const {
    return d_name;
}

// -----------
// class Field
// -----------

// PRIVATE ACCESSORS
Field::Status Field::status(int x, int y) const {
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

// CREATORS
Field::Field(int m, int n, int k)
        : d_grid(m, {static_cast<std::size_t>(n), nullptr}),
          d_k(k),
          d_cellsLeft(m * n) {
}

// MANIPULATORS
Field::Status Field::makeMove(const Player &player, int x, int y) {
    if (x >= d_grid.size() || y >= d_grid.back().size() || d_grid[x][y] != nullptr) {
        return e_ERROR;
    }
    d_grid[x][y] = &player;
    d_cellsLeft--;

    return status(x, y);
}

// ACCESSORS
std::ostream &Field::print(std::ostream &os) const {
    return os << "Printing game field ... TBD\n";
}
