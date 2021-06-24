#include "Game.h"

string Game::getCard(int num) {
    switch (num) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            return std::to_string(num);
            break;
        case 11:
            return "B";
            break;
        case 12:
            return "Д";
            break;
        case 13:
            return "К";
            break;
        case 14:
            return "Т";
            break;
    }
}

void Game::play(Student &builder, string teacher, int mark) {
    srand(time(nullptr));
    player_count = 0;
    teacher_count = 0;
    int num;
    bool check = false;
    bool check_player = false;
    int number;
    int number1;
    while (player_count <= 21 and teacher_count <= 21 and !check_player) {
        cout << "1 - добавить, 2 - остановиться:" << endl;
        cin >> num;
        if (num == 1) { // добавление карты
            number = rand() % 13 + 2;
            player_count += number;
            cout << getCard(number) << endl;
            cout << "Ваша общая сумма: " << player_count << endl;
            number1 = rand() % 13 + 2;
            if (teacher_count >= player_count) {
                cout << teacher << " спасовал!" << endl;
                check = true;
            } else if (!check)
                teacher_count += number1;
            cout << getCard(number1) << endl;
            cout << "Cумма " << teacher << ": " << teacher_count << endl;

        } else if (teacher_count < 21) { // игрок спасовал
            check_player = true;
            while (teacher_count < 21 and !check) {
                int random = rand() % 13 + 2;
                if (teacher_count >= player_count) {
                    cout << teacher << " спасовал!" << endl;
                    check = true;
                } else
                    teacher_count += random;
                cout << getCard(random) << endl;
                cout << "Cумма " << teacher << ": " << teacher_count << endl;
            }
        }
        // с шансом в 50% выпадает рандомное событие при условие, что игрок спасовал
        if (check_player and rand() % 2 == 0) {
            switch (builder.getProp()) {
                // сыграла удача и ваша карта поменялась на карту соперника
                case CLOTHES_PROPERTIES::LUCK:
                    if (player_count != 0 and teacher_count != 0) {
                        cout << "БОНУС/ДЕБАФ: Сыграла удача и " << teacher << " вы обменялись последними картами"
                             << endl;
                        player_count -= number;
                        player_count += number1;
                        cout << "Ваша общая сумма: " << player_count << endl;
                        teacher_count += number;
                        teacher_count -= number1;
                        cout << "Cумма " << teacher << ": " << teacher_count << endl;
                    }
                    break;
                    // сыграло уважение и препод дал вам шанс переиграть
                case CLOTHES_PROPERTIES::RESPECT:
                    if ((player_count <= teacher_count) and (player_count != 0 and teacher_count != 0)) {
                        cout << "БОНУС: Сыграло уважение и " << teacher << " дал вам шанс переиграть" << endl;
                        player_count = 0;
                        teacher_count = 0;
                        check_player = false;
                    } else {
                        cout << "ДЕБАФ: Из уважения вы соглашаетесь на ничью" << endl;
                        player_count = 21;
                        teacher_count = 21;
                    }
                    break;
                    // сыграла крутость и вы были спасены от проигрыша тем, что спрятали последнюю карту
                case CLOTHES_PROPERTIES::COOL:
                    if (player_count > 21) {
                    } else {
                        cout << "ДЕБАФ: Из-за своей крутости вы рискуете и берёте ещё одну карту" << endl;
                        int number = rand() % 13 + 2;
                        player_count += number;
                        cout << getCard(number) << endl;
                        cout << "Ваша общая сумма: " << player_count << endl;
                    }
            }
        }
    }

    // выставление оценки
    if ((player_count <= 21 and teacher_count < player_count) or
        (player_count <= 21 and teacher_count > 21)) {// победа
        cout << "Вы выиграли!" << endl;
        switch (mark) {
            case 3:
                cout << "Четыре? Звучит неплохо!" << endl;
                builder.addMarks(FOUR);
                cout << "Ваши оценки: " << builder.getMarks() << endl;
                break;
            case 4:
            case 5:
                cout << "Поздравляю с пятёркой!" << endl;
                builder.addMarks(FIVE);
                cout << "Ваши оценки: " << builder.getMarks() << endl;
                break;
        }

    } else {// поражение
        cout << "Вы проиграли!" << endl;
        switch (mark) {
            case 3:
                cout << "Вы получили парашу!" << endl;
                builder.addMarks(TWO);
                cout << "Ваши оценки: " << builder.getMarks() << endl;
                break;
            case 4:
                cout << "Вы получили троечку!" << endl;
                builder.addMarks(THREE);
                cout << "Ваши оценки: " << builder.getMarks() << endl;
                break;
            case 5:
                cout << "Ну четвёрка тоже неплохо!" << endl;
                builder.addMarks(FOUR);
                cout << "Ваши оценки: " << builder.getMarks() << endl;
                break;
        }
    }
}

