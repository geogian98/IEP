#include "Point.hpp"

#ifndef FIGURE_HPP
#define FIGURE_HPP


class Figure{
	float virtual perimeter() = 0;
	Point virtual getVertice(int i) = 0;
};

#endif
