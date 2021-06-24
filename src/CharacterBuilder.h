#pragma once

#include <iostream>
#include <vector>

using namespace std;

// чтобы ещё сильнее не усложнять код,
// играем мы за мужского персонажа, но надо прописать, чтобы было гибко

// наименования шмоток
enum CLOTHES {
    COSTUME,
    HOODIE_WITH_JEANS,
    SHIRT_WITH_PANTS,
};

enum CLOTHES_PROPERTIES {
    LUCK,
    COOL,
    RESPECT,
};

// типаж
enum PERSONALITY_TYPE {
    AGGRESSIVE,
    NEUTRAL,
    POSITIVE,
};

// оценки студента
enum MARKS {
    FIVE,
    FOUR,
    THREE,
    TWO,
};

// одежда персонажа
class HumanClothes {
    CLOTHES clothes;
public:
    HumanClothes(CLOTHES clothes) : clothes(clothes) {
    }

    string toStringName();

    CLOTHES_PROPERTIES Properties();
};

// типаж персонажа
class HumanPersonalityType {
    PERSONALITY_TYPE personalityType;
public:
    HumanPersonalityType(PERSONALITY_TYPE personalityType) : personalityType(personalityType) {
    }

    string toString();
};

// оценки персонажа
class HumanMarks {
    MARKS marks;
public:
    HumanMarks(MARKS marks) : marks(marks) {
    }

    string toString();
};

class Character {
    // одежда и её свойства
    struct Clothes {
        CLOTHES clothes;
        CLOTHES_PROPERTIES clothesProperties;
    };
    vector<HumanMarks *> marks;
    PERSONALITY_TYPE personalityType;

    Clothes clothes_arr;
    string name;

    // классы, являющиеся людьми
    friend class Student;

    friend class Teacher;

public:
    Character(string name) : name(name) {};

    string toString();

    string getName();

};

// абстрактный класс
class CharacterBuilder {
protected:
    vector<MARKS> marks;
    PERSONALITY_TYPE personalityType;
    struct Clothes {
        CLOTHES clothes;
        CLOTHES_PROPERTIES clothesProperties;
    };
    Clothes cl;
    string name;
public:
    void addMarks(MARKS mark);

    void setPersonalityType(PERSONALITY_TYPE personalityType);

    void setClothes(CLOTHES clothes, CLOTHES_PROPERTIES clothesProperties);

    void setName(string name);

    virtual Character *build() = 0;
};

class Student : public CharacterBuilder {
    CLOTHES_PROPERTIES prop;
public:
    virtual Character *build() {
        Character *character = new Character(name);
        // добавляем оценки
        for (auto &m : marks) {
            character->marks.push_back(new HumanMarks(m));
        }
        character->personalityType = personalityType;
        character->clothes_arr.clothes = cl.clothes;
        character->clothes_arr.clothesProperties = prop = cl.clothesProperties;
        return character;
    }

    string getMarks();

    CLOTHES_PROPERTIES getProp();
};

class Teacher : public CharacterBuilder {
public:
    virtual Character *build() {
        Character *character = new Character(name);
        character->personalityType = personalityType;
        character->clothes_arr.clothes = CLOTHES::COSTUME;
        character->clothes_arr.clothesProperties = CLOTHES_PROPERTIES::RESPECT;
        return character;
    }
};