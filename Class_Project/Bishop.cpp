#include "Bishop.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Piece.h"

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

int Bishop::check_Temp(int x, int y, vector<vector<int>> all_pieces_place, bool* any_one) const
{
    if (all_pieces_place[x][y] != -1)
    {
        *any_one = false;
        cout << "Take " << pieces_name[all_pieces_place[x][y]] << " X = " << x << " Y = " << y << endl;
        return 1;
    }
    return 0;
}

void Bishop::check_Capture(vector<vector<int>> all_pieces_place) const
{
    bool any_one = true;
    cout << "* Piece " << piece_name << " with X = " << x << " and Y = " << y << " *" << endl << endl;

    int temp = y + 1;
    for (int i = x + 1; i <= 7; i++)
    {
        if (temp == 8) break;
        int temp_2 = Bishop::check_Temp(i, temp, all_pieces_place, &any_one);
        if (temp_2) break;
        temp++;
    }
    temp = y + 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (temp == 8) break;
        int temp_2 = Bishop::check_Temp(i, temp, all_pieces_place, &any_one);
        if (temp_2) break;
        temp++;
    }
    temp = y - 1;
    for (int i = x + 1; i <= 7; i++)
    {
        if (temp == -1) break;
        int temp_2 = Bishop::check_Temp(i, temp, all_pieces_place, &any_one);
        if (temp_2) break;
        temp--;
    }
    temp = y - 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (temp == -1) break;
        int temp_2 = Bishop::check_Temp(i, temp, all_pieces_place, &any_one);
        if (temp_2) break;
        temp--;
    }
    if (any_one)
    {
        cout << "Doesn't take any piece" << endl;
    }
    cout << endl;
}
