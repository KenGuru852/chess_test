#include "Knight.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>


Knight::Knight(string new_name, int new_x, int new_y) : piece_name(new_name), x(new_x), y(new_y) {}

void Knight::insideGotoXY(short y, short x) const
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void Knight::piece_Drawer() const
{

    insideGotoXY(17 - 2 * y, 3 + 4 * x);
    cout << "kni";
    insideGotoXY(25, 25);
}

void Knight::check_Capture(vector<Piece> all_pieces) const
{
    cout << "Check_Capture" << endl;
}
