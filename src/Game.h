#pragma once

#include "CharacterBuilder.h"

class Game {
    int player_count;
    int teacher_count;

    // карта по номеру
    string getCard(int num);

public:
    // сам процесс игры
    void play(Student &builder, string teacher, int mark);

};
