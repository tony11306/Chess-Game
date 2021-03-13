
#ifndef PIECE_H
#define PEICE_H

// abstract class
class Piece{
    protected:
        char color;
        char pieceId;
        bool isAlive;
        bool hasMoved;
        Piece();

    public:
        char getColor();
        char getPieceID();
        bool checkAlive();
        bool checkMoved();
        
        void setAlive(bool);
        void setMoved(bool);

        bool virtual isMoveValid(int, int, int, int) = 0;
};


#endif // PIECE_H