#include "UserGUI.h"

Character *UserGUI::getCharacter(CharacterBuilder &builder, string name, CLOTHES clothes,
                                 PERSONALITY_TYPE pers_type) {
    builder.setName(name);
    builder.setPersonalityType(pers_type);
    HumanClothes hs(clothes);
    builder.setClothes(clothes, hs.Properties());

    Character *character = builder.build();

    return character;
}

Character *UserGUI::createCharacter(Student &builder) {
    int ready;

    cout << arUReady << endl;
    cout << "Введите число 1, чтобы выбрать персонажа:" << endl;
    cin >> ready;

    while (ready != 1) {
        cout << err << endl;
        cout << arUReady << endl;
        cout << "Введите число 1, чтобы выбрать персонажа:" << endl;
        cin >> ready;
    }

    cout << "Хорошо, теперь давайте создадим вашего персонажа." << endl;
    cout << "Введите имя персонажа: " << endl;
    string name;
    cin >> name;

    cout << "Выберите одежду персонажа(1-3):" << endl;
    int check = 0;
    while (check != 1 and check != 2 and check != 3) {
        cout << err << endl;
        cout << "Выберите одежду персонажа(1-3):" << endl;
        cout << "1. COSTUME (+ LUCK);\n" << "2. HOODIE_WITH_JEANS (+ "
             << "COOL);\n" << "3. SHIRT_WITH_PANTS (+ " << "RESPECT);" << endl;
        cin >> check;
    }
    CLOTHES clothes;
    switch (check) {
        case 1:
            clothes = CLOTHES::COSTUME;
            break;
        case 2:
            clothes = CLOTHES::HOODIE_WITH_JEANS;
            break;
        case 3:
            clothes = CLOTHES::SHIRT_WITH_PANTS;
            break;
    }

    cout << "Выберите типаж персонажа(1-3):" << endl;
    check = 0;
    while (check != 1 and check != 2 and check != 3) {
        cout << err << endl;
        cout << "Выберите типаж персонажа(1-3):" << endl;
        cout << "1. AGGRESSIVE;\n" << "2. NEUTRAL;\n" << "3. POSITIVE;" << endl;
        cin >> check;
    }
    PERSONALITY_TYPE personalityType;
    switch (check) {
        case 1:
            personalityType = PERSONALITY_TYPE::AGGRESSIVE;
            break;
        case 2:
            personalityType = PERSONALITY_TYPE::NEUTRAL;
            break;
        case 3:
            personalityType = PERSONALITY_TYPE::POSITIVE;
            break;
    }
    Character *character = getCharacter(builder, name, clothes, personalityType);
    return character;
}

void UserGUI::start() {
    cout << welcome << endl;
    Student builder;
    // создаём персонажа
    Character *character = createCharacter(builder);
    cout << "It's your's character: \n" << character->toString() << endl;

    cout << "Вам предстоит сыграть с каждым преподавателем в игру \"21\"" << endl;
    cout << "Правила игры довольно просты, вам просто нужно набрать "
            "максимальное количество очков, не превышающих число 21;" << endl;
    cout << "карты 2-10 соответствуют 2-10 соответственно, В-11, Д-12, К-13, Т-14" << endl;
    cout << "Но самое важное - это то, что перед каждой игрой вы ставите на кон свою оценку по выбору" << endl;
    cout << "Удачи!" << endl;

    int mark = 0;
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        // создаём преподавателей
        Teacher builder2;
        PERSONALITY_TYPE pers_type = PERSONALITY_TYPE(rand() % 3);
        HumanPersonalityType ht(pers_type);
        Character *characterTeacher = getCharacter(builder2, teacher_name[i], COSTUME,
                                                   pers_type);
        cout << "Сейчас у вас экзамен принимает " + characterTeacher->getName() << " с типом личности: "<< ht.toString() << endl;
        cout << "Сейчас у вас экзамен принимает " + characterTeacher->getName() << " с типом личности: "<< ht.toString() << endl;
        cout << "Делайте ваши ставки: 3, 4, 5. И помните, что характеристики "
                "вашей одежды могут помочь вам, так же как и тип личности" << endl;
        cin >> mark;
        while (mark != 3 and mark != 4 and mark != 5) {
            cout << err << endl;
            cout << "Делайте ваши ставки: 3, 4, 5. И помните, что характеристики "
                    "вашей одежды могут помочь вам, так же как и тип личности" << endl;
            cin >> mark;
        }
        // игра с добавлением оценки
        Game g;
        g.play(builder, characterTeacher->getName(), mark);

    }
    cout << "=========\nВаши итоговые оценки: " << builder.getMarks() << endl;
    cout << "Спасибо за игру!" << endl;

}
