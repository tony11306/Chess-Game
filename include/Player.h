#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player(char);
        void Move(int, int, int, int);
        char getColor();
    private:
        char color;

};



#endif