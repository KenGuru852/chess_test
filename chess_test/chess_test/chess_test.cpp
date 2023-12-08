#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>


using namespace std;

const string pieces_name[5] = {"king", "queen", "rook", "bishop", "knight"};

struct piece
{
    string name;
    int x;
    int y;
};

void gotoXY(short x, short y)
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

int inputChecker(piece check_piece)
{
    bool is_name = false;
    for (auto& x : pieces_name)
    {
        if (check_piece.name == x)
        {
            is_name = true;
            break;
        }
    }
    if (!is_name)
    {        
        return -1;
    }
    if (!(check_piece.x >= 0 && check_piece.x <= 7))
    {
        return -2;
    }
    if (!(check_piece.y >= 0 && check_piece.y <= 7))
    {
        return -3;
    }
    return 0;
}

int placeChecker(vector<piece> all_pieces)
{
    for (int i = 0; i < all_pieces.size()-1; i++)
    {
        for (int j = i + 1; j < all_pieces.size(); j++)
        {
            if ((all_pieces[i].x == all_pieces[j].x) && (all_pieces[i].y == all_pieces[j].y))
            {
                return -1;
            }
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //cout << "Hello World!" << endl;
    ifstream in;
    in.open("../input.txt");
    string line;
    int x, y;
    vector<piece> all_pieces;
    if (in.is_open())
    {
        while (in >> line >> x >> y)
        {
            struct piece* new_piece = new piece();
            new_piece->name = line;
            new_piece->x = x;
            new_piece->y = y;
            all_pieces.push_back(*new_piece);
        }
    }
    for (auto& x: all_pieces)
    {
        //inputChecker(x);
        cout << "Фигура: " << x.name << " Х = " << x.x << " Y = " << x.y << endl;
    }
    in.close();
    if (all_pieces.size() < 1)
    {
        cout << "Too little input" << endl;
        return 0;
    }
    if (all_pieces.size() > 10)
    {
        cout << "Too much input" << endl;
        return 0;
    }
    for (int i = 0; i < all_pieces.size(); i++)
    {
        int checker = inputChecker(all_pieces[i]);
        if (checker == -1)
        {
            cout << "Incorrect piece name input for piece number " << i << endl;
            return 0;
        }
        else if (checker == -2)
        {
            cout << "Incorrect X coordinate for piece number " << i << endl;
            return 0;
        }
        else if (checker == -3)
        {
            cout << "Incorrect Y coordinate for piece number " << i << endl;
            return 0;
        }
    }
    int placeChecking = placeChecker(all_pieces);
    if (placeChecking == -1)
    {
        cout << "At least 2 pieces have same place" << endl;
        return 0;
    }
    return 0;
}
