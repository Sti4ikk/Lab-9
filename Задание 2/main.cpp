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
	std::cout << "������� ������� �� ������ ������: ";
	std::cin >> size;
	  
	std::ofstream file("D:/Files/Znaki.dat", std::ios_base::binary);

	for(int i = 0; i < size; i++)
	{
		Znak person;
		char newStr = '\n';

		std::cout << "������� �������: ";
		std::cin >> person.surName;
		std::cout << "������� ���: ";
		std::cin >> person.name;
		std::cout << "������� ���� �������: ";
		std::cin >> person.znakZodiaka;
		std::cout << "������� ���� ��������(����� �������): ";
		std::cin >> person.dateOfDirthday[0]>>person.dateOfDirthday[1]>>person.dateOfDirthday[2];

		file.write((char*)&person, sizeof(Znak));
	}

	file.close();
}