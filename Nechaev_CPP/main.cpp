#include <iostream>
#include <Windows.h>
#include <vector>

class Bird
{
public:
	virtual ~Bird(){}
	virtual std::string MakeSound() const = 0;
};
class Pigeon : public Bird
{
public:
	std::string MakeSound() const override
	{
		return "Уруру";
	}
};
class Seagull : public Bird
{
	std::string MakeSound() const override
	{
		return "А-а-а";
	}
};
class Sparrow : public Bird
{
	std::string MakeSound() const override
	{
		return "Чик-чирик";
	}
};

int main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<std::unique_ptr<Brid>> birdsArray;
	birdsArray.push_back(std::make_unique<Sparrow>());
	birdsArray.push_back(std::make_unique<Seagull>());
	birdsArray.push_back(std::make_unique<Pigeon>());

	for (auto& bird : birdsArray)
	{
		std::cout << bird.MakeSound();
	}

	return 0;
}