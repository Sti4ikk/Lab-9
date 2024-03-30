#include <iostream>
#include <fstream>
#include "structs.h"

void readInfo(Znak* znak);
void printInfo(Znak* znak);

int main()
{
	setlocale(0, "ru");

	Znak** znak = new Znak* [10];
	for (int i = 0; i < 10; i++)
		znak[i] = new Znak;
	
	readInfo(*znak);
	printInfo(*znak);




	for (int i = 0; i < 10; i++)
		delete znak[i];
	delete[] znak;

	return 0;
}

void readInfo(Znak* znak)
{
	std::ifstream file("D:/Files/Znaki.dat", std::ios_base::binary);
	for (int i = 0; i < 10 && file.read(reinterpret_cast<char*>(&znak[i]), sizeof(Znak)); ++i) {}
	file.close();
}

void printInfo(Znak* znak)
{
	for (int i = 0; i < 5; ++i) 
	{
	std::cout << "Человек " << i + 1 << ":\n";
	std::cout << "Фамилия: " << znak[i].surName << std::endl;
	std::cout << "Имя: " << znak[i].name << std::endl;
	std::cout << "Знак зодиака: " << znak[i].znakZodiaka << std::endl;
	std::cout << "Дата рождения: " << znak[i].dateOfDirthday[0] << ".";
	std::cout << znak[i].dateOfDirthday[1] << ".";
	std::cout << znak[i].dateOfDirthday[2] << std::endl << std::endl;
	}
}