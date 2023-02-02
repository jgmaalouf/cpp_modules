#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <numeric>

class Span
{
private:
	unsigned int N_;
	std::vector<int> spanVec_;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& cpySpan);
	~Span();

	Span& operator=(const Span& cpySpan);

	void	addNumber(int input);
	void	addNumbers(const std::vector<int>::iterator& start, const std::vector<int>::iterator& end);
	int		shortestSpan() const;
	int		longestSpan() const;

	class SpanFull : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NoSpanFound : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif