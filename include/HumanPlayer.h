#include "Player.h"

#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

class HumanPlayer: public Player{

    public:
        HumanPlayer(std::string, char color);
        Movement decide() override;

};



#endif