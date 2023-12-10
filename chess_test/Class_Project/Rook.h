#pragma once
#include "Piece.h"


class Rook : public Piece
{
private:
	string piece_name;
	int x;
	int y;
public:
	Rook(string new_name, int new_x, int new_y);

	void insideGotoXY(short y, short x) const override;
	void piece_Drawer() const override;
	void check_Capture(vector<Piece> all_pieces) const override;
};