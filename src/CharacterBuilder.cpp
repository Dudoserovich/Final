#include "CharacterBuilder.h"

// определение методов класса HumanClothes
string HumanClothes::toStringName() {
    switch (clothes) {
        case CLOTHES::COSTUME:
            return "COSTUME";
        case CLOTHES::HOODIE_WITH_JEANS:
            return "HOODIE_WITH_JEANS";
        case CLOTHES::SHIRT_WITH_PANTS:
            return "SHIRT_WITH_PANTS";
    }

    throw logic_error("err");
}

CLOTHES_PROPERTIES HumanClothes::Properties() {
    switch (clothes) {
        case CLOTHES::COSTUME:
            return LUCK;
        case CLOTHES::HOODIE_WITH_JEANS:
            return COOL;
        case CLOTHES::SHIRT_WITH_PANTS:
            return RESPECT;
    }

    throw logic_error("err");
}

// определение методов класса HumanPersonalityType
string HumanPersonalityType::toString() {
    switch (personalityType) {
        case PERSONALITY_TYPE::AGGRESSIVE:
            return "AGGRESSIVE";
        case PERSONALITY_TYPE::NEUTRAL:
            return "NEUTRAL";
        case PERSONALITY_TYPE::POSITIVE:
            return "POSITIVE";
    }

    throw logic_error("err");
}

// определение методов класса HumanMarks
string HumanMarks::toString() {
    switch (marks) {
        case MARKS::FIVE:
            return "FIVE";
        case MARKS::FOUR:
            return "FOUR";
        case MARKS::THREE:
            return "THREE";
        case MARKS::TWO:
            return "TWO";
    }

    throw logic_error("err");
}

// определение методов класса Character
string Character::toString() {
    string s = "Name: " + name + '\n';
    s += "Clothes: ";

    switch (clothes_arr.clothes) {
        case CLOTHES::COSTUME:
            s += "COSTUME";
            break;
        case CLOTHES::HOODIE_WITH_JEANS:
            s += "HOODIE_WITH_JEANS";
            break;
        case CLOTHES::SHIRT_WITH_PANTS:
            s += "SHIRT_WITH_PANTS";
            break;
    }

    s += ", ";

    switch (clothes_arr.clothes) {
        case CLOTHES::COSTUME:
            s += "LUCK";
            break;
        case CLOTHES::HOODIE_WITH_JEANS:
            s += "COOL";
            break;
        case CLOTHES::SHIRT_WITH_PANTS:
            s += "RESPECT";
            break;
    }

    s += ";\nPersonality type: ";

    switch (personalityType) {
        case PERSONALITY_TYPE::AGGRESSIVE:
            s += "AGGRESSIVE";
            break;
        case PERSONALITY_TYPE::NEUTRAL:
            s += "NEUTRAL";
            break;
        case PERSONALITY_TYPE::POSITIVE:
            s += "POSITIVE";
            break;
    }

    if (marks.size() != 0) {
        s += ";\nMarks: ";
        for (auto &mark : marks) {
            s += mark->toString() + ", ";
        }
    } else s += ";";


    return s;
}

string Character::getName() {
    return this->name;
}

// определение методов CharacterBuilder
void CharacterBuilder::addMarks(MARKS mark) {
    marks.push_back(mark);
}

void CharacterBuilder::setPersonalityType(PERSONALITY_TYPE personalityType) {
    this->personalityType = personalityType;
}

void CharacterBuilder::setClothes(CLOTHES clothes, CLOTHES_PROPERTIES clothesProperties) {
    this->cl.clothes = clothes;
    this->cl.clothesProperties = clothesProperties;
}

void CharacterBuilder::setName(string name) {
    this->name = name;
}

// определение методов Student
string Student::getMarks() {
    string s = "";
    for (int i = 0; i < marks.size(); i++) {
        switch (marks[i]) {
            case MARKS::FIVE:
                s += "5,";
                break;
            case MARKS::FOUR:
                s += "4,";
                break;
            case MARKS::THREE:
                s += "3,";
                break;
            case MARKS::TWO:
                s += "2,";
                break;
        }
    }
    return s;
}

CLOTHES_PROPERTIES Student::getProp() {
    return prop;
}
