#include "Array.hpp"

int main ()
{
	std::cout << "Creating an array of 3 strings" << std::endl;
	Array<std::string> strArr(3);
	std::cout << "Filling it up with values" << std::endl;
	strArr[0] = "test";
	strArr[1] = "test2";
	strArr[2] = "test3";

	std::cout << "Displaying size and the 3 strings" << std::endl;
	std::cout << "Size: " << strArr.size() << std::endl;
	for (size_t i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << std::endl;

	std::cout << "int* a = new int(); and displaying a" << std::endl;
	int* a = new int();
	std::cout << *a << std::endl;
	std::cout << "Comparing with our Array" << std::endl;
	Array<int> intArr;
	std::cout << intArr[0] << std::endl;

	std::cout << "Creating an array of 4 doubles" << std::endl;
	Array<double> doubleArr(4);
	std::cout << "Filling it up with values" << std::endl;
	doubleArr[0] = 1.0;
	doubleArr[1] = 2.0;
	doubleArr[2] = 4.0;
	doubleArr[3] = 8.0;
	std::cout << "Displaying size and the array's doubles" << std::endl;
	std::cout << "Size: " << doubleArr.size() << std::endl;
	for (size_t i = 0; i < doubleArr.size(); i++)
		std::cout << doubleArr[i] << std::endl;
	
	std::cout << "Trying to access the 5th element" << std::endl;
	try
	{
		std::cout << doubleArr[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Creating a new double array and taking it's values from the previous array" << std::endl;
	Array<double> doubleArr2(doubleArr);
	std::cout << "Displaying size and the array's doubles" << std::endl;
	std::cout << "Size: " << doubleArr2.size() << std::endl;
	for (size_t i = 0; i < doubleArr2.size(); i++)
		std::cout << doubleArr2[i] << std::endl;

	std::cout << "Creating a new double array and displaying it's size and values it contains" << std::endl;
	Array<double> doubleArr3(2);
	std::cout << "Size: " << doubleArr3.size() << std::endl;
	for (size_t i = 0; i < doubleArr3.size(); i++)
		std::cout << doubleArr3[i] << std::endl;
	std::cout << "Setting it to the previous array's values using copy assignement operator" << std::endl;
	doubleArr3 = doubleArr2;
	std::cout << "Displaying it's size and values it contains now" << std::endl;
	std::cout << "Size: "<< doubleArr3.size() << std::endl;
	for (size_t i = 0; i < doubleArr3.size(); i++)
		std::cout << doubleArr3[i] << std::endl;

	system("leaks ex02");
}