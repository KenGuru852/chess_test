#pragma once

#include <iostream>
#include <vector>

using namespace std;

const string pieces_name[5] = { "king", "queen", "rook", "bishop", "knight" };

class Piece
{
private:
	virtual int check_Temp(int x, int y, vector<vector<int>> all_pieces_place, bool* any_one) const = 0;
public:
	virtual void piece_Drawer() const = 0;
	virtual void check_Capture(vector<vector<int>> all_pieces_place) const = 0;
	virtual void insideGotoXY(short y, short x) const = 0;
};
