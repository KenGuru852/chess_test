#include "King.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Piece.h"

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

int King::check_Temp(int x, int y, vector<vector<int>> all_pieces_place, bool* any_one) const
{
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
    {
        if (all_pieces_place[x][y] != -1)
        {
            *any_one = false;
            cout << "Take " << pieces_name[all_pieces_place[x][y]] << " X = " << x << " Y = " << y << endl;
        }
    }
    return 0;
}

void King::check_Capture(vector<vector<int>> all_pieces_place) const
{
    bool any_one = true;
    cout << "* Piece " << piece_name << " with X = " << x << " and Y = " << y << " *" << endl << endl;

    int temp_x = x-1;
    int temp_y = y-1;

    King::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    temp_y++;
    King::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    temp_y++;
    King::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    temp_x++;
    King::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    temp_x++;
    King::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    temp_y--;
    King::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    temp_y--;
    King::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    temp_x--;
    King::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);

    if (any_one)
    {
        cout << "Doesn't take any piece" << endl;
    }
    cout << endl;
}
