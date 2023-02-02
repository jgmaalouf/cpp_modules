#include "Span.hpp"

Span::Span() : N_(0)
{
}

Span::Span(unsigned int N) : N_(N)
{
}

Span::Span(const Span& cpySpan)
	: N_(cpySpan.N_)
	, spanVec_(cpySpan.spanVec_)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& cpySpan)
{
	N_ = cpySpan.N_;
	spanVec_ = cpySpan.spanVec_;
	return *this;
}

void Span::addNumber(int input)
{
	if (spanVec_.size() < N_)
		spanVec_.push_back(input);
	else
		throw Span::SpanFull();
}
void Span::addNumbers(const std::vector<int>::iterator& start, const std::vector<int>::iterator& end)
{
	if (std::distance(start, end) + spanVec_.size() < N_)
		spanVec_.insert(spanVec_.end(), start, end);
	else
		throw std::runtime_error("Doesn't fit");
}

int Span::shortestSpan() const
{
	if (spanVec_.size() < 2)
		throw Span::NoSpanFound();

	std::vector<int> tmp;
	std::adjacent_difference(spanVec_.begin(), spanVec_.end(), std::back_inserter(tmp));
	int (*toAbs)(int) = &std::abs;
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), toAbs);

	return *std::min_element(tmp.begin(), tmp.end());
}

int Span::longestSpan() const
{
	if (spanVec_.size() < 2)
		throw Span::NoSpanFound();

	int max = *std::max_element(spanVec_.begin(), spanVec_.end());
	int min = *std::min_element(spanVec_.begin(), spanVec_.end());

	return max - min;
}

const char* Span::SpanFull::what() const throw()
{
	return "Span is full!";
}

const char* Span::NoSpanFound::what() const throw()
{
	return "No span is found!";
}
