#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(std::string name, char color) {
    this->name = name;
    this->color = color;
}

Movement HumanPlayer::decide() {
    // wait for player to decide
}