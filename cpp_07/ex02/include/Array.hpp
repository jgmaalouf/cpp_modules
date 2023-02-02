#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T*				elements_;
	unsigned int	length_;
public:
	Array();
	Array(unsigned int n);
	Array(Array& source);
	~Array();

	Array& operator=(Array& rhs);
	T& operator[](unsigned int n);

	unsigned int size() const;
};

template <typename T>
Array<T>::Array() : length_(0)
{
	elements_ = new T[length_];
}

template <typename T>
Array<T>::Array(unsigned int n) : length_(n)
{
	elements_ = new T[length_];
}

template <typename T>
Array<T>::Array(Array& source) : length_(source.length_)
{
	elements_ = new T[length_];
	for (size_t i = 0; i < length_; i++)
		elements_[i] = source.elements_[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] elements_;
}

template <typename T>
Array<T>& Array<T>::operator=(Array& rhs)
{
	delete [] elements_;
	elements_ = new T[rhs.length_];
	for (size_t i = 0; i < rhs.length_; i++)
		elements_[i] = rhs.elements_[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n > length_)
		throw std::runtime_error("Out of bounds!");
	return elements_[n];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return length_;
}

#endif
