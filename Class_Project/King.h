#pragma once

#include "Piece.h"


class King : public Piece
{
private:
	string piece_name;
	int x;
	int y;
	int check_Temp(int x, int y, vector<vector<int>> all_pieces_place, bool* any_one) const override;
public:
	King(string new_name, int new_x, int new_y);

	void piece_Drawer() const override;
	void check_Capture(vector<vector<int>> all_pieces_place) const override;
	void insideGotoXY(short y, short x) const override;
};

