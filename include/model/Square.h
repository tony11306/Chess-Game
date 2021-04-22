#ifndef SQUARE_H
#define SQUARE_H

class Piece;

class Square {

    private:

        int row;
        int col;
        Piece* piece = nullptr;

    public:
        int getRow();
        int getCol();
        void setRow(int);
        void setCol(int);
        void setPiece(Piece*);
        void deletePiece();
        Piece* getPiece();
        Square();
        ~Square();

};
#endif


