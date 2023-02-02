#include "Serializer.hpp"

int main()
{
	Data *obj = new Data;
	obj->num = 132;
	obj->name = "Jad";

	uintptr_t serialRep = Serializer::serialize(obj);

	std::cout << "The serial representation of obj* is: " << serialRep << std::endl;

	std::cout << "num: " << obj->num << std::endl;
	std::cout << "name: " << obj->name << std::endl;

	std::cout << "We create a new Data pointer and we deserialize from the previous object serial representation: " << std::endl;
	Data *objCopy = Serializer::deserialize(serialRep);
	std::cout << "The serial representation of objCopy* is: " << Serializer::serialize(objCopy) << std::endl;

	std::cout << "num: " << objCopy->num << std::endl;
	std::cout << "name: " << objCopy->name << std::endl;
	
	delete obj;
}
