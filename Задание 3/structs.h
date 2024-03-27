#pragma once
#include <string>

struct Human
{
	std::string surName;
	std::string name;
	std::string znakZodiaka;
	int dateOfDirthday[3];
};

struct Znaki
{
	std::string znak;
	int dateOfStart[2];
	int dateOfEnd[2];
};