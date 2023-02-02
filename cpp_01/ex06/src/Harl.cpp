#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << "\n[ DEBUG ]\n"
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup "
				<< "burger. I really do!" << std::endl;
			
}

void Harl::info()
{
	std::cout << "\n[ INFO ]\n"
				<< "I cannot believe adding extra bacon costs more money."
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void Harl::warning()
{
	std::cout << "\n[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years whereas you started "
				<< "working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "\n[ ERROR ]\n"
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void Harl::complain(std::string level, std::string filterWord)
{
	std::string levels [4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	void (Harl::*complaints [4]) (void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int filter = -1;
	int lvl_index = -1;
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == filterWord)
			filter = i;
		if (levels[i] == level)
			lvl_index = i;
	}
	switch (filter)
	{
	case 0:
		if (lvl_index == 0)
			(this->*complaints[0]) ();
	case 1:
		if (lvl_index == 1)
			(this->*complaints[1]) ();
	case 2:
		if (lvl_index == 2)
			(this->*complaints[2]) ();
	case 3:
		if (lvl_index == 3)
			(this->*complaints[3]) ();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
