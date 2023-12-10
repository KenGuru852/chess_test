#include "Queen.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Piece.h"

Queen::Queen(string new_name, int new_x, int new_y) : piece_name(new_name), x(new_x), y(new_y) {}

void Queen::insideGotoXY(short y, short x) const
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void Queen::piece_Drawer() const
{

    insideGotoXY(17 - 2 * y, 3 + 4 * x);
    cout << "que";
    insideGotoXY(25, 25);
}

int Queen::check_Temp(int x, int y, vector<vector<int>> all_pieces_place, bool* any_one) const
{
    if (all_pieces_place[x][y] != -1)
    {
        *any_one = false;
        cout << "Take " << pieces_name[all_pieces_place[x][y]] << " X = " << x << " Y = " << y << endl;
        return 1;
    }
    return 0;
}

void Queen::check_Capture(vector<vector<int>> all_pieces_place) const
{
    bool any_one = true;
    cout << "* Piece " << piece_name << " with X = " << x << " and Y = " << y << " *" << endl << endl;
    for (int i = x - 1; i >= 0; i--)
    {
        int temp = Queen::check_Temp(i, y, all_pieces_place, &any_one);
        if (temp == 1) break;
    }
    for (int i = x + 1; i <= 7; i++)
    {
        int temp = Queen::check_Temp(i, y, all_pieces_place, &any_one);
        if (temp == 1) break;
    }
    for (int i = y - 1; i >= 0; i--)
    {
        int temp = Queen::check_Temp(x, i, all_pieces_place, &any_one);
        if (temp == 1) break;
    }
    for (int i = y + 1; i <= 7; i++)
    {
        int temp = Queen::check_Temp(x, i, all_pieces_place, &any_one);
        if (temp == 1) break;
    }
    int temp = y + 1;
    for (int i = x + 1; i <= 7; i++)
    {
        if (temp == 8) break;
        int temp_2 = Queen::check_Temp(i, temp, all_pieces_place, &any_one);
        if (temp_2) break;
        temp++;
    }
    temp = y + 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (temp == 8) break;
        int temp_2 = Queen::check_Temp(i, temp, all_pieces_place, &any_one);
        if (temp_2) break;
        temp++;
    }
    temp = y - 1;
    for (int i = x + 1; i <= 7; i++)
    {
        if (temp == -1) break;
        int temp_2 = Queen::check_Temp(i, temp, all_pieces_place, &any_one);
        if (temp_2) break;
        temp--;
    }
    temp = y - 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (temp == -1) break;
        int temp_2 = Queen::check_Temp(i, temp, all_pieces_place, &any_one);
        if (temp_2) break;
        temp--;
    }
    if (any_one)
    {
        cout << "Doesn't take any piece" << endl;
    }
    cout << endl;
}
