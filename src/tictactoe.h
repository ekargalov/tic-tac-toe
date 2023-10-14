#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>

// ============
// class Player
// ============

class Player {
    // DATA
    std::string d_name;

public:
    // CREATORS
    Player(const std::string &name);

    // ACCESSORS
    const std::string &name() const;
};

// ===========
// class Field
// ===========

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
    Status status(int x, int y) const;

public:
    // CREATORS
    Field(int m, int n, int k);

    // MANIPULATORS
    Status makeMove(const Player &player, int x, int y);

    // ACCESSORS
    std::ostream &print(std::ostream &os) const;
};

inline
std::ostream &operator<<(std::ostream &os, const Field &field) {
    return field.print(os);
}

#endif
