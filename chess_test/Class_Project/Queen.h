#pragma once
#include "Piece.h"


class Queen : public Piece
{
private:
	string piece_name;
	int x;
	int y;
public:
	Queen(string new_name, int new_x, int new_y);

	void insideGotoXY(short y, short x) const override;
	void piece_Drawer() const override;
	void check_Capture(vector<vector<int>> all_pieces_place) const override;
	int check_Temp(int x, int y, vector<vector<int>> all_pieces_place, bool* any_one) const override;
};