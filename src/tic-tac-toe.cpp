// tic-tac-toe.cpp: определяет точку входа для приложения.
//

#include "tic-tac-toe.h"

using namespace std;

/* class Field {
public:
    Field (int n, int m) {
        
    }

    bool makeMove(Player* player, int x, int y) {
        
    }

    int status(Player* player) { // 2 -- win, -2 -- fail, 0 -- the game in progress 1 -- draw, -1 -- other;
        
    }

private:
    vector<vector<Player*>> d_grid;
}; */

class Player {
public:
    Player(string p_name, bool p_isCross) {
        name = p_name;
        isCross = p_isCross;
    }

    string getName() {
        return name;
    }
private:
    string name;
    bool isCross;
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

    // cout << "Welcome " << name1 << " and " << name2;

    Player player1(name1, true);
    Player player2(name2, false);
    cout << player1.getName() << " " << player2.getName();
    return 0;
}
	