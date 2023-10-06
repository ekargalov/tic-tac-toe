// tic-tac-toe.cpp: определяет точку входа для приложения.
//

#include "tic-tac-toe.h"

using namespace std;

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

    cout << "Welcome " << name1 << " and " << name2;
	return 0;
}
	