#include "Rook.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Piece.h"

Rook::Rook(string new_name, int new_x, int new_y) : piece_name(new_name), x(new_x), y(new_y) {}

void Rook::insideGotoXY(short y, short x) const
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void Rook::piece_Drawer() const
{

    insideGotoXY(17 - 2 * y, 3 + 4 * x);
    cout << "roo";
    insideGotoXY(25, 25);
}

int Rook::check_Temp(int x, int y, vector<vector<int>> all_pieces_place, bool* any_one) const
{
    if (all_pieces_place[x][y] != -1)
    {
        *any_one = false;
        cout << "Take " << pieces_name[all_pieces_place[x][y]] << " X = " << x << " Y = " << y << endl;
        return 1;
    }
    return 0;
}

void Rook::check_Capture(vector<vector<int>> all_pieces_place) const
{
    bool any_one = true;
    cout << "* Piece " << piece_name << " with X = " << x << " and Y = " << y << " *" << endl << endl;
    for (int i = x - 1; i >= 0; i--)
    {
        int temp = Rook::check_Temp(i, y, all_pieces_place, &any_one);
        if (temp == 1) break;
    }
    for (int i = x + 1; i <= 7; i++)
    {
        int temp = Rook::check_Temp(i, y, all_pieces_place, &any_one);
        if (temp == 1) break;
    }
    for (int i = y - 1; i >= 0; i--)
    {
        int temp = Rook::check_Temp(x, i, all_pieces_place, &any_one);
        if (temp == 1) break;
    }
    for (int i = y + 1; i <= 7; i++)
    {
        int temp = Rook::check_Temp(x, i, all_pieces_place, &any_one);
        if (temp == 1) break;
    }
    if (any_one)
    {
        cout << "Doesn't take any piece" << endl;
    }
    cout << endl;
}
