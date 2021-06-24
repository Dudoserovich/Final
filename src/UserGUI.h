#pragma once

#include "CharacterBuilder.h"
#include "Game.h"

class UserGUI {
    string welcome = "Добро пожаловать в игру \"Выжить на сессии\"";
    string arUReady = "Вы готовы создать персонажа?";
    string err = "Введено неверное число!";

    string teacher_name[3] = {"Евгений Ефремов", "Скурихин", "Светлана Николаевна"};

    Character *getCharacter(CharacterBuilder &builder, string name, CLOTHES clothes = COSTUME,
                            PERSONALITY_TYPE pers_type = NEUTRAL);

    // создание персонажа
    Character *createCharacter(Student &builder);

public:
    void start();
};
