#include "Knight.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Piece.h"

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

int Knight::check_Temp(int x, int y, vector<vector<int>> all_pieces_place, bool* any_one) const
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

void Knight::check_Capture(vector<vector<int>> all_pieces_place) const
{
    bool any_one = true;
    cout << "* Piece " << piece_name << " with X = " << x << " and Y = " << y << " *" << endl << endl;

    int temp_x = x - 1;
    int temp_y = y + 2;

    Knight::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    Knight::check_Temp(temp_x, temp_y-4, all_pieces_place, &any_one);
    temp_x += 2;
    Knight::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    Knight::check_Temp(temp_x, temp_y-4, all_pieces_place, &any_one);
    temp_x = x - 2;
    temp_y = y + 1;
    Knight::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    Knight::check_Temp(temp_x+4, temp_y, all_pieces_place, &any_one);
    temp_y -= 2;
    Knight::check_Temp(temp_x, temp_y, all_pieces_place, &any_one);
    Knight::check_Temp(temp_x+4, temp_y, all_pieces_place, &any_one);

    if (any_one)
    {
        cout << "Doesn't take any piece" << endl;
    }
    cout << endl;
}
