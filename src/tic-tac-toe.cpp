// tic-tac-toe.cpp: определяет точку входа для приложения.
//

#include "tic-tac-toe.h"

#include <vector>
#include <string>

using namespace std;

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
	