#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl hobj;

	if (argc != 2)
		return (std::cout << "Wrong input\n", 0);
	hobj.complain("DEBUG", argv[1]);
	hobj.complain("INFO", argv[1]);
	hobj.complain("SOMETHING", argv[1]);
	hobj.complain("WARNING", argv[1]);
	hobj.complain("ERROR", argv[1]);
	hobj.complain("SOMETHING_ELSE", argv[1]);
}
