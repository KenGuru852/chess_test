#include "King.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>


King::King(string new_name, int new_x, int new_y) : piece_name(new_name), x(new_x), y(new_y) {}

void King::insideGotoXY(short y, short x) const
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void King::piece_Drawer() const
{

    insideGotoXY(17 - 2 * y, 3 + 4 * x);
    cout << "kin";
    insideGotoXY(25, 25);
}

void King::check_Capture(vector<Piece> all_pieces) const
{
	cout << "Check_Capture" << endl;
}
