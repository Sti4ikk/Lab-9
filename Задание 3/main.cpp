#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <array>
#include <fstream>
#include "structs.h"


bool isZnakExistent(const Human& person, std::array<Znaki, 12>& znaki);
bool isZnakCorrect(const Human& person, std::array<Znaki, 12>& znaki);
void readInfo(Human* people);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Human* people = new Human[10];
    // Пример данных:
    std::array<Znaki, 12> znaki{
        {"овен", {21, 3}, {20, 4},
        {"телец", {21, 4}, {20, 5}},
        {"близнецы", {21, 5}, {21, 6}},
        {"рак", {22, 6}, {22, 7}},
        {"лев", {23, 7}, {22, 8}},
        {"дева", {21, 4}, {20, 5}},
        {"весы", {23, 9}, {22, 10}},
        {"скорпион", {23, 10}, {21, 11}},
        {"стрелец", {22, 11}, {21, 12}},
        {"козерог", {22, 12}, {19, 1}},
        {"водолей", {20, 1}, {18, 2}},
        {"рыбы", {19, 2}, {20, 3}}}
    };
    readInfo(people);

    // Вывод информации о людях, чей знак зодиака не соответствует дате рождения
    for (int i = 0; i < 3; ++i) {
        if (isZnakExistent(people[i], znaki) && !isZnakCorrect(people[i], znaki)) 
        {
            std::cout << "Человек " << i + 1 << ":\n";
            std::cout << "Фамилия: " << people[i].surName << std::endl;
            std::cout << "Имя: " << people[i].name << std::endl;
            std::cout << "Знак зодиака: " << people[i].znakZodiaka << std::endl;
            std::cout << "Дата рождения: " << people[i].dateOfDirthday[0] << ".";
            std::cout << people[i].dateOfDirthday[1] << ".";
            std::cout << people[i].dateOfDirthday[2] << std::endl << std::endl;
        }
    }

    delete[] people;

    return 0;
}

// Проверка, существует ли знак зодиака
bool isZnakExistent(const Human& person, std::array<Znaki, 12>& znaki) {
    for (const auto& znak : znaki) {
        if (person.znakZodiaka == znak.znak) {
            return true;
        }
    }
    return false;
}

// Проверка, соответствует ли знак зодиака дате рождения
bool isZnakCorrect(const Human& person, std::array<Znaki, 12>& znaki)
{
    std::string currentZnak;
    for (const auto& znak : znaki) {
        if ((person.dateOfDirthday[1] == znak.dateOfStart[1] &&
            person.dateOfDirthday[0] >= znak.dateOfStart[0] &&
            person.dateOfDirthday[0] <= 30) or
            ((person.dateOfDirthday[1] == znak.dateOfEnd[1]) &&
                (person.dateOfDirthday[0] <= znak.dateOfEnd[0] &&
                    person.dateOfDirthday[0] >= 1)))
        {
            currentZnak = znak.znak;
            if (currentZnak == person.znakZodiaka)
                return true;

        }
    }
    return false;
}



void readInfo(Human* people)
{
    std::ifstream file("D:/Files/Znaki.dat", std::ios_base::binary);
    for (int i = 0; i < 5 && file.read(reinterpret_cast<char*>(&people[i]), sizeof(Human)); ++i) {}
    file.close();
}
