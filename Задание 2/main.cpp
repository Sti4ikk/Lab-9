#include <iostream>
#include "structs.h"
#include <fstream>
#include <Windows.h>

void enterInfo();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	enterInfo();

	return 0;
}

void enterInfo()
{
	int size;
	std::cout << "Сколько человек вы хотите ввести: ";
	std::cin >> size;
	Znak* person = new Znak;
	  
	std::ofstream file("D:/Files/Znaki.dat", std::ios_base::binary);

	for(int i = 0; i < size; i++)
	{

		char newStr = '\n';

		std::cout << "Введите фамилию: ";
		std::cin >> person->surName;
		std::cout << "Введите имя: ";
		std::cin >> person->name;
		std::cout << "Введите Знак Зодиака: ";
		std::cin >> person->znakZodiaka;
		std::cout << "Введите дату рождения(через пробелы): ";
		std::cin >> person->dateOfDirthday[0]>>person->dateOfDirthday[1]>>person->dateOfDirthday[2];

		file.write((char*)&(*person), sizeof(Znak));
	}

	std::cout << "Данные записаны успешно!";

	delete person;
	file.close();
}