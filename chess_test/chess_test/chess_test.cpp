#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "King.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

using namespace std;

void gotoXY(short y, short x)
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void drawBoard()
{
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "|" << endl << endl;
    }
    gotoXY(0, 0);
    for (int i = 0; i < 11; i++)
    {
        cout << "-------------------------------------" << endl;
        cout << endl;
    }
    int drawSide = 7;
    int drawTop = 0;
    for (int i = 1; i <= 19; i += 2)
    {
        for (int j = 2; j <= 38; j += 4) 
        {
            if (j == 38)
            {
                gotoXY(i, 36);
                cout << "|";
            }
            else
            {
                gotoXY(i, j);
                cout << "|";
            }
        }
        if (i == 1 || i == 19)
        {
            for (int q = 4; q <= 34; q += 4)
            {
                gotoXY(i, q);
                cout << drawTop;
                drawTop++;
            }
            drawTop = 0;
        }
        if (i > 1 && i < 19)
        {
            gotoXY(i, 1);
            cout << drawSide;
            gotoXY(i, 35);
            cout << drawSide;
            drawSide--;
        }
    }
    gotoXY(1, 1);
    cout << "X";
    gotoXY(19, 1);
    cout << "X";
    gotoXY(1, 35);
    cout << "X";
    gotoXY(19, 35);
    cout << "X";
    gotoXY(25, 0);
}

int inputChecker(string name_to_check, int x_to_check, int y_to_check, vector<Piece*> *all_pieces, vector<vector<int>>& pieces_place)
{
    const string pieces_name[5] = { "king", "queen", "rook", "bishop", "knight" };
    bool is_name = false;
    int ind;
    for (int i = 0; i < 5; i++)
    {
        if (name_to_check == pieces_name[i])
        {
            is_name = true;
            ind = i;
            break;
        }
    }
    if (!is_name)
    {
        return -1;
    }
    if (!(x_to_check >= 0 && x_to_check <= 7))
    {
        return -2;
    }
    if (!(y_to_check >= 0 && y_to_check <= 7))
    {
        return -3;
    }
    if (!(pieces_place[x_to_check][y_to_check] == -1))
    {
        return -4;
    }
    else
    {
        pieces_place[x_to_check][y_to_check] = ind;
    }
    if (ind == 0)
    {
        all_pieces->push_back(new King(name_to_check, x_to_check, y_to_check));
    }
    else if (ind == 1)
    {
        all_pieces->push_back(new Queen(name_to_check, x_to_check, y_to_check));
    }
    else if (ind == 2)
    {
        all_pieces->push_back(new Rook(name_to_check, x_to_check, y_to_check));
    }
    else if (ind == 3)
    {
        all_pieces->push_back(new Bishop(name_to_check, x_to_check, y_to_check));
    }
    else if (ind == 4)
    {
        all_pieces->push_back(new Knight(name_to_check, x_to_check, y_to_check));
    }
    return 0;
}

int main()
{
    vector<vector<int>> pieces_place(8, vector<int>(8, -1));
    setlocale(LC_ALL, "Russian");
    ifstream in;
    in.open("../input.txt");
    vector<Piece*> all_pieces;
    string name;
    int x, y;
    int line_counter = 0;
    drawBoard();
    if (in.is_open())
    {
        while (in >> name >> x >> y)
        {
            line_counter++;
            int checker = inputChecker(name, x, y, &all_pieces, pieces_place);
            if (checker == -1)
            {
                cout << "Incorrect piece name input for piece number " << line_counter << endl;
                return 0;
            }
            else if (checker == -2)
            {
                cout << "Incorrect X coordinate for piece number " << line_counter << endl;
                return 0;
            }
            else if (checker == -3)
            {
                cout << "Incorrect Y coordinate for piece number " << line_counter << endl;
                return 0;
            }
            else if (checker == -4)
            {
                cout << "At least 2 pieces have same place" << endl;
                return 0;
            }
        }

    }
    in.close();
    for (auto& x : all_pieces)
    {
        x->piece_Drawer();
    }
    return 0;
}
