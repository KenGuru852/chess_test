#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Piece
{
public:
	virtual void piece_Drawer() const = 0;
	virtual void check_Capture(vector<Piece> all_pieces) const = 0;
	virtual void insideGotoXY(short y, short x) const = 0;
};
