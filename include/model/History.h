#ifndef HISTORY_H
#define HISTORY_H

#include "Piece.h"
#include "MoveData.h"

class History {
    private:
        bool isEnPassant;
        bool isCastling;
        Piece* capturedPiece;
        Piece* movePiece;
        MoveData moveData;
    public:

        ~History() {
            delete capturedPiece;
            delete movePiece;
        }

        History(MoveData move):moveData(move) {
            isEnPassant = false;
            isCastling = false;
            capturedPiece = nullptr;
            movePiece = nullptr;
        }
        
        void setIsEnPassant(bool isEnPassant) {
            this->isEnPassant = isEnPassant;
        }

        void setIsCastling(bool isCastling) {
            this->isCastling = isCastling;
        }

        void setCapturedPiece(Piece* capturedPiece) {
            if(capturedPiece == nullptr) {
                this->capturedPiece = nullptr;
                return;
            }
            this->capturedPiece = capturedPiece->clone();
        }

        void setMovePiece(Piece* movePiece) {
            if(movePiece == nullptr) {
                this->movePiece = nullptr;
                return;
            }
            this->movePiece = movePiece;
        }

        bool checkIsEnPassant() {
            return isEnPassant;
        }

        bool checkIsCastling() {
            return isCastling;
        }

        Piece* getCapturedPiece() {
            return capturedPiece;
        }

        Piece* getMovePiece() {
            return movePiece;
        }

        MoveData getMoveData() {
            return moveData;
        }


        

};

#endif