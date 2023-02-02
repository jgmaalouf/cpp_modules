#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t serializedObj = reinterpret_cast<uintptr_t>(ptr);
	return serializedObj;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* deserializedObj = reinterpret_cast<Data *>(raw);
	return deserializedObj;
}