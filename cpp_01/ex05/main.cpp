#include "Harl.hpp"

int main()
{
	Harl hobj;

	hobj.complain("DEBUG");
	hobj.complain("INFO");
	hobj.complain("SOMETHING");
	hobj.complain("WARNING");
	hobj.complain("ERROR");
	hobj.complain("SOMETHING_ELSE");
}
