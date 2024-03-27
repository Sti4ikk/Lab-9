#include <iostream>
#include "structs.h"
#include <fstream>
#include <array>
#include <vector>
#include <Windows.h>

void readInfo(Human* arr);
void print(Human* arr);
int isZnakExistent(Human* people, std::array<Znaki, 12> znaki);
void isZnakCorrect(Human* people, std::array<Znaki, 12> znaki, std::vector<int>& indexes);
void printInfoAboutZnakOfHuman(Human* people, std::vector<int>& indexes);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Human* people = new Human[10];
	std::array<Znaki, 12> znaki{
		{"Овен", {21, 3}, {20, 4},
		{"Телец", {21, 4}, {20, 5}},
		{"Близнецы", {21, 3}, {20, 4}},
		{"Рак", {21, 4}, {20, 5}},
		{"Лев", {21, 3}, {20, 4}},
		{"Дева", {21, 4}, {20, 5}},
		{"Весы", {21, 3}, {20, 4}},
		{"Скорпион", {21, 4}, {20, 5}},
		{"Стрелец", {21, 3}, {20, 4}},
		{"Козерог", {21, 4}, {20, 5}},
		{"Водолей", {21, 3}, {20, 4}},
		{"Рыбы", {21, 4}, {20, 5}}}
	};
	std::vector<int> indexes;
	indexes.reserve(10);

	/*for (int i = 0; i < 12; i++)
	{
		std::cout << znaki[i].znak;
		std::cout << znaki[i].dateOfStart[0];
		std::cout << znaki[i].dateOfStart[1];
		std::cout << znaki[i].dateOfEnd[0];
		std::cout << znaki[i].dateOfEnd[1] << std::endl;
	}      */


	readInfo(people);
	isZnakCorrect(people,znaki, indexes);
	printInfoAboutZnakOfHuman(people, indexes);


	delete[] people;
	return 0;
}

void readInfo(Human* people)
{
	Human znak;
	std::ifstream file("D:/Files/Znaki.dat", std::ios_base::binary);
	for (int i = 0; i < 10 and file.read(reinterpret_cast<char*>(&people[i]), sizeof(Human)); ++i) {}

	file.close();
}

void print(Human* people)
{
	for (int i = 0; i < 2; i++)
	{
		std::cout << "\tЧеловек " << i + 1 << ": \n";
		std::cout << "Фамилия:        " << people[i].surName << std::endl;
		std::cout << "Имя:            "<< people[i].name << std::endl;
		std::cout << "Знак зодиака:   "<< people[i].znakZodiaka << std::endl;
		std::cout << "Дата рождения:  " << people[i].dateOfDirthday[0] << ".";
		std::cout << people[i].dateOfDirthday[1] << ".";
		std::cout << people[i].dateOfDirthday[2] << std::endl << std::endl;
	}
}

// проверка, существует ли знак зодиака
int isZnakExistent(Human* people, std::array<Znaki, 12> znaki)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (people[i].znakZodiaka == znaki[j].znak)
				return 1;
		}

		return 0;
	}
}

void isZnakCorrect(Human* people, std::array<Znaki, 12> znaki, std::vector<int>& indexes)
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if ((people[i].dateOfDirthday[1] == znaki[j].dateOfStart[1]   // проверка на совпадание месяца начала
				 and (people[i].dateOfDirthday[0] >= znaki[j].dateOfStart[1] and people[i].dateOfDirthday[0] <= 30) // проверка на день

				 or people[i].dateOfDirthday[1] == znaki[j].dateOfEnd[1]) // проверка на совпадание месяца конца
				 and (people[i].dateOfDirthday[0] <= znaki[j].dateOfEnd[1] and people[i].dateOfDirthday[0] >= 1))   // проверка на день
			{
				indexes[count++] = i;
			}
		}
	}
}

void printInfoAboutZnakOfHuman(Human* people, std::vector<int>& indexes)
{
	std::cout << "Список людей, чей знак зодиака не соотвутсвует дате: \n";
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < indexes.size(); j++)
		{
			if (i != indexes[j])
			{
				std::cout << people[i].surName << std::endl;
			}
		}
	}
}