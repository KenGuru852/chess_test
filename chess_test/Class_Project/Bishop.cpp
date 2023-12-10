#include "Bishop.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>


Bishop::Bishop(string new_name, int new_x, int new_y) : piece_name(new_name), x(new_x), y(new_y) {}

void Bishop::insideGotoXY(short y, short x) const
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void Bishop::piece_Drawer() const
{

    insideGotoXY(17 - 2 * y, 3 + 4 * x);
    cout << "bis";
    insideGotoXY(25, 25);
}

void Bishop::check_Capture(vector<Piece> all_pieces) const
{
    cout << "Check_Capture" << endl;
}
