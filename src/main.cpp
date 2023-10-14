#include "tictactoe.h"

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